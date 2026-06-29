import sys
from typing import List


def process_and_save_archive(args: List[str]) -> None:
    """Reads a file, transforms its text, and optionally saves it to a new file."""
    if len(args) != 2:
        print("Usage: ft_archive_creation.py <filename>")
        return

    filename: str = args[1]
    original_content: str = ""

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    # Step 1: Read the original file
    try:
        file_stream = open(filename, "r")
        try:
            original_content = file_stream.read()
            print("---")
            print(original_content, end="")
            print("---")
        finally:
            file_stream.close()
            print(f"File '{filename}' closed.")
    except OSError as error:
        print(f"Error opening file '{filename}': {error}")
        return

    # Step 2: Transform the data
    print("Transform data:")
    print("---")

    # Split the content into lines, append '#' to non-empty elements, and rejoin
    # splitlines() handles various newline characters (\n, \r\n) cleanly
    lines: List[str] = original_content.splitlines()
    transformed_lines: List[str] = [f"{line}#" for line in lines]
    transformed_content: str = "\n".join(transformed_lines) + "\n"

    print(transformed_content, end="")
    print("---")

    # Step 3: Prompt for user input
    # input() always returns a string (empty string if they just press Enter)
    destination: str = input("Enter new file name (or empty): ").strip()

    if not destination:
        print("Not saving data.")
        return

    # Step 4: Write to the new archive file
    print(f"Saving data to '{destination}'")
    try:
        # 'w' mode creates the file or overwrites it if it exists
        out_stream = open(destination, "w")
        try:
            out_stream.write(transformed_content)
        finally:
            out_stream.close()
        print(f"Data saved in file '{destination}'.")
    except OSError as error:
        print(f"Error saving file '{destination}': {error}")


if __name__ == "__main__":
    process_and_save_archive(sys.argv)
