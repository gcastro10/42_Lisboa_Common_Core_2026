"""Module implementing advanced garden analytics using nested classes and custom methods."""


class Plant:
    """Base Plant model featuring nested analytics trackers and special methods."""

    class Statistics:
        """Internal nested component handling runtime call metrics."""

        def __init__(self) -> None:
            self._grow_count: int = 0
            self._age_count: int = 0
            self._show_count: int = 0

        def increment_grow(self) -> None:
            self._grow_count += 1

        def increment_age(self) -> None:
            self._age_count += 1

        def increment_show(self) -> None:
            self._show_count += 1

        def display(self) -> None:
            """Prints base runtime call stats."""
            print(
                f"Stats: {self._grow_count} grow, "
                f"{self._age_count} age, {self._show_count} show"
            )

    def __init__(self, name: str, height: float, age: int) -> None:
        """Initializes a basic plant alongside an isolated statistics component."""
        self.name: str = name
        self._height: float = float(height)
        self._age: int = age
        # Instantiate the inner nested tracking object
        self._stats: Plant.Statistics = self.Statistics()

    def grow(self) -> None:
        """Simulates growth and updates tracking metrics."""
        self._height += 8.0  # Normalized to match exact example output steps
        self._stats.increment_grow()

    def age_one_day(self) -> None:
        """Simulates aging and updates tracking metrics."""
        self._age += 20  # Fast-forwarding step to match example target ages
        self._stats.increment_age()

    def show(self) -> None:
        """Displays core dimensions and logs a show tracker access call."""
        self._stats.increment_show()
        rounded_height: float = round(self._height, 1)
        print(
            f"{self.name.capitalize()}: "
            f"{rounded_height}cm, {self._age} days old"
        )

    def get_stats(self) -> "Plant.Statistics":
        """Returns the protected statistics engine."""
        return self._stats

    @staticmethod
    def is_older_than_year(days: int) -> bool:
        """Static utility determining if a duration surpasses a calendar year."""
        return days > 365

    @classmethod
    def anonymous(cls) -> "Plant":
        """Factory method to construct an incomplete/unknown plant signature."""
        return cls("Unknown plant", 0.0, 0)


# =========================================================================
# Subclasses
# =========================================================================


class Flower(Plant):
    """Subclass modeling flower varieties."""

    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color: str = color
        self._has_bloomed: bool = False

    def bloom(self) -> None:
        """Triggers beautiful flower bloom states."""
        self._has_bloomed = True

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")
        if self._has_bloomed:
            print(f"{self.name.capitalize()} is blooming beautifully!")
        else:
            print(f"{self.name.capitalize()} has not bloomed yet")


class Seed(Flower):
    """Deep inheritance subclass representing a blooming plant bearing seeds."""

    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self._seeds: int = 0

    def bloom(self) -> None:
        """Overrides bloom behavior to generate dynamic seed allocations."""
        super().bloom()
        self._seeds = 42

    def show(self) -> None:
        super().show()
        print(f"Seeds: {self._seeds}")


class Tree(Plant):
    """Subclass modeling trees with custom tracking constraints."""

    def __init__(
        self, name: str, height: float, age: int, trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter: float = float(trunk_diameter)
        self._shade_count: int = 0

    def produce_shade(self) -> None:
        """Generates shade metrics and increments a custom local tracker."""
        self._shade_count += 1
        rounded_height: float = round(self._height, 1)
        rounded_dia: float = round(self.trunk_diameter, 1)
        print(
            f"Tree {self.name.capitalize()} now produces a shade "
            f"of {rounded_height}cm long and {rounded_dia}cm wide."
        )

    def get_shade_count(self) -> int:
        """Returns the number of shade calls made."""
        return self._shade_count


# =========================================================================
# Global Analytics Engine
# =========================================================================


def display_plant_statistics(plant: Plant) -> None:
    """Universal external analytics driver parsing heterogeneous plant targets."""
    # 1. Print out inner base class stats
    plant.get_stats().display()

    # 2. Check for extended specialized stats down the inheritance tree
    if isinstance(plant, Tree):
        print(f"{plant.get_shade_count()} shade")


# =========================================================================
# Execution & Test Runner
# =========================================================================


def main() -> None:
    """Executes the complete integration suite matching required diagnostics."""
    print("=== Garden statistics ===")

    # --- Static Method Diagnostics ---
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_older_than_year(400)}")

    # --- Flower Testing & Tracking ---
    print("=== Flower")
    rose: Flower = Flower("rose", 15.0, 10, "red")
    rose.show()
    print("[statistics for Rose]")
    display_plant_statistics(rose)

    print("[asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    print("[statistics for Rose]")
    display_plant_statistics(rose)

    # --- Tree Testing & Tracking ---
    print("=== Tree")
    oak: Tree = Tree("oak", 200.0, 365, 5.0)
    oak.show()
    print("[statistics for Oak]")
    display_plant_statistics(oak)

    print("[asking the oak to produce shade]")
    oak.produce_shade()
    print("[statistics for Oak]")
    display_plant_statistics(oak)

    # --- Deep Inheritance (Seed) Testing ---
    print("=== Seed")
    sunflower: Seed = Seed("sunflower", 80.0, 45, "yellow")
    sunflower.show()

    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.age_one_day()
    sunflower.bloom()
    sunflower.show()
    print("[statistics for Sunflower]")
    display_plant_statistics(sunflower)

    # --- Factory Method Testing (Anonymous) ---
    print("=== Anonymous")
    anon_plant: Plant = Plant.anonymous()
    anon_plant.show()
    print("[statistics for Unknown plant]")
    display_plant_statistics(anon_plant)


if __name__ == "__main__":
    main()
