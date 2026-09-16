from abc import ABC, abstractmethod

from .creature import Aquabub, Creature, Flameling, Pyrodon, Torragon


class CreatureFactory(ABC):
    """Abstract factory for one creature family."""

    @abstractmethod
    def create_base(self) -> Creature:
        """Create the base creature of this family."""

    @abstractmethod
    def create_evolved(self) -> Creature:
        """Create the evolved creature of this family."""


class FlameFactory(CreatureFactory):
    """Factory for Flameling and its evolution Pyrodon."""

    def create_base(self) -> Creature:
        """Create a Flameling."""
        return Flameling()

    def create_evolved(self) -> Creature:
        """Create a Pyrodon."""
        return Pyrodon()


class AquaFactory(CreatureFactory):
    """Factory for Aquabub and its evolution Torragon."""

    def create_base(self) -> Creature:
        """Create an Aquabub."""
        return Aquabub()

    def create_evolved(self) -> Creature:
        """Create a Torragon."""
        return Torragon()
