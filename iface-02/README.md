# Start to Flesh Out the Interface

What so far has been achieved is to PARTIALLY demonstrate that
a `Clock` may be controlled through an `IClock` interface.
- The functions and `Set` and `TickUp` can be called.
- As there is currently no way to "show" the current state of the clock the effect cannot be verified.

* * * * *

Actually there is a way which is provided in the extra steps
`iface-02x` and`iface-02y`:
- It requires to use a "downcast" from `IClock` to `Clock` to
  access the "runtime type" implementing the interface.
- As this introduces exactly the coupling the interface shall
  avoid it is only shown but not further developed.