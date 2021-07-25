# Following Frequently Demanded "C++ Style Guide Rules"

Two rules frequently demanded in C++ Style guides have not
been followed so far:
- Declare a `virtual` destructor in every class from which
  you derive other classes.
  - As `IClock` is the base class for `Clock` this rule
    would apply here:
  - Mark every member function overridden in a derived class
    as `override`.


Apply the relevant changes now – it shouldn't change
anything in the output.

* * * * *

In the model solution the automated testing approach of
`iface-04x` is continued.