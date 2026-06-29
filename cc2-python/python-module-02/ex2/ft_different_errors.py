"""Module demonstrating handling of multiple distinct exception types."""


def garden_operations(operation_number: int) -> None:
    """Trigger intentional architectural errors based on an operation identifier.

    Args:
        operation_number (int): ID mapping to a specific faulty code block.

    Raises:
        ValueError: For bad data conversion.
        ZeroDivisionError: For mathematical impossibility.
        FileNotFoundError: For missing file resources.
        TypeError: For unsupported type operations.
    """
    if operation_number == 0:
        # Trigger ValueError
        int("abc")
    elif operation_number == 1:
        # Trigger ZeroDivisionError
        _ = 10 / 0
    elif operation_number == 2:
        # Trigger FileNotFoundError
        open("/non/existent/file", "r")
    elif operation_number == 3:
        # Trigger TypeError - # type: ignore bypasses mypy warning
        _ = "water" + 5  # type: ignore[operator]


def test_error_types() -> None:
    """Execute and isolate multiple exception handling tests."""
    print("=== Garden Error Types Demo ===")

    # Test individual exceptions sequentially
    for op in range(5):
        print(f"Testing operation {op}...")
        try:
            garden_operations(op)
            if op == 4:
                print("Operation completed successfully")
        except ValueError as e:
            print(f"Caught ValueError: {e}")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
        except TypeError as e:
            print(f"Caught TypeError: {e}")

    # Demonstration: Catching multiple errors with a SINGLE try/except block
    print("\n--- Testing Compound Exception Block ---")
    for op in [0, 1]:
        try:
            garden_operations(op)
        except (ValueError, ZeroDivisionError) as e:
            print(f"Caught common pipeline error via tuple: {e}")

    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
