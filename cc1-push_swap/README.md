*This project has been created as part of the 42 curriculum by `<login1>`, `<login2>`.*

# push_swap

## Description

`push_swap` is a C program that sorts a list of integers using only a small,
fixed set of stack operations. It receives the integers as command-line
arguments, builds **stack `a`**, and writes to **stdout** the exact sequence of
operations that sorts `a` in ascending order (smallest value on top). A second
stack `b` is used as scratch space.

The binary embeds **four sorting strategies** selectable at runtime and an
**adaptive** default that chooses a strategy from a *disorder* metric computed
on the input before any move is made. Both stacks are **doubly linked lists**,
which gives O(1) reverse rotations via a `bottom` pointer.

No `libft` and no `printf` are used: every byte of output and every error is
produced through tiny `write()`-based helpers. The project is **Norm v4**
compliant and leak-free.

## Instructions

### Compilation

```bash
make            # build ./push_swap
make clean      # remove object files
make fclean     # remove objects + binary
make re         # rebuild from scratch
```

Compiled with `cc -Wall -Wextra -Werror`. No relink on a second `make`.

### Execution

```bash
./push_swap [FLAG] <int> <int> ...
```

- Integers are passed as separate arguments (e.g. `./push_swap 3 1 2`) and must
  be unique, valid 32-bit signed integers.
- With no integers, the program prints nothing and exits `0`.
- On invalid input (non-integer, overflow, duplicate, unknown flag) it prints
  `Error\n` to **stderr** and exits `1`.

### Flags

| Flag | Strategy | Complexity (operation model) |
|---|---|---|
| `--simple` | Selection sort | O(n²) |
| `--medium` | Chunk sort | O(n√n) |
| `--complex` | LSD radix sort on ranks | O(n log n) |
| `--adaptive` | Auto (default) | regime-dependent |
| `--bench` | Print metrics to **stderr** after sorting | — |

Flags may be combined, e.g. `./push_swap --complex --bench 5 4 3 2 1`.

Example:

```bash
./push_swap --bench $(shuf -i 0-999999 -n 100 | tr '\n' ' ') 1>/dev/null
```

```text
[bench] disorder: 49.40%
[bench] strategy: medium (O(n sqrt n))
[bench] total ops: 762
[bench] sa:0 sb:0 ss:0 pa:100 pb:100 ra:360 rb:0 rr:0 rra:0 rrb:102 rrr:0
```

(Operations alone go to stdout; `--bench` metrics go only to stderr.)

## Algorithms & Justification

### Data structure

Each stack is a doubly linked list with `top`, `bottom`, and `size`:

```c
typedef struct s_node { int value; struct s_node *prev; struct s_node *next; } t_node;
typedef struct s_stack { t_node *top; t_node *bottom; int size; } t_stack;
```

Push/pop happen at `top`; the `bottom` pointer makes `rra`/`rrb` O(1) (no full
traversal needed). All eleven operations move existing nodes between stacks —
no per-operation `malloc` — so the only allocations are the input nodes and the
temporary array snapshots used for the disorder metric and rank compression.

### Disorder metric

Before any operation, `compute_disorder` takes an array snapshot of `a` and
counts **inversions** — pairs `(i, j)`, `i < j`, with `a[i] > a[j]`:

```
disorder_permille = inversions * 1000 / (n * (n - 1) / 2)    -> 0..1000
```

It is stored as an **integer permille** to avoid floating point (the subject's
`[0,1]` value is just `permille/1000`). `n <= 1` yields `0`. The snapshot array
is freed immediately. This is the worst-case-O(n²) inversion count, which is
cheap for the benchmark sizes (≤ 500).

### Simple — selection sort, O(n²) (`--simple`)

Repeatedly find the minimum in `a`, rotate it to the top using the cheaper of
`ra`/`rra`, and `pb` it. Once 3 elements remain, `sort_3` handles them with a
hard-coded optimal sequence; `sort_2` handles 2. Finally `pa_all` pushes
everything back from `b`. Best for nearly-sorted, small inputs.

### Medium — chunk sort, O(n√n) (`--medium`)

Values are **rank-compressed** (each value replaced by its 0-based rank), then
pushed into `b` in ascending rank ranges (chunks). When a node's rank falls in
the current chunk window it is pushed (`pb`, with an occasional `rb` to keep `b`
roughly ordered); otherwise `ra` skips it. After every element is in `b`, they
are pulled back by repeatedly rotating the current maximum of `b` to the top and
`pa`-ing it, yielding ascending order in `a`. The chunk count scales with input
size, giving the characteristic O(n√n) behaviour.

### Complex — LSD radix sort on ranks, O(n log n) (`--complex`)

Values are rank-compressed to `0..n-1`. For each bit from least to most
significant (`max_bits = ceil(log2(n))` passes), one pass scans the current `a`:
nodes whose current bit is `0` are pushed to `b` (`pb`), the rest are rotated
(`ra`); then all of `b` is pushed back (`pa_all`). Because ranks are a dense
`0..n-1` permutation, `ceil(log2 n)` passes fully sort the stack. Each pass is
~1.5n operations, so the total is ~1.5·n·log₂(n) — the most scalable strategy.

### Adaptive (default)

`pick_strategy` routes by the disorder permille (forced flags bypass this):

| Disorder | Permille | Strategy |
|---|---|---|
| `< 0.2` | `< 200` | simple (O(n²)) |
| `0.2 ≤ x < 0.5` | `200–499` | medium (O(n√n)) |
| `≥ 0.5` | `≥ 500` | complex (O(n log n)) |

Nearly-sorted inputs get the cheap selection sort; heavily shuffled inputs
(uniform random tends toward ~50% disorder) get radix.

### Measured performance

| Input | Budget (pass) | Typical adaptive result |
|---|---|---|
| 100 random | < 2000 ops | ~700–1100 ops |
| 500 random | < 12000 ops | ~6300–6800 ops |

Both comfortably reach the *good* tier.

## File layout

16 `.c` files + 1 header, each file ≤ 5 functions and each function ≤ 25 lines
(Norm v4). The plan's three operation files and `parse`/`strategy` modules were
split (`ops_push.c`, `ops_rrotate.c`, `parse2.c`, `strategy2.c`) strictly to
stay under the 5-functions-per-file cap, as the plan's "When to Split a File"
section allows.

| File | Role |
|---|---|
| `main.c` | entry, context init, orchestration, cleanup, `is_sorted` |
| `utils.c` | `write()`-based output (`put_char/str/nbr/uint/error`) |
| `parse.c` / `parse2.c` | argument validation, flag parsing, stack build |
| `stack.c` | doubly linked list core |
| `ops_swap.c` / `ops_push.c` / `ops_rotate.c` / `ops_rrotate.c` | the 11 operations |
| `ops_utils.c` | min/max position, rotate-to-top helpers |
| `disorder.c` | inversion-count disorder metric |
| `sort_simple.c` / `sort_medium.c` / `sort_complex.c` | the three sorters |
| `strategy.c` / `strategy2.c` | dispatch, adaptive routing, `--bench` output |

## Resources

- 42 subject: *push_swap* v1.1 (mandatory part).
- Radix-sort-for-push_swap technique (rank compression + bitwise passes), a
  well-known community approach.
- Inversion count as a sortedness measure (Kendall tau distance).

### Use of AI

An AI assistant (Cursor) was used to scaffold the repository against the project
plan: generating the Norm-compliant file/function split, the boilerplate for the
11 operations and the `write()` helpers, the test scripts, and this README. The
sorting algorithms, the adaptive thresholds, and the doubly-linked-list design
were specified in `PROJECT_PLAN.md` and implemented accordingly. All output was
reviewed, compiled, norm-checked, valgrind-tested, and benchmarked.

## Contributions

- `<login1>`: Makefile, `utils.c`, `main.c`, `stack.c`, operation files.
- `<login2>`: `parse.c`, `disorder.c`, `strategy.c`, the three sorters.
- Both: `sort_complex.c` + adaptive wiring, Norm audit, README, valgrind scripts.

> No `libft`, no `printf`: all I/O is done with `write()` only.
