"""Module for managing and displaying individual plant data in a garden."""


class Plant:
    """Represents a plant in the garden with its core physical traits."""

    def __init__(self, name: str, height: int, age: int) -> None:
        """Initializes a new Plant instance.

        Args:
            name: The type/name of the plant.
            height: Height in centimeters.
            age: Age in days.
        """
        self.name: str = name
        self.height: int = height
        self.age: int = age

    def show(self) -> None:
        """Displays the formatted details of the plant."""
        # Custom string formatting to match the example output requirements
        print(
            f"{self.name.capitalize()}: "
            f"{self.height}cm, {self.age} days old"
        )


def main() -> None:
    """Main execution function to manage the garden registry."""
    print("=== Garden Plant Registry ===")

    # Instantiating the 3 plant objects required by the exercise
    rose: Plant = Plant("rose", 25, 30)
    sunflower: Plant = Plant("sunflower", 80, 45)
    cactus: Plant = Plant("cactus", 15, 120)

    # Displaying their information
    rose.show()
    sunflower.show()
    cactus.show()


if __name__ == "__main__":
    main()
