import sys


def main() -> None:
    """Process and display command-line arguments."""
    print("=== Command Quest ===")

    # In Python, len() gives the total count of items in a list
    total_args: int = len(sys.argv)
    program_name: str = sys.argv[0]

    print(f"Program name: {program_name}")

    argument_count: int = total_args - 1

    if argument_count == 0:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {argument_count}")
        index: int = 1
        while index < total_args:
            print(f"Argument {index}: {sys.argv[index]}")
            index += 1

    print(f"Total arguments: {total_args}")


if __name__ == "__main__":
    main()
