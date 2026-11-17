# Module 09 · STL applications

[← Module 08](../Module-08/README.md) · [All modules](../README.md) · [Subject PDF · v3.3](en.subject.pdf)

Choose containers to suit three different problems: ordered date lookup,
last-in-first-out expression evaluation, and merge-insertion sorting. The subject
requires different containers across exercises, making container selection part
of the design rather than an incidental implementation detail.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | Bitcoin Exchange | CSV rates, date validation, and prior-date lookup | `btc` |
| [ex01](ex01/) | Reverse Polish Notation | Stack evaluation and operand order | `RPN` |
| [ex02](ex02/) | PmergeMe | Ford–Johnson sorting and container timing | `PmergeMe` |

## Container choices in this checkout

| Exercise | Containers | Role |
| --- | --- | --- |
| `ex00` | `std::map<std::string, float>` | Ordered exchange rates indexed by date |
| `ex01` | `std::stack<int, std::list<int> >` | Operand stack backed by a list |
| `ex02` | `std::vector` and `std::deque` | Two sorting implementations and their intermediate groups |

The subject requires at least one container in each exercise and two in `ex02`.
Containers used to validate one exercise cannot be reused in the following ones.
The explicit list backing in `RPN` matters: the default stack backing would be a deque.

## Subject requirements

### Bitcoin Exchange

- Read an input filename whose rows follow `date | value`; dates use `YYYY-MM-DD`.
- Accept amounts from **0 to 1000**, validate inputs, and report invalid rows.
- Multiply each amount by the stored rate for that date. If there is no exact
  match, use the closest **earlier** stored date, never a later one.

### Reverse Polish Notation

- Accept one quoted expression containing single-digit operands and `+ - / *`.
- Intermediate values and results can exceed one digit. Parentheses and decimal
  operands are outside the required input language.
- Maintain operand order for subtraction and division, reject malformed
  expressions, and print errors on standard error.

### PmergeMe

- Sort a positive integer sequence using **Ford–Johnson merge-insertion sort**
  with at least two different containers.
- Handle at least **3,000 integers, including duplicate values** in this subject version.
- Display the before/after sequence and timing for each container. Timing must
  account for the sorting and associated data management; errors go to standard error.

## Build and run

Run from `Module-09/`. Bitcoin Exchange loads `data.csv` relative to its current
working directory, so start it from `ex00`:

```bash
make -C ex00
(cd ex00 && ./btc in.txt)

make -C ex02
./ex02/PmergeMe 3 5 9 7 4
./ex02/PmergeMe 5 3 5 1 3
```

The included [in.txt](ex00/in.txt) mixes valid and invalid rows. Its error messages
are part of the demo. [data.csv](ex00/data.csv) is the historical rate dataset used
by the program, not a live market feed.

`RPN` currently has the build blocker described below. Its intended invocation is:

```bash
make -C ex01
./ex01/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# Expected result for this expression: 42
```

On Linux/WSL, generate a 3,000-element input with:

```bash
./ex02/PmergeMe $(shuf -i 1-100000 -n 3000)
```

This command generates distinct values; the smaller duplicate example above
checks a separate requirement. PmergeMe abbreviates displayed sequences longer
than five elements, so inspecting its printed prefix does not verify the full sort.

Use `make -C ex02 fclean` to clean an exercise or `make -C ex02 re` to rebuild it.

## Code map

- [BitcoinExchange.cpp](ex00/BitcoinExchange.cpp): database loading and input processing.
- [RPN.hpp](ex01/RPN.hpp) and [RPN.cpp](ex01/RPN.cpp): stack storage and token evaluation.
- [PmergeMe.hpp](ex02/PmergeMe.hpp) and [PmergeMe.cpp](ex02/PmergeMe.cpp): vector/deque
  sorting, grouped chains, and Jacobsthal insertion helpers.
- [ex02/main.cpp](ex02/main.cpp): argument parsing, output, and POSIX timing.

## Checkout notes

`ex00` and `ex02` passed the recorded clean build check. `ex01` fails with GCC
13.3.0 because [RPN.cpp](ex01/RPN.cpp) calls `std::atoi` without directly including
`<cstdlib>`; the compiler reports that `atoi` is not a member of `std`.

PmergeMe currently writes caught exception messages to standard output, whereas
the subject requires standard error. The supplied PDF also explicitly requires
duplicates to work; compilation alone does not verify that or Ford–Johnson correctness.

## Cases to explore

- Bitcoin: exact and missing dates, leap days, dates before the dataset, missing
  files, malformed rows, and amounts at 0, 1000, and outside that range.
- RPN: subtraction/division order, insufficient operands, leftover operands,
  invalid tokens, and division by zero once the build blocker is resolved.
- PmergeMe: one value, odd/even lengths, sorted and reversed inputs, duplicates,
  invalid numeric text, and inputs of at least 3,000 elements.
- Compare both full sorting results with a trusted sorted copy when evaluating the
  algorithm; the abbreviated display is only a preview.
