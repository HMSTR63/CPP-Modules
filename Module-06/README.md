# Module 06 · C++ casts

[← Module 05](../Module-05/README.md) · [All modules](../README.md) · [Subject PDF · v8.1](en.subject.pdf) · [Module 07 →](../Module-07/README.md)

Explore three different conversion problems: turning a literal into scalar values,
round-tripping a pointer through an integer, and identifying a derived object
through a polymorphic base. Each needs a different kind of cast.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | Conversion of scalar types | Literal parsing, limits, and explicit scalar conversions | `convert` |
| [ex01](ex01/) | Serialization | `Data*` ↔ `uintptr_t` with `reinterpret_cast` | `Serialize` |
| [ex02](ex02/) | Identify real type | Runtime identification using `dynamic_cast` | `Bass` |

## What to understand

- **`static_cast`:** explicitly converts scalar types; checking range and special
  values remains the program's responsibility.
- **`reinterpret_cast`:** the pointer exercise preserves an address representation.
  It does not copy the pointed-to object or save it to a file.
- **`dynamic_cast`:** checks a polymorphic object's concrete type. A failed pointer
  cast produces null; a failed reference cast throws an exception.
- **Object lifetime:** converting a pointer to an integer does not extend the life
  of its object. The round trip is meaningful while the original object is alive.

## Subject requirements

- `ScalarConverter` is not instantiable by users. Its static `convert` method
  prints the input as `char`, `int`, `float`, and `double`.
- Recognize decimal literals and special values including `nan`, `nanf`, and signed
  infinities. Report impossible conversions and non-displayable characters.
- `Serializer` also exposes only static operations. Round-tripping a non-empty
  `Data` object's address must return the original pointer.
- `Base` has a public virtual destructor; empty `A`, `B`, and `C` derive from it.
  Identify an object's real type through both a base pointer and a base reference.
- `identify(Base&)` must not use a pointer, and the exercise forbids including
  `<typeinfo>`. These four identification classes are exempt from Canonical Form.

## Build and run

Run from `Module-06/`:

```bash
make -C ex00
./ex00/convert 0
./ex00/convert 42.0f
./ex00/convert nan
./ex00/convert a

make -C ex01
./ex01/Serialize

make -C ex02
./ex02/Bass
```

The serializer demo stores `63`, serializes its address, changes the original value
to `44`, then reads `44` through the restored pointer and compares both addresses.
That illustrates address preservation rather than a snapshot of the earlier value.

The identification demo creates ten randomly selected objects. Its executable is
named `Bass` in the current Makefile, and the printed type order varies by run.

Use `make -C ex00 fclean` to clean an exercise or `make -C ex00 re` to rebuild it.

## Code map

- [ScalarConverter.cpp](ex00/ScalarConverter.cpp): parsing, scalar limits, and output.
- [Serializer.hpp](ex01/Serializer.hpp): `Data` and the static conversion interface;
  [Serializer.cpp](ex01/Serializer.cpp) implements the casts.
- [Base.hpp](ex02/Base.hpp) and [main.cpp](ex02/main.cpp): the hierarchy, random
  generation, and both identification overloads.

## Checkout notes

All three exercises passed the recorded clean build check. However,
[ex02/main.cpp](ex02/main.cpp) currently includes `<typeinfo>`, which the subject
explicitly forbids. A successful build does not establish subject compliance.

## Cases to explore

- Convert displayable characters, zero, signed values, decimal fractions, and numeric limits.
- Try each pseudo-literal, malformed text, overflow, and a value with no displayable character.
- Confirm that serialization preserves pointer identity and access to the same live object.
- Identify each concrete type through both overloads and compare failed-cast behavior.
