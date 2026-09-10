import random

# A fixed pool of distinct game achievements
ACHIEVEMENT_POOL: list[str] = [
    "First Steps",
    "Master Explorer",
    "Collector Supreme",
    "Crafting Genius",
    "World Savior",
    "Untouchable",
    "Boss Slayer",
    "Strategist",
    "Unstoppable",
    "Speed Runner",
    "Survivor",
    "Treasure Hunter",
    "Sharp Mind",
    "Hidden Path Finder",
]


def gen_player_achievements() -> set[str]:
    """Select a random achievement subset for one player's profile."""
    # To ensure varied overlaps, we pick between 5 and 9 unique achievements
    num_achievements: int = random.randint(5, 9)

    # random.sample picks unique elements without replacement
    selected: list[str] = random.sample(ACHIEVEMENT_POOL, num_achievements)
    return set(selected)


def main() -> None:
    """Execute the achievement tracking system analytics."""
    print("=== Achievement Tracker System ===")

    # 1. Generate profiles for 4 distinct players
    player_names: list[str] = ["Alice", "Bob", "Charlie", "Dylan"]
    player_sets: list[set[str]] = [
        gen_player_achievements(),
        gen_player_achievements(),
        gen_player_achievements(),
        gen_player_achievements(),
    ]

    player_index: int = 0
    while player_index < len(player_names):
        print(f"Player {player_names[player_index]}: "
              f"{player_sets[player_index]}")
        player_index += 1

    # 2. All distinct achievements unlocked among all players (Union)
    # Using the unpacking operator * to union all sets together
    all_unlocked: set[str] = set.union(
        player_sets[0], player_sets[1], player_sets[2], player_sets[3]
    )
    print(f"All distinct achievements: {all_unlocked}")

    # 3. Achievements shared by all players (Intersection)
    common: set[str] = set.intersection(
        player_sets[0], player_sets[1], player_sets[2], player_sets[3]
    )
    print(f"Common achievements: {common}")

    # Full universal set of all possible achievements in the game
    full_pool_set: set[str] = set(ACHIEVEMENT_POOL)

    # Calculate individual unique and missing sets
    player_index = 0
    while player_index < len(player_names):
        current_set: set[str] = player_sets[player_index]
        if player_index == 0:
            everyone_else = set.union(
                player_sets[1], player_sets[2], player_sets[3]
            )
        elif player_index == 1:
            everyone_else = set.union(
                player_sets[0], player_sets[2], player_sets[3]
            )
        elif player_index == 2:
            everyone_else = set.union(
                player_sets[0], player_sets[1], player_sets[3]
            )
        else:
            everyone_else = set.union(
                player_sets[0], player_sets[1], player_sets[2]
            )

        unique_to_player: set[str] = current_set.difference(everyone_else)
        print(f"Only {player_names[player_index]} has: {unique_to_player}")
        player_index += 1

    player_index = 0
    while player_index < len(player_names):
        missing: set[str] = full_pool_set.difference(player_sets[player_index])
        print(f"{player_names[player_index]} is missing: {missing}")
        player_index += 1


if __name__ == "__main__":
    main()
