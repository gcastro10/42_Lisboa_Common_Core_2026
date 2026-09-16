from ex0 import AquaFactory, Creature, CreatureFactory, FlameFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    AggressiveStrategy,
    BattleStrategy,
    DefensiveStrategy,
    InvalidStrategyError,
    NormalStrategy,
)


def battle(
    opponents: list[tuple[CreatureFactory, BattleStrategy]],
) -> None:
    """Make each opponent fight every other opponent once."""
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    print("")

    fighters: list[tuple[Creature, BattleStrategy]] = []
    try:
        for factory, strategy in opponents:
            fighters.append((factory.create_base(), strategy))
    except Exception as exc:
        print(f"Battle error, aborting tournament: {exc}")
        return
    for i in range(len(fighters)):
        for j in range(i + 1, len(fighters)):
            left, left_strategy = fighters[i]
            right, right_strategy = fighters[j]
            print("* Battle *")
            print(left.describe())
            print("vs.")
            print(right.describe())
            print("now fight!")
            try:
                for line in left_strategy.act(left):
                    print(line)
                for line in right_strategy.act(right):
                    print(line)
            except InvalidStrategyError as exc:
                print(f"Battle error, aborting tournament: {exc}")
                print("")
                return
            print("")

def main() -> None:
    """Run the three subject tournaments."""
    flame = FlameFactory()
    aqua = AquaFactory()
    healing = HealingCreatureFactory()
    transforming = TransformCreatureFactory()
    normal = NormalStrategy()
    aggressive = AggressiveStrategy()
    defensive = DefensiveStrategy()

    print("Tournament 0 (basic)")
    print("[ (Flameling+Normal), (Healing+Defensive) ]")
    battle([(flame, normal), (healing, defensive)])

    print("Tournament 1 (error)")
    print("[ (Flameling+Aggressive), (Healing+Defensive) ]")
    battle([(flame, aggressive), (healing, defensive)])

    print("Tournament 2 (multiple)")
    print(
        "[ (Aquabub+Normal), (Healing+Defensive), "
        "(Transform+Aggressive) ]"
    )
    battle(
        [
            (aqua, normal),
            (healing, defensive),
            (transforming, aggressive),
        ]
    )


if __name__ == "__main__":
    main()
