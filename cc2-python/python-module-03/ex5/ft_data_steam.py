import random
from typing import Generator

# Configuration pools for random generation
PLAYERS: list[str] = ["alice", "bob", "charlie", "dylan"]
ACTIONS: list[str] = [
    "run",
    "eat",
    "sleep",
    "grab",
    "move",
    "climb",
    "swim",
    "use",
    "release",
]


def gen_event() -> Generator[tuple[str, str], None, None]:
    """Generate an infinite sequence of random player action events.

    Yields:
        tuple[str, str]: A tuple containing (player_name, action).
    """
    while True:
        player: str = random.choice(PLAYERS)
        action: str = random.choice(ACTIONS)
        yield (player, action)


def consume_event(
    event_list: list[tuple[str, str]],
) -> Generator[tuple[str, str], None, None]:
    """Destructively consume items randomly from the given list until empty.

    Yields:
        tuple[str, str]: An event extracted from the input list.
    """
    while event_list:
        # Pick a random valid index remaining in the list
        idx: int = random.randint(0, len(event_list) - 1)
        # .pop(idx) removes and returns the item at that index
        event: tuple[str, str] = event_list.pop(idx)
        yield event


def main() -> None:
    """Run the stream generation and consumption simulation loop."""
    print("=== Game Data Stream Processor ===")

    # Instantiate our infinite generator state
    stream: Generator[tuple[str, str], None, None] = gen_event()

    # 1. Pull 1000 items from the infinite stream using next()
    for i in range(1000):
        # next() asks the generator state to run until its next yield statement
        player, action = next(stream)
        # Using conditional trick to mimic the truncated output pattern nicely
        if i < 15 or i >= 992:
            print(f"Event {i}: Player {player} did action {action}")
        elif i == 15:
            print("[...]")

    # 2. Build a fresh list of exactly 10 tuples from the stream
    events_buffer: list[tuple[str, str]] = [next(stream) for _ in range(10)]
    print(f"Built list of 10 events: {events_buffer}")

    # 3. Consume the list using our consume_event consumer generator
    # Used directly in the for .. in .. loop structure
    for consumed in consume_event(events_buffer):
        print(f"Got event from list: {consumed}")
        print(f"Remains in list: {events_buffer}")


if __name__ == "__main__":
    main()
