import sys


def main() -> None:
    """Process and display command-line arguments."""
    print("=== Command Quest ===")

    # In Python, len() gives the total count of items in a list
    total_args: int = len(sys.argv)
    program_name: str = sys.argv[0]

    print(f"Program name: {program_name}")

    # Slice the list to separate the script name from actual arguments
    # sys.argv[1:] is equivalent to TS: sys.argv.slice(1)
    arguments: list[str] = sys.argv[1:]

    if not arguments:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {len(arguments)}")
        # enumerate(..., 1) gives us both the index (starting at 1) and the item
        for index, arg in enumerate(arguments, 1):
            print(f"Argument {index}: {arg}")

    print(f"Total arguments: {total_args}")


if __name__ == "__main__":
    main()
