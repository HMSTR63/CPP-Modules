# Module 01 · Memory, pointers, and references

[← Module 00](../Module-00/README.md) · [All modules](../README.md) · [Subject PDF · v11.1](en.subject.pdf) · [Module 02 →](../Module-02/README.md)

This module connects object lifetime to memory ownership. Zombies demonstrate
stack and heap allocation; weapons demonstrate references and optional pointers;
the remaining exercises introduce file streams, member-function pointers, and
`switch` control flow.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | BraiiiiiiinnnzzzZ | Stack objects, `new`, and `delete` | `Zombie` |
| [ex01](ex01/) | Moar brainz! | Arrays of objects, `new[]`, and `delete[]` | `Zombie` |
| [ex02](ex02/) | HI THIS IS BRAIN | Values, addresses, pointers, and references | `brain` |
| [ex03](ex03/) | Unnecessary violence | Shared weapons through references and pointers | `weapon` |
| [ex04](ex04/) | Sed is for losers | File streams and string substitution | `replace` |
| [ex05](ex05/) | Harl 2.0 | Dispatch through pointers to member functions | `Harl` |
| [ex06](ex06/) | Harl filter | Severity filtering with `switch` | `harlFilter` |

The subject explicitly permits passing the module without `ex06`.

## What to understand

- **Storage duration:** a local object ends with its scope; a heap object remains
  alive until its owner deletes it.
- **Matching allocation:** pair `new` with `delete` and `new[]` with `delete[]`.
- **References and pointers:** a reference expresses an existing required object;
  a pointer can represent an optional association, as in an unarmed `HumanB`.
- **Member-function pointers:** invoking a selected member still requires an object.
  Harl uses this to map a level to behavior without a long conditional chain.

## Subject requirements

- `newZombie` returns a zombie that outlives the factory call; `randomChump` creates
  a temporary local zombie. The horde allocates and initializes `N` zombies together.
- `HumanA` is constructed with a weapon; `HumanB` can receive one later. Changing
  the shared weapon's type must affect subsequent attacks.
- The replacement program takes `filename`, `s1`, and `s2`, writing the result to
  `<filename>.replace`. `std::string::replace` and C file operations are forbidden.
- Harl's first exercise must use member-function pointers. The filter must use
  `switch` and print the selected level and every higher severity.

## Build and run

Run from `Module-01/`. The no-argument demos contain their own sample objects:

```bash
make -C ex00
./ex00/Zombie
make -C ex01
./ex01/Zombie
make -C ex02
./ex02/brain
make -C ex03
./ex03/weapon

make -C ex05
./ex05/Harl DEBUG
make -C ex06
./ex06/harlFilter WARNING
```

`ex04` currently has a C++98 build blocker. Its intended invocation, after that
blocker is resolved, is:

```bash
make -C ex04
printf 'hello C++, hello world\n' > /tmp/cpp01-replace-demo.txt
./ex04/replace /tmp/cpp01-replace-demo.txt hello goodbye
cat /tmp/cpp01-replace-demo.txt.replace
```

Use `make -C ex03 fclean` to clean an exercise or `make -C ex03 re` to rebuild it.

## Code map

- [newZombie.cpp](ex00/newZombie.cpp) and [randomChump.cpp](ex00/randomChump.cpp):
  contrasting object lifetimes; [zombieHorde.cpp](ex01/zombieHorde.cpp) allocates an array.
- [HumanA.hpp](ex03/HumanA.hpp), [HumanB.hpp](ex03/HumanB.hpp), and
  [Weapon.hpp](ex03/Weapon.hpp): two ways to share a weapon.
- [Sed.cpp](ex04/Sed.cpp): line-by-line replacement using string operations.
- [ex05/Harl.cpp](ex05/Harl.cpp) and [ex06/Harl.cpp](ex06/Harl.cpp): direct dispatch
  versus severity filtering.

## Checkout notes

Six of the seven exercises passed the recorded clean build check. `ex04` fails
because [Sed.cpp](ex04/Sed.cpp) passes `std::string` objects directly to file-stream
constructors that accept C strings under C++98.

The current Harl method is named `comlain`, while the subject calls it `complain`.
The command-line demos invoke the existing spelling. Unknown filter levels
currently print `Harl is silent`; the subject shows a different fallback message.

## Cases to explore

- Follow destruction messages and ensure every heap allocation has one owner.
- Compare the three addresses printed by `brain`; they should identify the same string.
- Try an unarmed `HumanB`, then change a weapon type after both humans reference it.
- Check missing files, empty search strings, repeated matches, and replacement text
  containing the search string once `ex04` builds.
- Compare `Harl WARNING` with `harlFilter WARNING`: one level versus that level and above.
