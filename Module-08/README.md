# Module 08 · Containers, iterators, and algorithms

[← Module 07](../Module-07/README.md) · [All modules](../README.md) · [Subject PDF · v10.1](en.subject.pdf) · [Module 09 →](../Module-09/README.md)

The STL brings together containers that store data, iterators that expose a
sequence, and algorithms that operate on iterator ranges. These exercises use
that separation to implement generic search, distance calculations, and an
iterable stack adapter.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | Easy find | Generic search with `std::find` | `easyfind` |
| [ex01](ex01/) | Span | Capacity, iterator-range insertion, and numeric distances | `Span` |
| [ex02](ex02/) | Mutated abomination | Extending `std::stack` with iterators | `MutantStack` |

## What to understand

- **Containers:** `std::vector` and `std::list` provide different storage models.
  Generic search can use either through their iterator interfaces.
- **Half-open ranges:** `[begin, end)` includes the first element and excludes the
  past-the-end position. Never dereference `end()`.
- **Algorithms:** `std::find`, `std::sort`, `std::min_element`, and
  `std::max_element` express common operations without duplicating their logic.
- **Adapters:** `std::stack` exposes a restricted interface over an underlying
  container. A derived adapter can access its protected container member `c`.

## Subject requirements

- Use STL containers and algorithms wherever appropriate; doing so is an explicit
  objective of this module.
- `easyfind` finds the first occurrence of an integer in a container. Missing
  values can produce an exception or another documented error result. Associative
  containers are not required.
- `Span` stores at most `N` integers. Adding beyond capacity throws; computing a
  span with fewer than two values also throws.
- Provide shortest and longest distances, insertion of a range in one call, and
  tests containing at least **10,000 numbers**.
- `MutantStack` retains normal stack operations and adds iteration. Compare its
  observable behavior with an equivalent sequence in another container.

## Build and run

Run from `Module-08/`; all programs have built-in demonstrations:

```bash
make -C ex00
./ex00/easyfind
make -C ex01
./ex01/Span
make -C ex02
./ex02/MutantStack
```

`easyfind` tries vector, list, missing-value, and empty-container cases.
`Span` runs the five-value subject example, an empty-span case, and a range
insertion of **63,000 random integers**. The five-value example should produce a
shortest span of `2` and a longest span of `14`; the large random results vary.
`MutantStack` prints its stack and iterator operations, then repeats the sequence
with a list for comparison.

Use `make -C ex01 fclean` to clean an exercise or `make -C ex01 re` to rebuild it.

## Code map

- [easyfind.hpp](ex00/easyfind.hpp): mutable and const search overloads that throw
  `NoElementFound` when the requested value is absent.
- [Span.hpp](ex01/Span.hpp): capacity, single-value insertion, and templated range
  insertion; [Span.cpp](ex01/Span.cpp) implements distance calculations.
- [MutantStack.hpp](ex02/MutantStack.hpp): iterator aliases and access to the
  underlying stack container, including const and reverse traversal methods.
- [ex02/main.cpp](ex02/main.cpp): the stack/list comparison driver.

## Implementation notes

The shortest-span implementation sorts a copy and examines adjacent differences,
so sorting dominates its `O(n log n)` running time. The longest span uses the
minimum and maximum values with linear scans. The stored order remains unchanged
by those calculations.

`MutantStack<T>` inherits from `std::stack<T>` and exposes its underlying iterator
families through dependent type aliases using `typename`.

## Checkout notes

All three exercises passed the recorded clean build check. Their Makefiles enable
AddressSanitizer. The build check does not establish correctness for the full
integer range: the current `Span` distance methods return `int`, which deserves
particular attention when testing widely separated signed values.

## Cases to explore

- Search for the first, last, repeated, and missing value, including in a const container.
- Fill a Span exactly to capacity, then try one extra value and an oversized range.
- Calculate spans with zero, one, duplicate, negative, and widely separated values.
- Copy a Span and modify one copy independently.
- Compare forward, reverse, and const stack traversal with the underlying sequence.
