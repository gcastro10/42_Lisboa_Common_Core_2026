"""Module demonstrating OOP Inheritance with specialized plant subclasses."""


class Plant:
    """Base parent class containing attributes common to all vegetation."""

    def __init__(self, name: str, height: float, age: int) -> None:
        """Initializes core physical traits common across all plant life."""
        self.name: str = name
        self._height: float = float(height)
        self._age: int = age

    def grow(self) -> None:
        """Simulates growth by increasing height."""
        self._height += 2.1  # Base daily growth rate

    def age_one_day(self) -> None:
        """Simulates aging by adding a day."""
        self._age += 1

    def show(self) -> None:
        """Displays common plant state metrics."""
        rounded_height: float = round(self._height, 1)
        print(
            f"{self.name.capitalize()}: "
            f"{rounded_height}cm, {self._age} days old"
        )


# =========================================================================
# Specialized Subclasses
# =========================================================================


class Flower(Plant):
    """Specialized plant type representing flowers."""

    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        """Initializes a Flower, calling the parent constructor via super()."""
        super().__init__(name, height, age)
        self.color: str = color
        self._has_bloomed: bool = False

    def bloom(self) -> None:
        """Triggers the blooming sequence for the flower."""
        self._has_bloomed = True

    def show(self) -> None:
        """Overrides parent show to chain basic metrics with unique traits."""
        super().show()  # Reuse parent display logic
        print(f"Color: {self.color}")
        if self._has_bloomed:
            print(f"{self.name.capitalize()} is blooming beautifully!")
        else:
            print(f"{self.name.capitalize()} has not bloomed yet")


class Tree(Plant):
    """Specialized plant type representing trees."""

    def __init__(
        self, name: str, height: float, age: int, trunk_diameter: float
    ) -> None:
        """Initializes a Tree instance with custom structural dimensions."""
        super().__init__(name, height, age)
        self.trunk_diameter: float = float(trunk_diameter)

    def produce_shade(self) -> None:
        """Prints details about the shade production of the tree."""
        # Using parent properties directly inside the subclass
        rounded_height: float = round(self._height, 1)
        rounded_dia: float = round(self.trunk_diameter, 1)
        print(
            f"Tree {self.name.capitalize()} now produces a shade "
            f"of {rounded_height}cm long and {rounded_dia}cm wide."
        )

    def show(self) -> None:
        """Displays tree metrics by leveraging the parent implementation."""
        super().show()
        print(f"Trunk diameter: {round(self.trunk_diameter, 1)}cm")


class Vegetable(Plant):
    """Specialized plant type representing food-producing vegetables."""

    def __init__(
        self, name: str, height: float, age: int, harvest_season: str
    ) -> None:
        """Initializes a Vegetable instance with zero initial nutrition."""
        super().__init__(name, height, age)
        self.harvest_season: str = harvest_season
        self.nutritional_value: int = 0

    def grow_and_age_cycle(self, days: int) -> None:
        """Cycles growth and aging while building nutritional density."""
        for _ in range(days):
            self.grow()
            self.age_one_day()
            # Nutrition scales concurrently with the plant's growth cycle
            self.nutritional_value += 1

    def show(self) -> None:
        """Displays vegetable structural metrics alongside nutritional metrics."""
        super().show()
        print(f"Harvest season: {self.harvest_season}")
        print(f"Nutritional value: {self.nutritional_value}")


# =========================================================================
# Execution Context
# =========================================================================


def main() -> None:
    """Executes behavioral demonstrations on inherited specialized types."""
    print("=== Garden Plant Types ===")

    # --- Flower Testing ---
    print("=== Flower")
    rose: Flower = Flower("rose", 15.0, 10, "red")
    rose.show()
    print("[asking the rose to bloom]")
    rose.bloom()
    rose.show()

    # --- Tree Testing ---
    print("=== Tree")
    oak: Tree = Tree("oak", 200.0, 365, 5.0)
    oak.show()
    print("[asking the oak to produce shade]")
    oak.produce_shade()

    # --- Vegetable Testing ---
    print("=== Vegetable")
    tomato: Vegetable = Vegetable("tomato", 5.0, 10, "April")
    tomato.show()
    print("[make tomato grow and age for 20 days]")
    tomato.grow_and_age_cycle(20)
    tomato.show()


if __name__ == "__main__":
    main()
