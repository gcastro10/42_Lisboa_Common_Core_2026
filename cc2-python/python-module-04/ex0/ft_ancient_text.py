import sys
from typing import List


def recover_ancient_text(args: List[str]) -> None:
    """Reads a file from command line arguments and prints its contents."""
    # Check if exactly one argument (the filename) is provided.
    # args[0] is the script name, just like argv[0] in C.
    if len(args) != 2:
        print("Usage: ft_ancient_text.py <filename>")
        return

    filename: str = args[1]

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        # Open the file in read-text mode ('r')
        file_stream = open(filename, "r")
        try:
            content: str = file_stream.read()
            print("---")
            # end="" prevents print() from adding an extra newline if the file
            # already ends with one
            print(content, end="")
            print("---")
        finally:
            # Ensuring the file closes even if printing/reading fails
            file_stream.close()
            print(f"File '{filename}' closed.")

    except OSError as error:
        # Catches FileNotFoundError, PermissionError, etc. (similar to errno in C)
        print(f"Error opening file '{filename}': {error}")


if __name__ == "__main__":
    recover_ancient_text(sys.argv)
