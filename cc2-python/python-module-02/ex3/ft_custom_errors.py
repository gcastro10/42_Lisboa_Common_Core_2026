"""Module implementing a custom exception hierarchy for smart agriculture."""


class GardenError(Exception):
    """Base exception for all general garden-related issues."""

    def __init__(self, message: str = "Unknown garden error"):
        """Initialize the exception with a default message.

        Args:
            message (str): The specific error context.
        """
        super().__init__(message)


class PlantError(GardenError):
    """Exception raised for specific problems concerning plant health."""

    def __init__(self, message: str = "Unknown plant error"):
        """Initialize the exception with a default message."""
        super().__init__(message)


class WaterError(GardenError):
    """Exception raised for irrigation and tank level anomalies."""

    def __init__(self, message: str = "Unknown water error"):
        """Initialize the exception with a default message."""
        super().__init__(message)


def monitor_crop(status: str) -> None:
    """Evaluate health status of crops.

    Args:
        status (str): The physiological state of the crop.

    Raises:
        PlantError: If the plant state indicates severe distress.
    """
    if status == "wilting":
        raise PlantError("The tomato plant is wilting!")


def monitor_irrigation(level: int) -> None:
    """Evaluate reservoir levels for watering systems.

    Args:
        level (int): Remaining tank volume percentage.

    Raises:
        WaterError: If the tank volume falls below operational minimums.
    """
    if level < 20:
        raise WaterError("Not enough water in the tank!")


def test_custom_errors() -> None:
    """Validate behavior of the custom agricultural exception hierarchy."""
    print("=== Custom Garden Errors Demo ===")

    # 1. Testing specific granularity catching
    print("Testing PlantError...")
    try:
        monitor_crop("wilting")
    except PlantError as e:
        print(f"Caught PlantError: {e}")

    print("Testing WaterError...")
    try:
        monitor_irrigation(10)
    except WaterError as e:
        print(f"Caught WaterError: {e}")

    # 2. Testing polymorphic catching via the base class (GardenError)
    print("Testing catching all garden errors...")
    for action in [lambda: monitor_crop("wilting"), lambda: monitor_irrigation(10)]:
        try:
            action()
        except GardenError as e:
            print(f"Caught GardenError: {e}")

    print("All custom error types work correctly!")


if __name__ == "__main__":
    test_custom_errors()
