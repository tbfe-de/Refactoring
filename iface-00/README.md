# Using Interfaces to Decrease Coupling

This refactoring is about using an what in OOP is called an
Interface to reduce coupling between two modules.

The starting situation is that a program uses a feature
called "Clock" directly.

**SIDE-NOTE** (you may skip over this on first reading):\
Actually `Clock` is a class holding three instances of a
class `Counter`. Don't worry too much what the class `Clock`
actually does. It is used here to give the example a
concrete and realistic background. But the stepwise process
shown always applies the same if you strive to decrease
coupling via an interface layer to something already packed
into a class or a set of classes meant to be used together.)

Currently a `Clock` instance is used directly in the main
program, which does only some basic tests of a Clock's
functionality.

These are the overall goals of the next five steps of this
refactoring:
- Shift the actual USE of the Clock
  - AWAY from the `main` function implemented in
    `main.cpp`
  - INTO an `appl` function implemented in `appl.cpp`.
- **Avoid the latter needs to know the details about how a
  Clock is implemented.**
  - To compile `appl.cpp` it should suffice to know how
    a Clock is menat to be used by its interface.
  - Nothing but the header file of the interface should be
    required to include into the translation unit.
- The actual Clock objects will (still) be provided by the
  `main` function.
  - Therefore in `main.cpp` the header file defining the
    class `Clock`` (still) need to ne included.
  - This header in turn will include the heder of the
    interface `IClock`, therefore its definition is
    available too.
