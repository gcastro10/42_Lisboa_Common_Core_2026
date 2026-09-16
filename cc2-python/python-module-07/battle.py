from ex0 import AquaFactory, CreatureFactory, FlameFactory


def test_factory(factory: CreatureFactory) -> None:
    """Create base and evolved forms, then describe and attack each."""
    print("Testing factory")
    try:
        base = factory.create_base()
        evolved = factory.create_evolved()
    except Exception as exc:
        print(f"Factory error: {exc}")
        return
    print(base.describe())
    print(base.attack())
    print(evolved.describe())
    print(evolved.attack())
    print("")


def test_battle(
    factory_a: CreatureFactory, factory_b: CreatureFactory
) -> None:
    """Make the base creatures of two factories fight."""
    print("Testing battle")
    try:
        fighter_a = factory_a.create_base()
        fighter_b = factory_b.create_base()
    except Exception as exc:
        print(f"Battle error: {exc}")
        return
    print(fighter_a.describe())
    print("vs.")
    print(fighter_b.describe())
    print("fight!")
    print(fighter_a.attack())
    print(fighter_b.attack())


def main() -> None:
    """Instantiate fire and water factories, then run the demo."""
    flame = FlameFactory()
    aqua = AquaFactory()
    test_factory(flame)
    test_factory(aqua)
    test_battle(flame, aqua)


if __name__ == "__main__":
    main()
