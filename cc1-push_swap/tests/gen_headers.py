#!/usr/bin/env python3
# Tooling helper (NOT submitted): prepend a canonical 42 header to each
# .c/.h source file if it does not already start with one.
import os
import sys

LOGIN = "gonca"
EMAIL = "gonca@student.42.fr"
DATE = "2026/06/03 21:25:00"

ART = [
    "        :::      ::::::::",
    "      :+:      :+:    :+:",
    "    +:+ +:+         +:+  ",
    "  +#+  +:+       +#+     ",
    "+#+#+#+#+#+   +#+        ",
    "     #+#    #+#          ",
    "    ###   ########.fr    ",
]


def border():
    return "/* " + "*" * 74 + " */"


def content(left, art):
    inner = 80 - len("/*   ") - len("*/")
    body = left + " " * (inner - len(art) - len(left)) + art
    line = "/*   " + body + "*/"
    assert len(line) == 80, "len=%d: %r" % (len(line), line)
    return line


def header(filename):
    lines = [border()]
    lines.append(content("", " " * 24))
    lines.append(content("", ART[0]))
    lines.append(content(filename, ART[1]))
    lines.append(content("", ART[2]))
    lines.append(content("By: %s <%s>" % (LOGIN, EMAIL), ART[3]))
    lines.append(content("", ART[4]))
    lines.append(content("Created: %s by %s" % (DATE, LOGIN), ART[5]))
    lines.append(content("Updated: %s by %s" % (DATE, LOGIN), ART[6]))
    lines.append(content("", " " * 24))
    lines.append(border())
    return "\n".join(lines) + "\n"


def main():
    for path in sys.argv[1:]:
        with open(path) as f:
            data = f.read()
        if data.startswith("/* *****"):
            continue
        name = os.path.basename(path)
        out = header(name) + data
        with open(path, "w") as f:
            f.write(out)
        print("header added: %s" % path)


if __name__ == "__main__":
    main()
