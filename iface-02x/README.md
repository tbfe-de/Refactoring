# Statically Down-Casting From an Interface

Here function `appl` as defined in `appl.cpp` accesses
`operator<<` by down-casting the interface `IClock` to the
underlying `Clock`:
- **The necessity for down-casts can usually be considered
  as bad design and hence should be avoided.**
  - The next step in the main line demonstrates how this can
    be achieved.
- It also need to be understood that the solution shown,
  with the `static_cast` fully depends on knowledge that can
  only come from a thorough code review.
  - **Therefore the program might be broken easily and
    inadvertently by modifications outside of function
    `appl`.**
