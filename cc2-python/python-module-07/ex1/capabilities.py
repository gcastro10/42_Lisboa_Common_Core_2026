from abc import ABC, abstractmethod


class HealCapability(ABC):
    """Capability that describes a healing action."""

    @abstractmethod
    def heal(self, target: object | None = None) -> str:
        """Return a string describing the healing action."""


class TransformCapability(ABC):
    """Capability that can transform and revert with persistent state."""

    def __init__(self) -> None:
        """Start in the untransformed state."""
        self._transformed: bool = False

    @abstractmethod
    def transform(self) -> str:
        """Enter the transformed state and describe the action."""

    @abstractmethod
    def revert(self) -> str:
        """Leave the transformed state and describe the action."""
