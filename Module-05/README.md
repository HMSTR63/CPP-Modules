# Module 05 · Exceptions and forms

[← Module 04](../Module-04/README.md) · [All modules](../README.md) · [Subject PDF · v11.1](en.subject.pdf) · [Module 06 →](../Module-06/README.md)

A small bureaucracy makes exceptions concrete: grades have valid ranges, forms
have signing and execution requirements, and invalid operations report failure.
Later exercises extend an abstract form and introduce a factory that creates a
concrete form from its name.

## Exercises

| Directory | Subject title | Focus | Executable |
| --- | --- | --- | --- |
| [ex00](ex00/) | Mommy, when I grow up, I want to be a bureaucrat! | Grade invariants and exceptions | `ex00` |
| [ex01](ex01/) | Form up, maggots! | Form signing and authorization | `ex01` |
| [ex02](ex02/) | No, you need form 28B, not 28C... | Abstract forms and concrete actions | `ex02` |
| [ex03](ex03/) | At least this beats coffee-making | An Intern factory returning `AForm*` | `ex02` |

## What to understand

- **Invariants:** constructors and grade-changing methods must preserve the
  permitted range or report an error through an exception.
- **Grade ordering:** grade **1** is the highest; grade **150** is the lowest.
  Promotion decreases the numeric value.
- **Exception propagation:** catch exceptions by reference through `std::exception`
  and use `what()` to explain the failure.
- **Polymorphic factories:** an `AForm*` can refer to several concrete forms without
  requiring the caller to choose their constructors directly.

## Subject requirements

- `Bureaucrat` has a constant name and a grade from 1 to 150. Invalid construction,
  promotion, or demotion throws a grade exception.
- `Form` starts unsigned and stores constant signing and execution grades.
  Signing requires a bureaucrat whose numeric grade is at most the required grade.
- In `ex02`, `Form` becomes abstract `AForm`. Execution requires both a signature
  and a sufficiently high executor grade.
- Exception classes are exempt from Orthodox Canonical Form; the other classes
  still follow the module's general rules.

| Concrete form | Signing grade | Execution grade | Action |
| --- | --- | --- | --- |
| `ShrubberyCreationForm` | 145 | 137 | Write trees to `<target>_shrubbery` |
| `RobotomyRequestForm` | 72 | 45 | Attempt robotomy with a 50% success rate |
| `PresidentialPardonForm` | 25 | 5 | Announce a presidential pardon |

`Intern::makeForm(name, target)` creates the requested form or reports an unknown
name. A returned heap-allocated form must eventually be deleted by its owner.

## Build and run

Run from `Module-05/`. Subshells keep each demo's working directory local to its
exercise, including the destination of generated shrubbery files:

```bash
make -C ex00
(cd ex00 && ./ex00)
make -C ex01
(cd ex01 && ./ex01)
make -C ex02
(cd ex02 && ./ex02)
make -C ex03
(cd ex03 && ./ex02)
```

The current `ex03/Makefile` also sets `NAME = ex02`; its command above is intentional.
The final two demos may create `MERCEDES-FORM_shrubbery` in their working directory.
Robotomy output varies between runs.

Use `make -C ex02 fclean` to clean an exercise or `make -C ex02 re` to rebuild it.
Generated shrubbery files are separate from the Makefile's build products.

## Code map

- [Bureaucrat.hpp](ex00/Bureaucrat.hpp): grades and exception types.
- [Form.cpp](ex01/Form.cpp): signing checks.
- [AForm.hpp](ex02/AForm.hpp) and [AForm.cpp](ex02/AForm.cpp): the abstract contract
  and execution requirements.
- [ShrubberyCreationForm.cpp](ex02/ShrubberyCreationForm.cpp),
  [RobotomyRequestForm.cpp](ex02/RobotomyRequestForm.cpp), and
  [PresidentialPardonForm.cpp](ex02/PresidentialPardonForm.cpp): concrete actions.
- [Intern.cpp](ex03/Intern.cpp): name-to-constructor dispatch.

## Checkout notes

All four exercises passed the recorded clean build check. Their Makefiles enable
AddressSanitizer. The demos cover selected grade and signing scenarios; they do
not cover every failure path or establish the robotomy probability statistically.

## Cases to explore

- Construct bureaucrats and forms at grades 0, 1, 150, and 151.
- Promote grade 1 and demote grade 150; inspect the exception and remaining state.
- Try to execute an unsigned form or sign/execute with an insufficient grade.
- Create each known form through `Intern`, then request an unknown form.
- Follow the lifetime of every factory-created form and inspect generated tree files.
