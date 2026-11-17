# Module 04 · Polymorphism and interfaces

[← Module 03](../Module-03/README.md) · [All modules](../README.md) · [Subject PDF · v13.1](en.subject.pdf) · [Module 05 →](../Module-05/README.md)

Use base-class interfaces to work with objects whose concrete type is chosen at
runtime. Animals introduce virtual dispatch and deep copying; the Materia exercise
combines abstract interfaces, cloning, and explicit ownership.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | Polymorphism | Virtual sounds and the contrasting WrongAnimal hierarchy | `ex00` |
| [ex01](ex01/) | I don't want to set the world on fire | Heap-owned brains, virtual destruction, and deep copies | `ex01` |
| [ex02](ex02/) | Abstract class | A non-instantiable Animal base | `ex02` |
| [ex03](ex03/) | Interface & recap | Materia cloning, character inventory, and source interfaces | `ex03` |

The subject explicitly permits passing the module without `ex03`.

## What to understand

- **Virtual dispatch:** calling a virtual function through `Animal*` chooses the
  implementation belonging to the concrete object.
- **Virtual destruction:** deleting a derived object through its base interface
  must also destroy the derived resources.
- **Deep copying:** copied animals need separate `Brain` objects; copied characters
  need independently cloned Materias.
- **Abstract contracts:** pure virtual members define operations that concrete
  classes must implement while preventing direct construction of the base.

## Subject requirements

- `Animal`, `Dog`, and `Cat` provide appropriate sounds. The `WrongAnimal` and
  `WrongCat` example demonstrates behavior without virtual sound dispatch.
- `Brain` stores **100 ideas**. Dogs and cats allocate their brains on construction
  and release them on destruction; copying must preserve independence.
- From `ex02`, `Animal` must be abstract. The subject allows renaming it `AAnimal`;
  this repository retains the name `Animal`.
- `Ice` and `Cure` implement `AMateria::clone()` and their own `use()` behavior.
- A `Character` owns an inventory of **four slots**. Invalid slot operations do
  nothing; `unequip()` must not delete the removed Materia. Its lifetime still
  needs an owner to avoid leaks.
- `MateriaSource` remembers up to four learned prototypes and creates a new clone
  of a requested type, returning null when that type is unknown.

## Build and run

Run from `Module-04/`; all programs use built-in demonstrations:

```bash
make -C ex00
./ex00/ex00
make -C ex01
./ex01/ex01
make -C ex02
./ex02/ex02
make -C ex03
./ex03/ex03
```

The first demo contrasts animal sounds. The next two create arrays of dogs and
cats and print brain addresses for copied dogs. The final demo learns Ice and
Cure, equips a character, and uses both Materias on another character.

Use `make -C ex01 fclean` to clean an exercise or `make -C ex01 re` to rebuild it.

## Code map

- [ex00/Animal.hpp](ex00/Animal.hpp) and [WrongAnimal.hpp](ex00/WrongAnimal.hpp):
  the two dispatch models.
- [Brain.hpp](ex01/Brain.hpp) and [Dog.cpp](ex01/Dog.cpp): owned data and copy behavior.
- [ex02/Animal.hpp](ex02/Animal.hpp): the abstract base declaration.
- [ICharacter.hpp](ex03/ICharacter.hpp), [IMateriaSource.hpp](ex03/IMateriaSource.hpp),
  and [AMateria.hpp](ex03/AMateria.hpp): the final exercise's interfaces.
- [Character.cpp](ex03/Character.cpp) and [MateriaSource.cpp](ex03/MateriaSource.cpp):
  inventory management and prototype creation.

## Checkout notes

All four exercises passed the recorded clean build check. Some Makefiles enable
AddressSanitizer. Compilation alone does not establish correct ownership for all
equip, unequip, copy, and destruction paths.

## Cases to explore

- Compare calls through a base pointer with calls on a concrete object.
- Modify an idea after copying an animal and verify that the other copy is independent.
- Confirm that constructing `Animal` is rejected in `ex02`.
- Fill all inventory slots, try invalid indices, and request an unknown Materia type.
- Copy a character, unequip a Materia, and follow which object owns every allocation.
