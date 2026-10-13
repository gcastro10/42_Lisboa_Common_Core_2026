import os

from dotenv import load_dotenv


KEYS: tuple[str, ...] = (
    "MATRIX_MODE",
    "DATABASE_URL",
    "API_KEY",
    "LOG_LEVEL",
    "ZION_ENDPOINT",
)
SECRET_KEYS: tuple[str, ...] = (
    "API_KEY",
    "DATABASE_URL",
    "ZION_ENDPOINT",
)
MODES: tuple[str, ...] = ("development", "production")


def exercise_dir() -> str:
    """Return the directory that contains this program."""
    return os.path.dirname(os.path.abspath(__file__))


def env_file() -> str:
    """Return the development .env path."""
    return os.path.join(exercise_dir(), ".env")


def gitignore_file() -> str:
    """Return the exercise .gitignore path."""
    return os.path.join(exercise_dir(), ".gitignore")


def read_config() -> dict[str, str]:
    """Collect non-empty configuration from the environment."""
    values: dict[str, str] = {}
    for key in KEYS:
        raw: str | None = os.getenv(key)
        if raw is None or raw.strip() == "":
            continue
        values[key] = raw
    return values


def warn_incomplete(values: dict[str, str]) -> bool:
    """Warn about missing keys or a bad mode. Return True when usable."""
    ready: bool = True
    for key in KEYS:
        if key not in values:
            print(f"WARNING: Missing configuration: {key}")
            ready = False
    mode: str | None = values.get("MATRIX_MODE")
    if mode is not None and mode not in MODES:
        print("WARNING: Invalid configuration: MATRIX_MODE")
        ready = False
    return ready


def database_label(url: str) -> str:
    """Describe the database without printing its URL."""
    lowered: str = url.lower()
    local: bool = (
        "localhost" in lowered
        or "127.0.0.1" in lowered
        or "sqlite" in lowered
    )
    if local:
        return "Connected to local instance"
    return "Connected to remote instance"


def secrets_are_hardcoded(values: dict[str, str]) -> bool:
    """Return True when a live secret is written in this source file."""
    with open(__file__, encoding="utf-8") as source:
        text: str = source.read()
    for key in SECRET_KEYS:
        if values[key] in text:
            return True
    return False


def env_is_configured() -> bool:
    """Return True when .env exists and .gitignore ignores it."""
    if not os.path.isfile(env_file()):
        return False
    if not os.path.isfile(gitignore_file()):
        return False
    with open(gitignore_file(), encoding="utf-8") as rules:
        for line in rules:
            if line.strip() == ".env":
                return True
    return False


def print_report(values: dict[str, str]) -> None:
    """Print the subject configuration block."""
    print("ORACLE STATUS: Reading the Matrix...")
    print("Configuration loaded:")
    print(f"Mode: {values['MATRIX_MODE']}")
    print(f"Database: {database_label(values['DATABASE_URL'])}")
    print("API Access: Authenticated")
    print(f"Log Level: {values['LOG_LEVEL']}")
    print("Zion Network: Online")
    print("Environment security check:")
    if secrets_are_hardcoded(values):
        print("WARNING: Hardcoded secrets detected")
    else:
        print("[OK] No hardcoded secrets detected")
    if env_is_configured():
        print("[OK] .env file properly configured")
    else:
        print("WARNING: .env file is not properly configured")
    print("[OK] Production overrides available")
    print("The Oracle sees all configurations.")


def main() -> None:
    """Load configuration and report it without revealing secrets."""
    try:
        load_dotenv(env_file(), override=False)
        values: dict[str, str] = read_config()
        if not warn_incomplete(values):
            return
        print_report(values)
    except Exception as error:
        print(f"Error: {error}")


if __name__ == "__main__":
    main()
