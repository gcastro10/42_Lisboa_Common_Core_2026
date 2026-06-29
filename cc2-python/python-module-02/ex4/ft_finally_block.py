"""Module demonstrating resource cleanup architectures using finally blocks."""


class PlantError(Exception):
    """Exception raised for specific problems concerning plant health."""

    def __init__(self, message: str = "Unknown plant error"):
        """Initialize the exception with a default message."""
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    """Simulate watering a specific plant, enforcing capital casing naming rules.

    Args:
        plant_name (str): The name of the plant asset.

    Raises:
        PlantError: If the plant name does not meet formatting standards.
    """
    # str.capitalize() capitalizes the first letter and lowers the rest.
    # If the initial string isn't exactly matches that layout, we reject it.
    if plant_name != plant_name.capitalize():
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")

    print(f"Watering {plant_name}: [OK]")


def run_pipeline_batch(plants: list[str]) -> None:
    """Execute a batch irrigation process wrapped inside a deterministic life cycle.

    Args:
        plants (list[str]): Names of plants to process.
    """
    print("Opening watering system")
    try:
        for plant in plants:
            water_plant(plant)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
        return  # Explicit early return from function
    finally:
        # This execution path is guaranteed by the runtime engine
        print("Closing watering system")


def test_watering_system() -> None:
    """Simulate both healthy and volatile scenarios inside the pipeline."""
    print("=== Garden Watering System ===")

    print("Testing valid plants...")
    valid_batch: list[str] = ["Tomato", "Lettuce", "Carrots"]
    run_pipeline_batch(valid_batch)

    print("\nTesting invalid plants...")
    invalid_batch: list[str] = ["Tomato", "lettuce", "Carrots"]
    run_pipeline_batch(invalid_batch)

    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
