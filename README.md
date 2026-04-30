# alx-low_level_programming

**One-line summary:** Collection of low-level C programming exercises and projects completed as part of systems programming practice.

## Overview
This repository contains C projects and exercises focused on pointers, memory management, data structures, and Unix system calls. Projects are organized by topic and include small test harnesses.

## Key features
- Implementations of common C utilities and algorithms
- Emphasis on memory safety and correct resource management
- Small test programs to validate behavior

## How to build and run
```bash
git clone git@github.com:Pattson22/alx-low_level_programming.git
cd alx-low_level_programming
make
# run tests
make test

##Examples
Show how to compile and run one example:
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-holberton.c -o example
./example
Design notes
Each exercise is self-contained.

Use of static analysis and valgrind recommended for memory checks.

Tests and CI
CI runs make and make test. See .github/workflows/ci.yml.

What I learned
Manual memory management and pointer arithmetic

Defensive programming and test-driven approaches

