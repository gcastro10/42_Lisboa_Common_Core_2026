"""Module for robust validation and range checking of sensor data."""


def input_temperature(temp_str: str) -> int:
    """Convert and validate a temperature string from a field sensor.

    Args:
        temp_str (str): The raw string data from the sensor.

    Returns:
        int: The parsed integer temperature if within safe limits.

    Raises:
        ValueError: If data is non-numeric, too hot (>40°C), or too cold (<0°C).
    """
    # Step 1: Type validation (Can raise a ValueError naturally)
    temp: int = int(temp_str)

    # Step 2: Domain validation (Manually raising ValueError for bad ranges)
    if temp > 40:
        raise ValueError(f"{temp}°C is too hot for plants (max 40°C)")
    if temp < 0:
        raise ValueError(f"{temp}°C is too cold for plants (min 0°C)")

    return temp


def test_temperature() -> None:
    """Execute evaluation cases for the validation pipeline."""
    print("=== Garden Temperature Checker ===")

    # Define test cases as pairs of input strings and descriptions
    test_cases: list[str] = ["25", "abc", "100", "-50"]

    for data in test_cases:
        print(f"Input data is '{data}'")
        try:
            temp = input_temperature(data)
            print(f"Temperature is now {temp}°C")
        except ValueError as e:
            print(f"Caught input_temperature error: {e}")

    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
