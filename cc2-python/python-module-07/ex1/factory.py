from ex0 import Creature, CreatureFactory

from .creatures import Bloomelle, Morphagon, Shiftling, Sproutling


class HealingCreatureFactory(CreatureFactory):
    """Factory for Sproutling and its evolution Bloomelle."""

    def create_base(self) -> Creature:
        """Create a Sproutling."""
        return Sproutling()

    def create_evolved(self) -> Creature:
        """Create a Bloomelle."""
        return Bloomelle()


class TransformCreatureFactory(CreatureFactory):
    """Factory for Shiftling and its evolution Morphagon."""

    def create_base(self) -> Creature:
        """Create a Shiftling."""
        return Shiftling()

    def create_evolved(self) -> Creature:
        """Create a Morphagon."""
        return Morphagon()
