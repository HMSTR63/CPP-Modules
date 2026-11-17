# Module 07 · Templates

[← Module 06](../Module-06/README.md) · [All modules](../README.md) · [Subject PDF · v10.1](en.subject.pdf) · [Module 08 →](../Module-08/README.md)

Write operations once and let the compiler instantiate them for different types.
The module begins with small function templates, extends them to array traversal,
and finishes with a class template that owns a dynamically allocated array.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | Start with a few functions | Generic `swap`, `min`, and `max` | `whatever` |
| [ex01](ex01/) | Iter | Applying a callable to array elements | `iter` |
| [ex02](ex02/) | Array | Owned storage, deep copying, and checked subscripting | `Array` |

## What to understand

- **Instantiation:** a template describes a family of functions or classes; the
  compiler generates the concrete version required by each use.
- **Definition visibility:** implementations must be visible at instantiation.
  Headers can contain them directly or include a `.tpp` file.
- **Type requirements:** generic code still requires the operations it uses, such
  as assignment, comparison, or construction, to be supported by the chosen type.
- **Const correctness:** generic traversal should support reading const arrays and
  callbacks that legitimately modify mutable elements.

## Subject requirements

- `swap` exchanges two values. `min` and `max` compare two values of the same type;
  if the values are equal, they return the **second** argument.
- `iter` takes an array address, its length, and a function applied to each element.
  Support const and non-const element access as appropriate to the callback.
- Default `Array<T>` construction creates an empty array. Construction with a
  size allocates exactly that many default-initialized elements with `new[]`.
- Copy construction and assignment create independent storage. Subscript access
  outside the allocated range throws `std::exception`; `size()` is a const query.

## Build and run

Run from `Module-07/`; each executable uses the bundled test driver:

```bash
make -C ex00
./ex00/whatever
make -C ex01
./ex01/iter
make -C ex02
./ex02/Array
```

`whatever` works with integers and strings. `iter` visits a constant integer array
and a mutable string array using a printing callback. `Array` demonstrates empty
construction, string elements, an out-of-range exception, and copy independence.

Use `make -C ex02 fclean` to clean an exercise or `make -C ex02 re` to rebuild it.

## Code map

- [whatever.hpp](ex00/whatever.hpp): the three generic utility functions.
- [iter.hpp](ex01/iter.hpp): generic traversal and the demo printing helper.
- [Array.hpp](ex02/Array.hpp): the array interface, including subscripting.
- [Array.tpp](ex02/Array.tpp): allocation, copying, destruction, and bounds checks.
- [ex02/main.cpp](ex02/main.cpp): the active array demonstration and additional
  commented-out test material.

## Checkout notes

All three exercises passed the recorded clean build check. Their Makefiles enable
AddressSanitizer. The active demos exercise selected instantiations; they do not
prove correctness for every element type or callback signature.

## Cases to explore

- Compare equal-valued objects and inspect which argument `min` or `max` returns.
- Use `iter` with a modifying callback, a const array, and a zero-length range.
- Copy an array, change one copy, and confirm the other copy remains unchanged.
- Assign arrays of different sizes and try self-assignment.
- Check an empty array, the last valid index, and the first out-of-range index.
