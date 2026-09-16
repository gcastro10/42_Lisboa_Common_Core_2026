from ex0 import Creature

from .capabilities import HealCapability, TransformCapability


class Sproutling(Creature, HealCapability):
    """Base grass-family creature with a small self-heal."""

    def __init__(self) -> None:
        """Create a Sproutling."""
        Creature.__init__(self, "Sproutling", "Grass")

    def attack(self) -> str:
        """Use Vine Whip."""
        return "Sproutling uses Vine Whip!"

    def heal(self, target: object | None = None) -> str:
        """Heal a small amount."""
        return "Sproutling heals itself for a small amount"


class Bloomelle(Creature, HealCapability):
    """Evolved grass-family creature with a large group heal."""

    def __init__(self) -> None:
        """Create a Bloomelle."""
        Creature.__init__(self, "Bloomelle", "Grass/Fairy")

    def attack(self) -> str:
        """Use Petal Dance."""
        return "Bloomelle uses Petal Dance!"

    def heal(self, target: object | None = None) -> str:
        """Heal a large amount."""
        return "Bloomelle heals itself and others for a large amount"


class Shiftling(Creature, TransformCapability):
    """Base normal-family creature that can sharpen its form."""

    def __init__(self) -> None:
        """Create a Shiftling in its normal form."""
        Creature.__init__(self, "Shiftling", "Normal")
        TransformCapability.__init__(self)

    def attack(self) -> str:
        """Strike normally or with a boosted form."""
        if self._transformed:
            return "Shiftling performs a boosted strike!"
        return "Shiftling attacks normally."

    def transform(self) -> str:
        """Shift into a sharper form."""
        self._transformed = True
        return "Shiftling shifts into a sharper form!"

    def revert(self) -> str:
        """Return to the normal form."""
        self._transformed = False
        return "Shiftling returns to normal."


class Morphagon(Creature, TransformCapability):
    """Evolved dragon-family creature that can morph in battle."""

    def __init__(self) -> None:
        """Create a Morphagon in its normal form."""
        Creature.__init__(self, "Morphagon", "Normal/Dragon")
        TransformCapability.__init__(self)

    def attack(self) -> str:
        """Strike normally or with a morph strike."""
        if self._transformed:
            return "Morphagon unleashes a devastating morph strike!"
        return "Morphagon attacks normally."

    def transform(self) -> str:
        """Morph into a dragonic battle form."""
        self._transformed = True
        return "Morphagon morphs into a dragonic battle form!"

    def revert(self) -> str:
        """Stabilize back to the normal form."""
        self._transformed = False
        return "Morphagon stabilizes its form."
