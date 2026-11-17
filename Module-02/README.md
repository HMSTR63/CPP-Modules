# Module 02 · Fixed-point numbers and operator overloading

[← Module 01](../Module-01/README.md) · [All modules](../README.md) · [Subject PDF · v9.1](en.subject.pdf) · [Module 03 →](../Module-03/README.md)

Build a numeric type in stages: first define its copy and lifetime behavior, then
add conversion, arithmetic, comparisons, and a geometric application. Each exercise
contains its own version of `Fixed` rather than sharing a single implementation.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | My First Class in Orthodox Canonical Form | Constructors, assignment, and raw storage | `Fixed` |
| [ex01](ex01/) | Towards a more useful fixed-point number class | Integer/float conversion and stream insertion | `Fixed` |
| [ex02](ex02/) | Now we're talking | Arithmetic, comparisons, increments, and min/max | `Fixed` |
| [ex03](ex03/) | BSP | Strict point-in-triangle testing using `Fixed` | `Fixed` |

The subject explicitly permits passing the module without `ex03`.

## What to understand

- **Orthodox Canonical Form:** default construction, copy construction, copy
  assignment, and destruction define how an object is created, copied, and released.
- **Fixed-point representation:** eight fractional bits give a scale factor of
  `256`; a stored raw integer represents `raw / 256`. One raw step is `1/256`.
- **Value semantics:** arithmetic creates result values, while prefix and postfix
  increment have different return behavior.
- **Const overloads:** `min` and `max` must support both mutable and constant operands.

## Subject requirements

- Store the raw value in an integer with a static constant fractional-bit count of
  **eight**. The first exercise exposes `getRawBits` and `setRawBits`.
- Add integer and floating-point constructors, `toInt`, `toFloat`, and `operator<<`.
  `roundf` from `<cmath>` is explicitly authorized where the subject lists it.
- Add all six comparisons, four arithmetic operators, prefix/postfix increment and
  decrement, and mutable/const forms of static `min` and `max`.
- `Point` stores constant `Fixed` coordinates. `bsp(a, b, c, point)` returns true
  only for a point strictly inside the triangle: vertices and edges are excluded.

## Build and run

Run from `Module-02/`; all four Makefiles produce an executable named `Fixed`:

```bash
make -C ex00
./ex00/Fixed
make -C ex01
./ex01/Fixed
make -C ex02
./ex02/Fixed
make -C ex03
./ex03/Fixed
```

`ex00` demonstrates copying and raw bits; `ex01` prints numeric conversions;
`ex02` demonstrates increments and multiplication; `ex03` tests point `(2, 2)`
against the triangle `(0, 0)`, `(10, 0)`, `(0, 10)`.

Use `make -C ex02 fclean` to clean an exercise or `make -C ex02 re` to rebuild it.

## Code map

- [ex00/Fixed.hpp](ex00/Fixed.hpp): the initial canonical interface.
- [ex01/Fixed.cpp](ex01/Fixed.cpp): conversions and stream output.
- [ex02/Fixed.cpp](ex02/Fixed.cpp): operators and min/max overloads.
- [Point.hpp](ex03/Point.hpp), [Point.cpp](ex03/Point.cpp), and [bsp.cpp](ex03/bsp.cpp):
  coordinates and a triangle-area decomposition test.

## Checkout notes

All four exercises passed the recorded clean build check. The supplied `main.cpp`
files demonstrate a subset of the interface; they are not exhaustive tests of
every operator, numeric range, or geometric boundary.

## Cases to explore

- Compare copy construction with assignment, including self-assignment.
- Convert zero, negative values, integers, and values between two representable steps.
- Inspect prefix/postfix results and confirm that increment changes the value by `1/256`.
- Exercise every comparison and both const and mutable min/max overloads.
- Test points inside, outside, on an edge, at a vertex, and against a degenerate triangle.
