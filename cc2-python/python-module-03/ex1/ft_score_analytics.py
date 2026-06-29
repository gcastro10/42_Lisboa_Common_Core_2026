import sys


def main() -> None:
    """Analyze and display statistics for player scores from command-line arguments."""
    print("=== Player Score Analytics ===")

    # Grab arguments excluding the script name
    raw_args: list[str] = sys.argv[1:]
    scores: list[int] = []

    # Process input parameters using EAFP style error handling
    for arg in raw_args:
        try:
            # Attempt to convert to int. Throws ValueError if it fails.
            score: int = int(arg)
            scores.append(score)
        except ValueError:
            print(f"Invalid parameter: '{arg}'")

    # If no valid scores were extracted (either empty input or all invalid)
    if not scores:
        print(
            "No scores provided. Usage: "
            "python3 ft_score_analytics.py <score1> <score2> ..."
        )
        return

    # Calculate analytical metrics using authorized built-ins
    total_players: int = len(scores)
    total_score: int = sum(scores)
    # Python 3 performs float division with /, integer division with //
    average_score: float = total_score / total_players
    high_score: int = max(scores)
    low_score: int = min(scores)
    score_range: int = high_score - low_score

    # Display results formatted identically to the game requirements
    print(f"Scores processed: {scores}")
    print(f"Total players: {total_players}")
    print(f"Total score: {total_score}")
    print(f"Average score: {average_score}")
    print(f"High score: {high_score}")
    print(f"Low score: {low_score}")
    print(f"Score range: {score_range}")


if __name__ == "__main__":
    main()
