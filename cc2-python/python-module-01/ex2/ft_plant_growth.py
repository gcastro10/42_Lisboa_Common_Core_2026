"""Module simulating plant growth and aging over a week-long period."""


class Plant:
    """Represents a plant that can age and grow dynamically over time."""

    def __init__(
        self, name: str, height: float, age: int, growth_rate: float
    ) -> None:
        """Initializes a new Plant instance with a unique growth rate."""
        self.name: str = name
        self.height: float = height
        self.age: int = age
        self.growth_rate: float = growth_rate

    def grow(self) -> None:
        """Increases the height of the plant by its specific growth rate."""
        self.height += self.growth_rate

    def age_one_day(self) -> None:
        """Increases the age of the plant by one day."""
        self.age += 1

    def show(self) -> None:
        """Displays the formatted details of the plant with float precision."""
        # round() ensures clean floating-point display to 1 decimal place
        rounded_height: float = round(self.height, 1)
        print(
            f"{self.name.capitalize()}: "
            f"{rounded_height}cm, {self.age} days old"
        )


def main() -> None:
    """Simulates a week of growth for a plant and prints daily progress."""
    print("=== Garden Plant Growth ===")

    # Initializing a Rose with a starting height of 25.0cm and growth rate of 0.8cm/day
    rose: Plant = Plant("rose", 25.0, 30, 0.8)
    rose.show()

    initial_height: float = rose.height

    # Simulate 7 days using the authorized range() function
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        rose.grow()
        rose.age_one_day()
        rose.show()

    # Calculate total increase over the week
    weekly_growth: float = round(rose.height - initial_height, 1)
    print(f"Growth this week: {weekly_growth}cm")


if __name__ == "__main__":
    main()
