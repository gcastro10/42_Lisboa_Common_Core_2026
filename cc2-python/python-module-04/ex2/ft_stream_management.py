import sys
from typing import List


def process_with_streams(args: List[str]) -> None:
    """Processes file contents and utilizes system streams for input/output."""
    if len(args) != 2:
        print("Usage: ft_stream_management.py <filename>")
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
        # Redirecting error message to sys.stderr with the required prefix
        print(
            f"[STDERR] Error opening file '{filename}': {error}",
            file=sys.stderr,
        )
        return

    # Step 2: Transform the data
    print("Transform data:")
    print("---")
    lines: List[str] = original_content.splitlines()
    transformed_lines: List[str] = [f"{line}#" for line in lines]
    transformed_content: str = "\n".join(transformed_lines) + "\n"
    print(transformed_content, end="")
    print("---")

    # Step 3: Prompt for user input via sys.stdin
    print("Enter new file name (or empty): ", end="")
    sys.stdout.flush()  # Ensure the prompt is visible before blocking for input

    # sys.stdin.readline() retains the trailing newline character '\n'
    user_input: str = sys.stdin.readline()
    destination: str = user_input.strip()

    if not destination:
        print("Not saving data.")
        return

    # Step 4: Write to the new archive file
    print(f"Saving data to '{destination}'")
    try:
        out_stream = open(destination, "w")
        try:
            out_stream.write(transformed_content)
        finally:
            out_stream.close()
        print(f"Data saved in file '{destination}'.")
    except OSError as error:
        print(
            f"[STDERR] Error opening file '{destination}': {error}",
            file=sys.stderr,
        )
        print("Data not saved.")


if __name__ == "__main__":
    process_with_streams(sys.argv)
