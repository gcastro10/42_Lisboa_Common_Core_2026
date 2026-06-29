import math


def get_player_pos() -> tuple[float, float, float]:
    """Prompt the user for 3D coordinates and validate the input.

    Retries until valid 'x,y,z' floats are provided.
    """
    while True:
        try:
            user_input: str = input(
                "Enter new coordinates as floats in format 'x,y,z': "
            )

            # Split by comma and strip whitespace from each part
            parts: list[str] = [p.strip() for p in user_input.split(",")]

            if len(parts) != 3:
                print("Invalid syntax")
                continue

            # Attempt to convert each component to float
            # If any part fails, it raises a ValueError handled below
            current_part: str = parts[0]
            try:
                current_part = parts[0]
                x: float = float(parts[0])
                current_part = parts[1]
                y: float = float(parts[1])
                current_part = parts[2]
                z: float = float(parts[2])
            except ValueError as val_err:
                # Match the exact exception message format from the prompt
                print(f"Error on parameter '{current_part}': {val_err}")
                continue

            return (x, y, z)

        except (KeyboardInterrupt, EOFError):
            # Gracefully exit if user hits Ctrl+C or Ctrl+D
            print("\nExiting...")
            sys.exit(0)


def main() -> None:
    """Run the 3D game coordinate tracking system program."""
    print("=== Game Coordinate System ===")

    print("Get a first set of coordinates")
    pos1: tuple[float, float, float] = get_player_pos()

    # Tuple unpacking: clean assignment from tuple elements
    x1, y1, z1 = pos1
    print(f"Got a first tuple: {pos1}")
    print(f"It includes: X={x1}, Y={y1}, Z={z1}")

    # Distance to center (0,0,0)
    dist_to_center: float = math.sqrt(x1**2 + y1**2 + z1**2)
    print(f"Distance to center: {round(dist_to_center, 4)}")

    print("Get a second set of coordinates")
    pos2: tuple[float, float, float] = get_player_pos()
    x2, y2, z2 = pos2

    # Euclidean distance between pos1 and pos2
    # The ** operator means exponentiation (like Math.pow() in TS)
    dist_between: float = math.sqrt(
        (x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2
    )
    print(f"Distance between the 2 sets of coordinates: {round(dist_between, 4)}")


if __name__ == "__main__":
    import sys  # Imported here to safely use sys.exit on interruption

    main()
