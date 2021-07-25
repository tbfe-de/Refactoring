# Dynamically Down-Casting From an Interface

Here function `appl` as defined in `appl.cpp` accesses
`operator<<` by down-casting the interface `IClock` to the
underlying `Clock`:
- **The necessity for down-casts can usually be considered
  as bad design and hence should be avoided.**
  - The next step in the main line demonstrates how this can
    be achieved.
- The solution shown uses a `dynamic_cast` which returns a
  `nullptr` if the underlying (runtime) type is not an
  instance of `class Clock` (or a class derived from it).
  - This is called RTTI and relies on extra information
    the compiler puts into the executable code.
  - To avoid bloated executable code that extra information
    is only created for classes with at least one `virtual`
    member function.
  - The solution chosen here to simply do nothing if the
    runtime type is NOT `Clock` may or may not be the right
    thing to do.
  - **Therefore the code INSIDE `appl` may still be
    inadvertently broken by changes OUTSIDE of `appl`.
