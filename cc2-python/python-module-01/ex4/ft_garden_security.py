"""Module implementing strict data validation and encapsulation for plant objects."""


class Plant:
    """Represents a plant with protected attributes and explicit accessors."""

    def __init__(self, name: str, height: float, age: int) -> None:
        """Initializes a plant, enforcing data integrity on creation."""
        self.name: str = name

        # Default values in case initialization data is invalid
        self._height: float = 0.0
        self._age: int = 0

        # Use setters during initialization to leverage validation logic
        self.set_height(height)
        self.set_age(age)

    # --- Getters ---
    def get_height(self) -> float:
        """Returns the protected height trait."""
        return self._height

    def get_age(self) -> int:
        """Returns the protected age trait."""
        return self._age

    # --- Setters ---
    def set_height(self, new_height: float) -> None:
        """Validates and sets the height attribute."""
        if new_height < 0:
            print(f"{self.name.capitalize()}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = float(new_height)

    def set_age(self, new_age: int) -> None:
        """Validates and sets the age attribute."""
        if new_age < 0:
            print(f"{self.name.capitalize()}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = new_age

    def show(self) -> None:
        """Displays the current secure state of the plant."""
        rounded_height: float = round(self._height, 1)
        print(
            f"{self.name.capitalize()}: "
            f"{rounded_height}cm, {self._age} days old"
        )


def main() -> None:
    """Demonstrates data security validation by executing edge case tests."""
    print("=== Garden Security System ===")

    # 1. Create a plant validly
    rose: Plant = Plant("rose", 15.0, 10)
    print(
        f"Plant created: {rose.name.capitalize()}: "
        f"{rose.get_height()}cm, {rose.get_age()} days old"
    )

    # 2. Valid Updates
    rose.set_height(25.0)
    print(f"Height updated: {int(rose.get_height())}cm")

    rose.set_age(30)
    print(f"Age updated: {rose.get_age()} days")

    # 3. Invalid Updates (Should trigger error logs and rejections)
    rose.set_height(-5.0)
    rose.set_age(-1)

    # 4. Confirm final state remained uncorrupted
    print("Current state:", end=" ")
    rose.show()


if __name__ == "__main__":
    main()
