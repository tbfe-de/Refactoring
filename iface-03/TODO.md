# Make the `Print`-ing-Capability available via `operator<<`

Now that there is a `Print`-ing capability available via the
`IClock` interface using it via `operator<<` is close to
trivial:
- In file `IClock.h` implement the following function:
```
inline
std::ostream& operator<<(std::ostream& lhs,
                         const IClock& rhs) {
    return … // TBD
}
```
- A "to be done" has been left for you.
  - But the solution is really simple.
  - REALLY!
  - (if you're desperate scroll down to the bottom)

- In `appl` you can now use `SHOW` again to show the state
  of anything that implements the interface `IClock`:
  - **If you have not yet moved over the `SHOW`-macro from
    file `main.cpp` to `ppl.cpp` you should do it now.
  - Whether you want to do more thorough testing as shown
    below is up to you.
```
void appl(IClock& clk) {
                        SHOW(clk);
    clk.TickUp();       SHOW(clk);
    …
}
```

* * * * * 

Optional:

As it quickly can getting boring (and therefore somewhat
error prone) to verify more or less voluminous test output
against your expectations, consider to switch to a
lightweight form of TDD, as shown in `iface-04x`.

if you simply copy over the file `appl.cpp` from there to
your solution you should only get some output like below if
everything works as expected:
```
*** 12 tests PASSED
```



