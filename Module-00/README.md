# Module 00 · C++ foundations

[All modules](../README.md) · [Subject PDF · v11.2](en.subject.pdf) · [Next: Module 01 →](../Module-01/README.md)

The first module moves from C functions to objects: classes hold state, member
functions control access to it, and streams handle input and output. The final
exercise introduces data shared by every instance through static members.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | Megaphone | Command-line arguments, strings, and output streams | `megaphone` |
| [ex01](ex01/) | My Awesome PhoneBook | Encapsulation, fixed-size storage, and formatted input/output | `phonebook` |
| [ex02](ex02/) | The Job Of Your Dreams | Static counters, account state, and timestamped logs | `Account` |

The subject explicitly permits passing the module without `ex02`.

## What to understand

- **Encapsulation:** a class exposes operations while keeping its internal state private.
- **Object lifetime:** constructors establish valid state; destructors run when an
  object's lifetime ends.
- **Static versus instance data:** account-wide totals belong to the class, while an
  individual account's balance belongs to that object.
- **Const member functions:** reading a contact or balance should not require changing it.

## Subject requirements

- `megaphone` uppercases its arguments and joins them without inserting additional
  separators. With no arguments, it prints the subject's feedback message.
- The phonebook stores **eight contacts** without dynamic allocation. A ninth
  contact replaces the oldest one.
- `ADD`, `SEARCH`, and `EXIT` drive the phonebook. All five contact fields must be
  non-empty; search results use four right-aligned, ten-character columns separated
  by `|`, with long values shortened using a trailing dot.
- `Account` reconstructs the behavior expected by the provided header, test driver,
  and reference log. Timestamps naturally differ between runs.

## Build and run

Run these commands from `Module-00/`:

```bash
make -C ex00
./ex00/megaphone "hello" " C++"
# HELLO C++

make -C ex01
./ex01/phonebook
# Enter ADD, SEARCH, or EXIT at the prompt.
```

The Account Makefile names its executable `Account`, but `make -C ex02` currently
fails for the reason below. Its intended test entry point is [tests.cpp](ex02/tests.cpp).

Use `make -C ex00 fclean` to remove one exercise's build products, or
`make -C ex00 re` to rebuild it from scratch.

## Code map

- [megaphone.cpp](ex00/megaphone.cpp): argument processing and uppercase output.
- [phonebook.hpp](ex01/phonebook.hpp) and [phonebook.cpp](ex01/phonebook.cpp): storage
  and phonebook operations; [Contact.hpp](ex01/Contact.hpp) defines contact data.
- [Account.hpp](ex02/Account.hpp): the account interface and shared statistics.

## Checkout notes

`ex00` and `ex01` passed the recorded clean build check. `ex02/Makefile` lists
`Account.cpp`, but that filename is absent. The implementation currently lives in
the hidden file [ex02/.cpp](ex02/.cpp), so Make cannot build `Account.o`.
The additional [test.cpp](ex02/test.cpp) is only an empty test entry point and is
not the `tests.cpp` used by the Makefile.

## Cases to explore

- Run Megaphone with no arguments, empty arguments, punctuation, and multiple words.
- Search an empty phonebook, then add nine contacts and inspect which one is replaced.
- Try long contact fields, invalid indices, empty fields, and end-of-file input.
- For Account, compare deposits, successful and refused withdrawals, and aggregate
  totals against the supplied test expectations once its build issue is resolved.
