import os
import site
import sys


def _under_prefix(location: str, prefix: str) -> bool:
    """Return True when location lives inside prefix."""
    prefix_root: str = os.path.normpath(prefix)
    candidate: str = os.path.normpath(location)
    try:
        return os.path.commonpath([candidate, prefix_root]) == prefix_root
    except ValueError:
        return False


def package_path() -> str:
    """Return the site-packages directory of the current prefix."""
    prefix: str = sys.prefix
    fallback: str = (
        f"{prefix}/lib/python{sys.version_info.major}."
        f"{sys.version_info.minor}/site-packages"
    )
    try:
        locations: list[str] = site.getsitepackages()
    except AttributeError:
        return fallback
    for location in locations:
        if _under_prefix(location, prefix):
            return location
    return fallback


def print_outside() -> None:
    """Print the subject sample for a global interpreter."""
    print("MATRIX STATUS: You're still plugged in")
    print(f"Current Python: {sys.executable}")
    print("Virtual Environment: None detected")
    print("WARNING: You're in the global environment!")
    print("The machines can see everything you install.")
    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate # On Unix")
    print("matrix_env\\Scripts\\activate # On Windows")
    print("Then run this program again.")


def print_inside() -> None:
    """Print the subject sample for a virtual environment."""
    name: str = os.path.basename(sys.prefix)
    print("MATRIX STATUS: Welcome to the construct")
    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {name}")
    print(f"Environment Path: {sys.prefix}")
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting")
    print("the global system.")
    print("Package installation path:")
    print(package_path())


def main() -> None:
    """Report whether this interpreter is inside a virtual environment."""
    try:
        # A venv replaces sys.prefix; the base install stays in base_prefix.
        if sys.prefix != sys.base_prefix:
            print_inside()
        else:
            print_outside()
    except Exception as error:
        print(f"Error: {error}")


if __name__ == "__main__":
    main()
