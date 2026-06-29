"""Module to introduce basic Python program structure and variable usage."""


def display_garden_intro() -> None:
    """Displays information about a specific plant in the garden."""
    # Simple variables with type hints
    name: str = "Rose"
    height: int = 25
    age: int = 30

    # Displaying the plant information using print()
    print("=== Welcome to My Garden ===")
    print(f"Plant: {name.capitalize()}")
    print(f"Height: {height}cm")
    print(f"Age: {age} days")
    print("=== End of Program ===")


if __name__ == "__main__":
    display_garden_intro()
