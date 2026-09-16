from abc import ABC, abstractmethod


class Creature(ABC):
    """Abstract creature card with a name, a type, and an attack."""

    def __init__(self, name: str, creature_type: str) -> None:
        """Store the creature display name and elemental type."""
        self.name: str = name
        self.creature_type: str = creature_type

    @abstractmethod
    def attack(self) -> str:
        """Return a string describing this creature's attack."""

    def describe(self) -> str:
        """Return a standard description using name and type."""
        return f"{self.name} is a {self.creature_type} type Creature"


class Flameling(Creature):
    """Base creature of the fire family."""

    def __init__(self) -> None:
        """Create a Flameling."""
        super().__init__("Flameling", "Fire")

    def attack(self) -> str:
        """Use Ember."""
        return "Flameling uses Ember!"


class Pyrodon(Creature):
    """Evolved creature of the fire family."""

    def __init__(self) -> None:
        """Create a Pyrodon."""
        super().__init__("Pyrodon", "Fire/Flying")

    def attack(self) -> str:
        """Use Flamethrower."""
        return "Pyrodon uses Flamethrower!"


class Aquabub(Creature):
    """Base creature of the water family."""

    def __init__(self) -> None:
        """Create an Aquabub."""
        super().__init__("Aquabub", "Water")

    def attack(self) -> str:
        """Use Water Gun."""
        return "Aquabub uses Water Gun!"


class Torragon(Creature):
    """Evolved creature of the water family."""

    def __init__(self) -> None:
        """Create a Torragon."""
        super().__init__("Torragon", "Water")

    def attack(self) -> str:
        """Use Hydro Pump."""
        return "Torragon uses Hydro Pump!"
