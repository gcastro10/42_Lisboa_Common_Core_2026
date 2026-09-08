from abc import ABC, abstractmethod
from typing import Any
import typing

class DataProcessor(ABC):
    """Abstract processor that validates, stores, and outputs data."""

    def __init__(self, name: str) -> None:
        """Initialize storage, ranking, and display name."""
        self._name: str = name
        self._items: list[tuple[int, str]] = []
        self._next_rank: int = 0
        self._total_processed: int = 0

    @property
    def name(self) -> str:
        """Return the human-readable processor name."""
        return self._name

    @property
    def total_processed(self) -> int:
        """Return how many items were ingested over the lifetime."""
        return self._total_processed

    @property
    def remaining(self) -> int:
        """Return how many ingested items are still waiting for output."""
        return len(self._items)

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Return True if data can be ingested by this processor."""

    @abstractmethod
    def ingest(self, data: Any) -> None:
        """Process and store input data, or raise if it is invalid."""

    def output(self) -> tuple[int, str]:
        """Extract the oldest stored item and its processing rank."""
        if not self._items:
            raise IndexError("No data remaining on processor")
        return self._items.pop(0)

    def _store(self, value: str) -> None:
        """Append a converted item and assign the next processing rank."""
        self._items.append((self._next_rank, value))
        self._next_rank += 1
        self._total_processed += 1


class NumericProcessor(DataProcessor):
    """Processor for ints, floats, and lists of those numbers."""

    def __init__(self) -> None:
        """Create a numeric processor with an empty FIFO store."""
        super().__init__("Numeric Processor")

    @staticmethod
    def _is_number(value: Any) -> bool:
        """Return True for int or float, excluding bool."""
        return type(value) in (int, float)

    def validate(self, data: Any) -> bool:
        """Accept a number or a non-empty list of numbers."""
        if self._is_number(data):
            return True
        if type(data) is list and len(data) > 0:
            return all(self._is_number(item) for item in data)
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        """Convert numeric values to strings and store each item."""
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, list):
            for item in data:
                self._store(str(item))
        else:
            self._store(str(data))


class TextProcessor(DataProcessor):
    """Processor for strings and lists of strings."""

    def __init__(self) -> None:
        """Create a text processor with an empty FIFO store."""
        super().__init__("Text Processor")

    def validate(self, data: Any) -> bool:
        """Accept a string or a non-empty list of strings."""
        if type(data) is str:
            return True
        if type(data) is list and len(data) > 0:
            return all(type(item) is str for item in data)
        return False

    def ingest(self, data: str | list[str]) -> None:
        """Store each text item without extra conversion."""
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, list):
            for item in data:
                self._store(item)
        else:
            self._store(data)


class LogProcessor(DataProcessor):
    """Processor for log dicts and lists of log dicts."""

    def __init__(self) -> None:
        """Create a log processor with an empty FIFO store."""
        super().__init__("Log Processor")

    @staticmethod
    def _is_log_entry(value: Any) -> bool:
        """Return True for a string dict with log_level and log_message."""
        if type(value) is not dict:
            return False
        if "log_level" not in value or "log_message" not in value:
            return False
        for key, val in value.items():
            if type(key) is not str or type(val) is not str:
                return False
        return True

    def validate(self, data: Any) -> bool:
        """Accept one log dict or a non-empty list of log dicts."""
        if self._is_log_entry(data):
            return True
        if type(data) is list and len(data) > 0:
            return all(self._is_log_entry(item) for item in data)
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        """Convert log dicts to 'LEVEL: message' strings and store them."""
        if not self.validate(data):
            raise ValueError("Improper log data")
        entries: list[dict[str, str]]
        if isinstance(data, list):
            entries = data
        else:
            entries = [data]
        for entry in entries:
            formatted: str = (
                f"{entry['log_level']}: {entry['log_message']}"
            )
            self._store(formatted)


class DataStream:
    """Routes mixed stream elements to registered processors."""

    def __init__(self) -> None:
        """Start with no registered processors."""
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        """Register a processor used to handle matching stream elements."""
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        """Send each element to the first processor that validates it."""
        for element in stream:
            handled: bool = False
            for proc in self._processors:
                if proc.validate(element):
                    proc.ingest(element)
                    handled = True
                    break
            if not handled:
                print(
                    "DataStream error - Can't process element in stream: "
                    f"{element}"
                )

    def print_processors_stats(self) -> None:
        """Print totals and remaining items for every processor."""
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
            return
        for proc in self._processors:
            print(
                f"{proc.name}: total {proc.total_processed} items "
                f"processed, remaining {proc.remaining} on processor"
            )


def _sample_batch() -> list[Any]:
    """Return the mixed stream used by the subject example."""
    return [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {
                "log_level": "WARNING",
                "log_message": "Telnet access! Use ssh instead",
            },
            {
                "log_level": "INFO",
                "log_message": "User wil is connected",
            },
        ],
        42,
        ["Hi", "five"],
    ]


def main() -> None:
    """Run the Code Nexus data stream demonstration."""
    print("=== Code Nexus - Data Stream ===")
    print("Initialize Data Stream...")
    stream: DataStream = DataStream()
    stream.print_processors_stats()

    numeric: NumericProcessor = NumericProcessor()
    print("Registering Numeric Processor")
    stream.register_processor(numeric)

    batch: list[Any] = _sample_batch()
    print(f"Send first batch of data on stream: {batch}")
    stream.process_stream(batch)
    stream.print_processors_stats()

    text: TextProcessor = TextProcessor()
    log: LogProcessor = LogProcessor()
    print("Registering other data processors")
    stream.register_processor(text)
    stream.register_processor(log)
    print("Send the same batch again")
    stream.process_stream(batch)
    stream.print_processors_stats()

    print(
        "Consume some elements from the data processors: "
        "Numeric 3, Text 2, Log 1"
    )
    for _ in range(3):
        numeric.output()
    for _ in range(2):
        text.output()
    log.output()
    stream.print_processors_stats()


if __name__ == "__main__":
    main()
