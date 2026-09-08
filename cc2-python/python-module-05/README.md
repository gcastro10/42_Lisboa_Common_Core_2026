# Python Module 05 — Polymorphic Data Streams

**Code Nexus** — abstract classes, method overriding, subtype
polymorphism, and duck-typed export plugins.

This README is written for evaluation: what each file does, which
concepts it proves, how to run it, and how to answer typical defense
questions.

---

## Files to submit

The subject only requires the exercise files. This README is extra
study/evaluation material.

```text
python-module-05/
├── ex0/data_processor.py   # abstract processors + FIFO output
├── ex1/data_stream.py      # polymorphic routing + statistics
├── ex2/data_pipeline.py    # Protocol export plugins + pipeline
└── README.md
```

Each exercise is **self-contained**. Later files copy earlier classes
and extend them. Do not import from another `ex*` folder.

---

## General instructions (from the subject)

- **Python 3.10+**
- **flake8** coding standard
- **Comprehensive type annotations**, checked with **mypy**
- Exception handling must protect streams from corruption
- **Authorized imports:** `abc` and `typing` only
- Standard types and their methods are allowed (`int`, `str`, `list`,
  `dict`, …)
- All built-in functions are allowed
- No `json`, `csv`, or `collections` imports

---

## Concepts you must be able to explain

### Abstract Base Class (`ABC`)

`DataProcessor` inherits from `ABC`. It defines the **common
interface** every specialized processor must implement:

- `validate(self, data: Any) -> bool` — abstract
- `ingest(self, data: Any) -> None` — abstract
- `output(self) -> tuple[int, str]` — concrete, shared by everyone

`@abstractmethod` means you **cannot instantiate** `DataProcessor`
directly. `NumericProcessor()`, `TextProcessor()`, and
`LogProcessor()` work because they override the abstract methods.

This is the contract: “I do not know *which* processor I have, but I
know it can validate, ingest, and output.”

### Method overriding

Each subclass **replaces** `validate` and `ingest` with behavior that
fits its data:

| Processor           | Valid input                                      | Stored form                         |
| ------------------- | ------------------------------------------------ | ----------------------------------- |
| `NumericProcessor`  | `int`, `float`, non-empty list of those          | `str(number)`                       |
| `TextProcessor`     | `str`, non-empty list of `str`                   | the string itself                   |
| `LogProcessor`      | `dict[str, str]` with `log_level`/`log_message`, or a list of those | `"LEVEL: message"` |

`output` is **not** overridden. All processors share the same FIFO
extraction logic. That is inheritance used for **code reuse**, while
overriding is used for **behavioral specialization**.

### Why `validate` stays `Any` but `ingest` narrows

The subject is explicit:

- `validate` cannot know what the stream will send, so every override
  keeps `validate(self, data: Any) -> bool`.
- `ingest` **must** advertise the types it really accepts, for
  example `int | float | list[int | float]`.

Runtime still has to be defensive: `ingest` calls `validate` and
raises if the caller skipped the check.

### The intentional mypy warning

Exercise 0 calls `numeric.ingest("foo")` **without** validating first.
That is invalid for `NumericProcessor`, so:

1. **Runtime:** `ValueError("Improper numeric data")`
2. **mypy:** argument type `str` is incompatible with
   `int | float | list[int | float]`

The subject says this mypy diagnostic is **on purpose**. Do not hide
it with `# type: ignore`.

### Subtype polymorphism

`DataStream` stores `list[DataProcessor]`. It never mentions
`NumericProcessor` inside `process_stream`. It only calls:

```text
proc.validate(element)
proc.ingest(element)
```

Python dispatches those calls to the **real class** of `proc`. That is
subtype polymorphism: one interface, many implementations.

### FIFO ranks

Each ingested **item** (not each stream element) gets a rank `0, 1, 2,
…` that never resets.

- Ingesting `[3.14, -1, 2.71]` stores **three** items.
- Ingesting `42` stores **one** more item (rank `3` if it follows that
  list).
- `output()` returns `(rank, value)` and **removes** the oldest item.

Ranks are what the JSON plugin uses for keys (`item_3`, `item_4`, …).

### `Protocol` and duck typing (Exercise 2)

`ExportPlugin` inherits from `typing.Protocol` and declares:

```python
def process_output(self, data: list[tuple[int, str]]) -> None:
```

`CSVExportPlugin` and `JSONExportPlugin` **do not inherit** from
`ExportPlugin`. They are compatible because they implement the same
method. That is duck typing: “if it has `process_output`, it is an
export plugin.”

`ABC` is for the processors (you **must** inherit and override).
`Protocol` is for plugins (any matching object is accepted).

---

## Exercise 0 — Data Processor

**File:** `ex0/data_processor.py`

### What it builds

The foundation of the Nexus:

- Abstract `DataProcessor`
- `NumericProcessor`, `TextProcessor`, `LogProcessor`
- Internal FIFO of `(rank, str)`
- `output()` pops the oldest pair

### Validation rules (important details)

- Numbers use `type(value) in (int, float)` so **`bool` is rejected**
  (`True` is a subclass of `int` in Python).
- Empty lists are invalid for **every** processor. Otherwise `[]`
  would match numeric, text, and log, and routing in Exercise 1 would
  be ambiguous.
- A log dict must be `str → str` and include `log_level` and
  `log_message`.

### Invalid ingest

If `ingest` is called with data that fails `validate`, it raises
`ValueError` (`Improper numeric data`, `Improper text data`,
`Improper log data`). Empty `output()` raises `IndexError`.

### How to run

```bash
python3 ex0/data_processor.py
```

The demo:

1. Validates `42` (True) and `"Hello"` (False) on numeric
2. Ingests `"foo"` without validation → exception
3. Ingests `[1, 2, 3, 4, 5]`, extracts 3 values (ranks `0, 1, 2`)
4. Validates `42` on text (False), ingests three words, extracts one
5. Validates `"Hello"` on log (False), ingests two log dicts, extracts
   both as `NOTICE: …` / `ERROR: …`

---

## Exercise 1 — Polymorphic Data Stream

**File:** `ex1/data_stream.py`

### What it adds

`DataStream`:

- `register_processor(proc)` — append a processor
- `process_stream(stream)` — for each element, use the **first**
  registered processor whose `validate` returns `True`
- `print_processors_stats()` — totals and remaining counts

If no processor matches:

```text
DataStream error - Can't process element in stream: Hello world
```

Stats format:

```text
== DataStream statistics ==
Numeric Processor: total 4 items processed, remaining 4 on processor
```

With zero processors: `No processor found, no data`.

### Routing vs splitting

A **stream element** is routed as a whole:

- `'Hello world'` → TextProcessor → **1** stored item
- `[3.14, -1, 2.71]` → NumericProcessor → **3** stored items
- `[{...}, {...}]` → LogProcessor → **2** stored items
- `42` → NumericProcessor → **1** stored item
- `['Hi', 'five']` → TextProcessor → **2** stored items

That is why the first full batch reports numeric `4`, text `3`, log
`2`.

### Demo story (matches the subject)

1. Empty stream → no processor
2. Register **only** NumericProcessor, send a mixed batch
   - numbers are ingested
   - text and logs print DataStream errors
3. Register Text and Log, send the **same** batch again
   - numeric total becomes `8` (second copy of the numbers)
   - text `3`, log `2`
4. Consume Numeric 3, Text 2, Log 1 via `output()`
   - remaining `5`, `1`, `1`

### How to run

```bash
python3 ex1/data_stream.py
```

---

## Exercise 2 — Data Pipeline

**File:** `ex2/data_pipeline.py`

### What it adds

After `process_stream` has filled the processors, the **output** side
of the pipeline is a plugin:

- `ExportPlugin(Protocol)` with `process_output`
- `CSVExportPlugin` — join values with commas (no `csv` module)
- `JSONExportPlugin` — build `{"item_<rank>": "<value>", ...}` by
  hand (no `json` module)
- `DataStream.output_pipeline(nb, plugin)` — from **each** processor,
  consume up to `nb` remaining items and pass that list to the plugin

CSV uses values only:

```text
CSV Output:
3.14,-1,2.71
```

JSON uses ranks as keys (the rank is **not** the current queue index;
it is the lifetime rank assigned at ingest):

```text
JSON Output:
{"item_3": "42", "item_4": "21", "item_5": "32", "item_6": "42", "item_7": "64"}
```

After the first batch, numeric ranks `0,1,2,3` are `3.14`, `-1`,
`2.71`, `42`. CSV consumes 3, so JSON later starts at `item_3`.

### Demo story

1. Register all three processors, send the first mixed batch
2. CSV export of 3 items per processor
3. Second batch (`21`, text list, log list, more numbers,
   `"World hello"`)
4. JSON export of 5 items per processor (or fewer if the queue is
   shorter)

### How to run

```bash
python3 ex2/data_pipeline.py
```

---

## Evaluation questions (and answers)

### How does polymorphism let `DataStream` handle unknown types?

`DataStream` does not switch on `type(element)` and does not import
concrete processors inside `process_stream`. It only knows the
**abstract** `DataProcessor` interface.

For each element it asks every registered processor, in order:
“does `validate` accept this?” The first `True` gets `ingest`.
Python then runs **that subclass’s** `ingest` (numeric conversion,
text storage, or log formatting).

New data types do not require editing `DataStream`. You write a new
subclass, override `validate`/`ingest`, and `register_processor` it.

### What are the benefits of this design?

- **Open for extension:** add `ImageProcessor` without rewriting the
  stream loop.
- **Closed for modification:** routing stays one loop.
- **Shared behavior:** FIFO ranks and `output()` live in the base
  class once.
- **Safe ingestion:** `validate` is the gate; `ingest` still raises
  if someone bypasses it.
- **Plugins stay independent:** CSV/JSON (or a future XML exporter)
  only need `process_output`. The pipeline does not inherit from them.

### Why not put type checks inside `DataStream`?

That would couple the stream to every known type and force a code
change for each new processor. Polymorphism moves the type knowledge
**into the processors**, which is the whole point of the module.

### `ABC` vs `Protocol` — when do you use each?

- **ABC / inheritance:** you own the hierarchy and want a forced
  contract (`DataProcessor`). Instantiating the base class must be
  impossible until methods are implemented.
- **Protocol / duck typing:** you want **compatibility without
  inheritance** (`ExportPlugin`). A plugin written by someone else
  should work if the method exists.

### How would you add a new data type during the defense?

Example: `BoolProcessor`:

1. Subclass `DataProcessor`
2. `validate`: `type(data) is bool` or a non-empty list of bools
3. `ingest(self, data: bool | list[bool]) -> None`
4. Store `"True"` / `"False"` via `_store`
5. `stream.register_processor(BoolProcessor())`

No change to `process_stream` or `output_pipeline`.

### How would you add a new export plugin?

Write a class with:

```python
def process_output(self, data: list[tuple[int, str]]) -> None:
```

Pass an instance to `output_pipeline`. Do **not** inherit from
`ExportPlugin` unless you want to; duck typing is enough.

---

## Checks (style and types)

```bash
# demos (output should match the subject examples)
python3 ex0/data_processor.py
python3 ex1/data_stream.py
python3 ex2/data_pipeline.py

# style
flake8 ex0/data_processor.py ex1/data_stream.py ex2/data_pipeline.py

# types — one expected diagnostic in ex0 (invalid ingest of 'foo')
mypy ex0/data_processor.py ex1/data_stream.py ex2/data_pipeline.py
```

Expected mypy result on Exercise 0:

```text
ex0/data_processor.py:163: error: Argument 1 to "ingest" of
"NumericProcessor" has incompatible type "str"; expected
"int | float | list[int | float]"  [arg-type]
```

`ex1` and `ex2` should be clean under mypy.

---

## Defense checklist

- You can draw the hierarchy: `ABC` → `DataProcessor` → three
  processors.
- You can explain that `output` is inherited, `validate`/`ingest` are
  overridden.
- You can explain FIFO ranks vs remaining count (`total` never
  decreases; `remaining` does).
- You can walk through why only NumericProcessor handles the first
  batch in Exercise 1.
- You can say why plugins use `Protocol` instead of `ABC`.
- You can add a processor or a plugin on paper in a few lines.
- You understand the mypy warning and can justify leaving it in.
