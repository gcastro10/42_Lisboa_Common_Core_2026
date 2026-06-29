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
    """Randomly select a subset of achievements to simulate a player's profile."""
    # To ensure varied overlaps, we pick between 5 and 9 unique achievements
    num_achievements: int = random.randint(5, 9)

    # random.sample picks unique elements without replacement
    selected: list[str] = random.sample(ACHIEVEMENT_POOL, num_achievements)
    return set(selected)


def main() -> None:
    """Execute the achievement tracking system analytics."""
    print("=== Achievement Tracker System ===")

    # 1. Generate profiles for 4 distinct players
    # Using a dictionary to cleanly map player names to their achievement sets
    players: dict[str, set[str]] = {
        "Alice": gen_player_achievements(),
        "Bob": gen_player_achievements(),
        "Charlie": gen_player_achievements(),
        "Dylan": gen_player_achievements(),
    }

    for name, achievements in players.items():
        print(f"Player {name}: {achievements}")

    # 2. All distinct achievements unlocked among all players (Union)
    # Using the unpacking operator * to union all sets together
    all_unlocked: set[str] = set.union(*players.values())
    print(f"All distinct achievements: {all_unlocked}")

    # 3. Achievements shared by all players (Intersection)
    common: set[str] = set.intersection(*players.values())
    print(f"Common achievements: {common}")

    # Full universal set of all possible achievements in the game
    full_pool_set: set[str] = set(ACHIEVEMENT_POOL)

    # Calculate individual unique and missing sets
    for name, current_set in players.items():
        # Get a union of everyone else's achievements
        everyone_else: set[str] = set.union(
            *(s for p, s in players.items() if p != name)
        )

        # 4. Spot achievements NO ONE else has (Difference)
        unique_to_player: set[str] = current_set.difference(everyone_else)
        print(f"Only {name} has: {unique_to_player}")

    for name, current_set in players.items():
        # 5. List missing achievements to unlock everything in the entire game
        missing: set[str] = full_pool_set.difference(current_set)
        print(f"Alice is missing: {missing}" if name == "Alice" else f"{name} is missing: {missing}")


if __name__ == "__main__":
    main()
