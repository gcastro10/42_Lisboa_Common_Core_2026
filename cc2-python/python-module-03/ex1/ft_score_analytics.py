import sys


def main() -> None:
    """Analyze and display command-line player score statistics."""
    print("=== Player Score Analytics ===")

    scores: list[int] = []

    # Process input parameters using EAFP style error handling
    index: int = 1
    while index < len(sys.argv):
        arg: str = sys.argv[index]
        try:
            # Attempt to convert to int. Throws ValueError if it fails.
            score: int = int(arg)
            scores = scores + [score]
        except ValueError:
            print(f"Invalid parameter: '{arg}'")
        index += 1

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
