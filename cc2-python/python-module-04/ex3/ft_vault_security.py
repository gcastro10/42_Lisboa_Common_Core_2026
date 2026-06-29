from typing import Tuple, Union


def secure_archive(
    filename: str, action: str = "read", content_to_write: str = ""
) -> Tuple[bool, str]:
    """Safely reads from or writes to a file using context managers.

    Args:
        filename: The path to the file.
        action: Either 'read' or 'write'. Defaults to 'read'.
        content_to_write: The data string to write if action is 'write'.

    Returns:
        A tuple containing a boolean success flag and a string message or file content.
    """
    try:
        if action == "write":
            with open(filename, "w") as file_stream:
                file_stream.write(content_to_write)
            return True, "Content successfully written to file"

        # Default action is read
        with open(filename, "r") as file_stream:
            content: str = file_stream.read()
        return True, content

    except OSError as error:
        # Returns False along with the string representation of the OS error
        return False, str(error)


if __name__ == "__main__":
    print("=== Cyber Archives Security ===")

    print("Using 'secure_archive' to read from a nonexistent file:")
    res1 = secure_archive("/not/existing/file", action="read")
    print(res1)

    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    res2 = secure_archive("/etc/master.passwd", action="read")
    print(res2)

    # Creating a temporary mock file matching your previous exercise to demonstrate success
    mock_filename = "ancient_fragment.txt"
    mock_data = (
        "[FRAGMENT 001] Digital preservation protocols established 2087\n"
        "[FRAGMENT 002] Knowledge must survive the entropy wars\n"
        "[FRAGMENT 003] Every byte saved is a victory against oblivion\n"
    )
    with open(mock_filename, "w") as f:
        f.write(mock_data)

    print("\nUsing 'secure_archive' to read from a regular file:")
    res3 = secure_archive(mock_filename, action="read")
    print(res3)

    print("\nUsing 'secure_archive' to write previous content to a new file:")
    if res3[0]:  # res3[0] contains the boolean flag
        res4 = secure_archive(
            "new_vault_entry.txt", action="write", content_to_write=res3[1]
        )
        print(res4)
