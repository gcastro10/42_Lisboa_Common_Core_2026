#!/usr/bin/env python3
# Local correctness checker (NOT submitted as the project bonus checker).
# Usage: ./push_swap <nums> | python3 checker.py <nums>
# Reads operations from stdin, applies them to stack a (= nums) and b (empty),
# then prints OK if a is ascending and b empty, KO otherwise.
import sys


def apply(op, a, b):
    if op == "sa":
        if len(a) > 1:
            a[0], a[1] = a[1], a[0]
    elif op == "sb":
        if len(b) > 1:
            b[0], b[1] = b[1], b[0]
    elif op == "ss":
        if len(a) > 1:
            a[0], a[1] = a[1], a[0]
        if len(b) > 1:
            b[0], b[1] = b[1], b[0]
    elif op == "pa":
        if b:
            a.insert(0, b.pop(0))
    elif op == "pb":
        if a:
            b.insert(0, a.pop(0))
    elif op == "ra":
        if a:
            a.append(a.pop(0))
    elif op == "rb":
        if b:
            b.append(b.pop(0))
    elif op == "rr":
        if a:
            a.append(a.pop(0))
        if b:
            b.append(b.pop(0))
    elif op == "rra":
        if a:
            a.insert(0, a.pop())
    elif op == "rrb":
        if b:
            b.insert(0, b.pop())
    elif op == "rrr":
        if a:
            a.insert(0, a.pop())
        if b:
            b.insert(0, b.pop())
    else:
        print("Invalid op: %s" % op, file=sys.stderr)
        sys.exit(2)


def main():
    a = [int(x) for x in sys.argv[1:]]
    b = []
    ops = [line.strip() for line in sys.stdin if line.strip()]
    for op in ops:
        apply(op, a, b)
    if a == sorted(a) and not b:
        print("OK (%d ops)" % len(ops))
    else:
        print("KO (%d ops)" % len(ops))
        sys.exit(1)


if __name__ == "__main__":
    main()
