# Create an Empty the Interface

The first step is to
- create the interface as an empty class in a new file
  `IClock.h`:
  - Below only the basic content of this file is shown;
  - **As it is a header file it should also have the usual
    include guards!**
```
class IClock {
    /*empty*/
};
```
- In file `Clock.h` class `Clock` should then announce it
  will implement that interface.
  - As shown below this requres only a minimal addition to
    the class definition.
  - **But be aware that `Clock.h` now needs the include the
    header file in which `IClock` was defined.**
```
// that ----vvvvvvvvvvvvvvv---- is to be added
class Clock : public IClock {
    …
    // all the rest stays the same)
    …
};
```
- The `main` function in `main.cpp` should now reduced to
  the code shown below:
  - An external declaration is provided for the `appl` function
    only to avoid another header trivial file.
  - **The definition of `IClock` is available via the indirect
    include of its header in file `Clock.h`.**
```
extern void appl(IClock&);

int main() {
    Clock c{};
    appl(c);
}
```
- To make everything compile and run a minimalistic `appl` function
  needs be added in a file `appl.cpp`:
  - **Be sure to include the appropriate header file so the compiler
    knows the definition of `IClock`.**
```
void appl(IClock& c) {
    /*empty*/
}
```
- Now everything should compile clean but of course no output will
    be generated. ("No news is good news" :-).)
  - If you want to see some output consider to add a line like
    the one below to the body of function `appl`.
  - **Be sure to add the standard library header which defines
    `std::cout` and `std::endl` too.**

```
    std::cout << "appl ready" << std::endl;
```

* * * * *

If everything compiles clean – **and only then** – you are ready
for the next step.
