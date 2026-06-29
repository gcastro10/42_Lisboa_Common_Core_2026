import random


def main() -> None:
    """Transform, filter, and analyze player data using comprehensions."""
    print("=== Game Data Alchemist ===")

    initial_players: list[str] = [
        "Alice",
        "bob",
        "Charlie",
        "dylan",
        "Emma",
        "Gregory",
        "john",
        "kevin",
        "Liam",
    ]
    print(f"Initial list of players: {initial_players}")

    # 1. List comprehension: Capitalize all names (.map equivalency)
    # .capitalize() forces the first letter uppercase and the rest lowercase
    all_capitalized: list[str] = [name.capitalize() for name in initial_players]
    print(f"New list with all names capitalized: {all_capitalized}")

    # 2. List comprehension: Filter out only initially capitalized names
    # .istitle() or .isupper() checks can work; name[0].isupper() is precise
    only_initially_cap: list[str] = [
        name for name in initial_players if name[0].isupper()
    ]
    print(f"New list of capitalized names only: {only_initially_cap}")

    # 3. Dict comprehension: Build random score maps for all players
    score_dict: dict[str, int] = {
        name: random.randint(50, 950) for name in all_capitalized
    }
    print(f"Score dict: {score_dict}")

    # Calculate average score using the authorized sum() and len() built-ins
    total_score: int = sum(score_dict.values())
    avg_score: float = total_score / len(score_dict) if score_dict else 0.0
    print(f"Score average is {round(avg_score, 2)}")

    # 4. Dict comprehension: Filter items higher than the average score
    high_scores: dict[str, int] = {
        name: score for name, score in score_dict.items() if score > avg_score
    }
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    main()
