# Module 03 · Inheritance

[← Module 02](../Module-02/README.md) · [All modules](../README.md) · [Subject PDF · v8.1](en.subject.pdf) · [Module 04 →](../Module-04/README.md)

Extend a small robot class into several related types. The exercises show what a
derived class reuses, how base objects are constructed and destroyed, and why
multiple inheritance needs care when two branches share the same ancestor.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | Aaaaand... OPEN! | Base class, state, attacks, damage, and repair | `ClapTrap` |
| [ex01](ex01/) | Serena, my love! | Derived `ScavTrap` and gate-keeper behavior | `ScavTrap` |
| [ex02](ex02/) | Repetitive work | Derived `FragTrap` and high-five behavior | `FragTrap` |
| [ex03](ex03/) | Now it's weird! | `DiamondTrap`, virtual inheritance, and name resolution | `DiamondTrap` |

The subject explicitly permits passing the module without `ex03`.

## What to understand

- **Base and derived state:** inherited members let related classes reuse the same
  model while initializing different health, energy, and damage values.
- **Construction order:** bases are constructed before derived parts; destruction
  reverses that order.
- **Name resolution:** qualify a base member when multiple inherited paths make
  the intended behavior ambiguous.
- **Virtual inheritance:** the `ex03` hierarchy shares one `ClapTrap` subobject
  between its `ScavTrap` and `FragTrap` branches.

## Subject requirements

| Type | Hit points | Energy | Attack damage | Special behavior |
| --- | --- | --- | --- | --- |
| `ClapTrap` | 10 | 10 | 0 | Attack, take damage, repair |
| `ScavTrap` | 100 | 50 | 20 | `guardGate()` |
| `FragTrap` | 100 | 100 | 30 | `highFivesGuys()` |
| `DiamondTrap` | From `FragTrap` | From `ScavTrap` | From `FragTrap` | `whoAmI()` and `ScavTrap::attack()` |

Attacks and repairs each cost one energy point; an exhausted or defeated robot
cannot perform them. The exercise API uses a target name rather than a direct
reference to another robot, so the demos explicitly apply damage separately.

`DiamondTrap` has its own name and a base name with the `_clap_name` suffix.
Its shared `ClapTrap` base must be constructed exactly once.

## Build and run

Run from `Module-03/`. Each executable runs a built-in combat scenario:

```bash
make -C ex00
./ex00/ClapTrap
make -C ex01
./ex01/ScavTrap
make -C ex02
./ex02/FragTrap
make -C ex03
./ex03/DiamondTrap
```

Follow the constructor/destructor messages as well as combat output. The final
demo displays both robot identities and invokes abilities from both parent classes.

Use `make -C ex03 fclean` to clean an exercise or `make -C ex03 re` to rebuild it.

## Code map

- [ex00/ClapTrap.cpp](ex00/ClapTrap.cpp): the basic state transitions.
- [ex01/ScavTrap.cpp](ex01/ScavTrap.cpp): specialization of the base robot.
- [ex02/FragTrap.cpp](ex02/FragTrap.cpp): a second derived type.
- [ex03/ScavTrap.hpp](ex03/ScavTrap.hpp) and [ex03/FragTrap.hpp](ex03/FragTrap.hpp):
  the virtual base declarations used by [DiamondTrap](ex03/DiamondTrap.hpp).

## Checkout notes

All four exercises passed the recorded clean build check. Each exercise carries
its own class files; changes made in one directory do not automatically apply to
the later versions.

## Cases to explore

- Attack or repair until energy is exhausted, then attempt another action.
- Apply damage equal to or greater than the remaining hit points.
- Copy and assign each robot type, then compare its name and state.
- Count base constructor calls for `DiamondTrap` and inspect both names with `whoAmI()`.
