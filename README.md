# C++ Modules · 42

A progression through C++98: from classes and object lifetimes to polymorphism,
templates, and the Standard Template Library. Each module has its own subject PDF,
exercise directories, and guide with build commands and study notes.

## Modules

| Module | Focus | Exercises | Subject |
| --- | --- | --- | --- |
| [00](Module-00/README.md) | Classes, streams, static members, and const | `ex00`–`ex02` | [PDF · v11.2](Module-00/en.subject.pdf) |
| [01](Module-01/README.md) | Allocation, pointers, references, and member-function pointers | `ex00`–`ex06` | [PDF · v11.1](Module-01/en.subject.pdf) |
| [02](Module-02/README.md) | Orthodox Canonical Form and operator overloading | `ex00`–`ex03` | [PDF · v9.1](Module-02/en.subject.pdf) |
| [03](Module-03/README.md) | Inheritance and the diamond problem | `ex00`–`ex03` | [PDF · v8.1](Module-03/en.subject.pdf) |
| [04](Module-04/README.md) | Runtime polymorphism, abstract classes, and interfaces | `ex00`–`ex03` | [PDF · v13.1](Module-04/en.subject.pdf) |
| [05](Module-05/README.md) | Exceptions, authorization rules, and form factories | `ex00`–`ex03` | [PDF · v11.1](Module-05/en.subject.pdf) |
| [06](Module-06/README.md) | Scalar conversion, pointer casts, and type identification | `ex00`–`ex02` | [PDF · v8.1](Module-06/en.subject.pdf) |
| [07](Module-07/README.md) | Function and class templates | `ex00`–`ex02` | [PDF · v10.1](Module-07/en.subject.pdf) |
| [08](Module-08/README.md) | Containers, iterators, and algorithms | `ex00`–`ex02` | [PDF · v10.1](Module-08/en.subject.pdf) |
| [09](Module-09/README.md) | Exchange-rate lookup, RPN, and Ford–Johnson sorting | `ex00`–`ex02` | [PDF · v3.3](Module-09/en.subject.pdf) |

**10 modules · 38 exercise directories · C++98**

## Getting started

You need a C++ compiler exposed as `c++` and GNU Make. Linux or WSL works well
with the existing Makefiles; Module 09's sorting demo also uses POSIX timing APIs.
Several exercises enable AddressSanitizer, so the compiler needs its runtime.

```bash
git clone https://github.com/HMSTR63/CPP-Modules.git
cd CPP-Modules/Module-00/ex00
make
./megaphone "hello, C++"
```

Expected output:

```text
HELLO, C++
```

Build each exercise from its own directory. There is no repository-wide Makefile,
and executable names are case-sensitive; each module guide lists the exact names.

| Command | Purpose |
| --- | --- |
| `make` | Build the exercise |
| `make clean` | Remove compilation intermediates |
| `make fclean` | Remove intermediates and the executable |
| `make re` | Clean and rebuild |

## Reading the repository

```text
CPP-Modules/
├── README.md
├── Module-00/
│   ├── README.md          # Overview, exercises, commands, and study notes
│   ├── en.subject.pdf     # Matching module subject
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
└── Module-01/ … Module-09/ # Same module-level organization
```

Start with the subject, read the module guide, then follow the exercise order.
Exercises often expand earlier classes, but each directory is built independently.
The subject PDFs define the assignment; the READMEs summarize it and explain how
to navigate this checkout. A described requirement is not a claim of full compliance.

## Shared subject rules

- Compile with `c++`, `-Wall -Wextra -Werror`, and C++98 compatibility. The supplied
  Makefiles explicitly use `-std=c++98`.
- Use C++ streams and allocation facilities. The subjects prohibit the `printf`
  family, C allocation functions, external libraries, Boost, and C++11 or newer features.
- STL containers and `<algorithm>` are introduced in Modules 08 and 09; they are
  restricted in earlier modules unless explicitly permitted.
- From Module 02 onward, use Orthodox Canonical Form unless an exercise grants an
  exception: default constructor, copy constructor, copy assignment, and destructor.
- Keep headers self-contained and protected against repeated inclusion. Template
  definitions must be visible where they are instantiated.
- Understand ownership, release allocated memory, and test more than the subject's
  sample input. Check each PDF for its exact restrictions and exceptions.

## Build verification

The existing code was checked on **2026-11-17** with **GCC 13.3.0** and **GNU Make
4.3** on Linux/WSL, starting from source revision `b33054e`. All 38 exercise
Makefiles were invoked with `make -B all` in a temporary copy, forcing compilation
instead of relying on binaries or object files already tracked in Git.

**35 exercises built; 3 have existing build failures:**

| Exercise | Observed blocker |
| --- | --- |
| [Module 00 · ex02](Module-00/README.md#checkout-notes) | The Makefile expects `Account.cpp`; the implementation is stored as `.cpp`. |
| [Module 01 · ex04](Module-01/README.md#checkout-notes) | File streams receive `std::string` filenames, which these C++98 constructors do not accept. |
| [Module 09 · ex01](Module-09/README.md#checkout-notes) | `std::atoi` is used without directly including `<cstdlib>`. |

This is a compilation snapshot, not a complete behavior, memory-safety, or
peer-evaluation audit. Module guides include useful cases to check while studying.
