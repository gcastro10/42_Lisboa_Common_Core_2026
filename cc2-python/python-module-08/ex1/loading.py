import importlib
import sys


PACKAGES: tuple[tuple[str, str], ...] = (
    ("pandas", "Data manipulation"),
    ("numpy", "Numerical computation"),
    ("matplotlib", "Visualization"),
)


class _PngSink:
    """Collect a complete PNG before anything is written to disk."""

    def __init__(self) -> None:
        """Start with an empty buffer."""
        self._chunks: list[bytes] = []

    def write(self, data: object) -> int:
        """Store one chunk from matplotlib."""
        if isinstance(data, str):
            encoded: bytes = data.encode("utf-8")
            self._chunks.append(encoded)
            return len(encoded)
        if isinstance(data, bytes):
            self._chunks.append(data)
            return len(data)
        if isinstance(data, bytearray | memoryview):
            blob: bytes = bytes(data)
            self._chunks.append(blob)
            return len(blob)
        raise TypeError("Unexpected plot data")

    def flush(self) -> None:
        """Satisfy file-like writers."""
        return None

    def seek(self, offset: int, whence: int = 0) -> int:
        """Ignore seeks; the image is kept in memory."""
        del offset, whence
        return 0

    def tell(self) -> int:
        """Return how many bytes are buffered."""
        return sum(len(chunk) for chunk in self._chunks)

    def close(self) -> None:
        """Satisfy file-like writers."""
        return None

    def payload(self) -> bytes:
        """Return the full PNG."""
        return b"".join(self._chunks)


def invoke(func: object, *args: object, **kwargs: object) -> object:
    """Call a function loaded at runtime."""
    if not callable(func):
        raise TypeError("Expected a callable object")
    return func(*args, **kwargs)


def package_version(name: str) -> str:
    """Return the installed distribution version."""
    metadata: object = importlib.import_module("importlib.metadata")
    version_fn: object = getattr(metadata, "version")
    return str(invoke(version_fn, name))


def print_install_help() -> None:
    """Show both install paths from the subject."""
    print("Install missing programs with pip:")
    print("pip install -r requirements.txt")
    print("Install missing programs with Poetry:")
    print("poetry install")
    print("poetry run python loading.py")


def print_manager_difference() -> None:
    """Show how pip and Poetry install the same programs."""
    print("Dependency managers:")
    print(f"pip: installs requirements.txt into {sys.executable}")
    print(
        "Poetry: installs pyproject.toml into its own "
        "environment via poetry run"
    )


def compare_package_managers(
    show_difference: bool = False,
) -> dict[str, object] | None:
    """Print versions, or the pip versus Poetry note."""
    if show_difference:
        print_manager_difference()
        return None
    loaded: dict[str, object] = {}
    missing: bool = False
    for name, role in PACKAGES:
        try:
            module: object = importlib.import_module(name)
        except ImportError:
            print(f"[MISSING] {name} - {role} unavailable")
            missing = True
            continue
        version: str = package_version(name)
        print(f"[OK] {name} ({version}) - {role} ready")
        loaded[name] = module
    if missing:
        print_install_help()
        return None
    return loaded


def render_plot(
    numpy_mod: object,
    pandas_mod: object,
    matplotlib_mod: object,
) -> None:
    """Build 1000 numpy points and save one pandas plot."""
    invoke(getattr(matplotlib_mod, "use"), "Agg")
    pyplot: object = importlib.import_module("matplotlib.pyplot")
    random_ns: object = getattr(numpy_mod, "random")
    generator: object = invoke(getattr(random_ns, "default_rng"))
    values: object = invoke(getattr(generator, "normal"), size=1000)
    frame: object = invoke(
        getattr(pandas_mod, "DataFrame"),
        {"signal": values},
    )
    series: object = invoke(getattr(getattr(frame, "signal"), "cumsum"))
    invoke(getattr(series, "plot"))
    sink: _PngSink = _PngSink()
    invoke(getattr(pyplot, "savefig"), sink, format="png")
    payload: bytes = sink.payload()
    if not payload:
        raise RuntimeError("Visualization was empty")
    with open("matrix_analysis.png", "wb") as image:
        image.write(payload)
    invoke(getattr(pyplot, "close"))


def main() -> None:
    """Check dependencies, then analyze simulated Matrix data."""
    try:
        print("LOADING STATUS: Loading programs...")
        print("Checking dependencies:")
        loaded: dict[str, object] | None = compare_package_managers()
        if loaded is None:
            return
        print("Analyzing Matrix data...")
        print("Processing 1000 data points...")
        print("Generating visualization...")
        render_plot(loaded["numpy"], loaded["pandas"], loaded["matplotlib"])
        print("Analysis complete!")
        print("Results saved to: matrix_analysis.png")
        compare_package_managers(show_difference=True)
    except Exception as error:
        print(f"Error: {error}")


if __name__ == "__main__":
    main()
