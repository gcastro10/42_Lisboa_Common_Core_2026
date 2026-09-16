from abc import ABC, abstractmethod

from ex0 import Creature
from ex1 import HealCapability, TransformCapability


class InvalidStrategyError(Exception):
    """Raised when a strategy is used with an unsuitable creature."""


class BattleStrategy(ABC):
    """Abstract strategy that sequences a creature's battle actions."""

    def __init__(self, label: str) -> None:
        """Store the adjective used in invalid-combination messages."""
        self.label: str = label

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        """Return True if this strategy suits the creature."""

    @abstractmethod
    def act(self, creature: Creature) -> list[str]:
        """Run the strategy, or raise if the creature is unsuitable."""

    def _require_valid(self, creature: Creature) -> None:
        """Raise if this strategy cannot be applied to the creature."""
        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' for this "
                f"{self.label} strategy"
            )


class NormalStrategy(BattleStrategy):
    """Strategy that only attacks; valid for every creature."""

    def __init__(self) -> None:
        """Create a normal attack-only strategy."""
        super().__init__("normal")

    def is_valid(self, creature: Creature) -> bool:
        """Accept any creature."""
        return True

    def act(self, creature: Creature) -> list[str]:
        """Return the creature's attack."""
        self._require_valid(creature)
        return [creature.attack()]


class AggressiveStrategy(BattleStrategy):
    """Strategy for transforming creatures: transform, attack, revert."""

    def __init__(self) -> None:
        """Create an aggressive transform-attack-revert strategy."""
        super().__init__("aggressive")

    def is_valid(self, creature: Creature) -> bool:
        """Accept creatures that expose transform capabilities."""
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> list[str]:
        """Transform, attack, then revert."""
        self._require_valid(creature)
        assert isinstance(creature, TransformCapability)
        return [
            creature.transform(),
            creature.attack(),
            creature.revert(),
        ]


class DefensiveStrategy(BattleStrategy):
    """Strategy for healing creatures: attack, then heal."""

    def __init__(self) -> None:
        """Create a defensive attack-then-heal strategy."""
        super().__init__("defensive")

    def is_valid(self, creature: Creature) -> bool:
        """Accept creatures that expose healing capabilities."""
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> list[str]:
        """Attack, then heal."""
        self._require_valid(creature)
        assert isinstance(creature, HealCapability)
        return [creature.attack(), creature.heal()]
