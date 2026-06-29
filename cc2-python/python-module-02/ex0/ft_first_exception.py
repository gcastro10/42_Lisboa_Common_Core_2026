"""Module for validating agricultural temperature sensor data."""


def input_temperature(temp_str: str) -> int:
    """Convert a temperature string from a field sensor into an integer.

    Args:
        temp_str (str): The raw string data from the sensor.

    Returns:
        int: The parsed integer temperature.

    Raises:
        ValueError: If the string cannot be converted to an integer.
    """
    return int(temp_str)


def test_temperature() -> None:
    """Test the temperature input function with both valid and invalid inputs."""
    print("=== Garden Temperature ===")

    # Test Case 1: Valid Input
    valid_data = "25"
    print(f"Input data is '{valid_data}'")
    try:
        temp = input_temperature(valid_data)
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")

    # Test Case 2: Invalid Input
    invalid_data = "abc"
    print(f"Input data is '{invalid_data}'")
    try:
        temp = input_temperature(invalid_data)
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        # Catching the specific ValueError raised by int()
        print(f"Caught input_temperature error: {e}")

    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
