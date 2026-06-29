"""Module demonstrating rapid plant instantiation using standard constructors."""


class Plant:
    """Represents a plant completely initialized upon instantiation."""

    def __init__(self, name: str, height: float, age: int) -> None:
        """Initializes a new Plant instance immediately ready for deployment.

        Args:
            name: The type/name of the plant.
            height: Height in centimeters.
            age: Age in days.
        """
        self.name: str = name
        self.height: float = height
        self.age: int = age

    def show(self) -> None:
        """Displays the formatted details of the plant."""
        rounded_height: float = round(self.height, 1)
        print(
            f"Created: {self.name.capitalize()}: "
            f"{rounded_height}cm, {self.age} days old"
        )


def main() -> None:
    """Instantiates multiple plants rapidly and loops through to display them."""
    print("=== Plant Factory Output ===")

    # Streamlining creation by batching instances into a structured Python list
    garden_inventory: list[Plant] = [
        Plant("rose", 25.0, 30),
        Plant("oak", 200.0, 365),
        Plant("cactus", 5.0, 90),
        Plant("sunflower", 80.0, 45),
        Plant("fern", 15.0, 120),
    ]

    # Iterating over the collection cleanly using a standard loop
    for plant in garden_inventory:
        plant.show()


if __name__ == "__main__":
    main()
