# Add `Print`-ing-Capability to the Interface

To determine whether the two functions called to `TickUp` or
`Set` the `Clock` behind the interface have the intended
effect another function has to be added to the interface:
- This function is very similar to the current `operator<<`
  but it cannot be defined as that operator, only as an
  ordinary member function, as `Print` is one below:
  - As an operator function it would need to take the
    `IClock` interface as it right hand argument.
  - But it actually receives it via the `this` pointer.
```
class IClock {
   …
   virtual std::ostream& Print(std::ostream&) const =0;
};
```
- **It takes TWO steps to make the `operator<<` available
  via the `IClock` interface.**
  - The above (and what follows below) only deals only with
    the first step.

Of course this function now needs an implementation, which
is nearly there in the shape of `operator<<`.
- Here is what it looks like right now (in class `Clock` as
  defined in `Clock.h`):
```
friend
std::ostream& operator<<(std::ostream&, const Clock&);
```
- And below is what it needs to be turned into:
```
std::ostream& Print(std::ostream&) const;;
```

The implementation needs to be modified accordingly.
- Currently it is outside of class `Clock` defined in
  `Clock.cpp`:
```
std::ostream& operator<<(std::ostream& lhs, const Clock& rhs) {
    std::ostream os{lhs.rdbuf()};
    os.fill('0');
    os << std::setw(2) << rhs.hours_.GetValue() << ':'
       << std::setw(2) << rhs.minutes_.GetValue() << ':'
       << std::setw(2) << rhs.seconds_.GetValue();
    return lhs;       
}
```
- It should become:
```
std::ostream& Clock::Print(std::ostream& lhs) const {
    std::ostream os{lhs.rdbuf()};
    os.fill('0');
    os << std::setw(2) << this->hours_.GetValue() << ':'
       << std::setw(2) << this->minutes_.GetValue() << ':'
       << std::setw(2) << this->seconds_.GetValue();
    return lhs;       
}
```
- **Understand that the use of `this->` above is not strictly
  necessary.**
  - It was only used in the example to illustrate how the
    `rhs` argument now became the `Clock` object for which
    `Print` has been called.
  - Feel free to omit it when ypu apply the change.
- Similarly, using the name `lhs` for the `std::ostream`
  argument doesn't any longer give the right indication what
  it stands for.
  - Feel free to rename it to something more meaningful.

Before `operator<<` is reestablished in the next step test
what has been achieved so far.
- Use something like below in the body of function `appl``
  as implemented in `appl.cpp`
  - Note that `clk` is the argument of type `IClock` and is
    handed over via reference. (So behind the scenes a
    pointer is used.)
  - **Understand that there still is NO a dependency on
    class `Clock` only on the interface `IClock`.**
```
    clk.Print(std::cout) << std::endl;
    clk.TickUp();	
    clk.Print(std::cout) << std::endl;
    clk.Set(1, 2, 59);
    clk.Print(std::cout) << std::endl;
    clk.TickUp();	
    clk.Print(std::cout) << std::endl;
```
