# Start to Flesh Out the Interface

So that the function `appl` in `appl.cpp` can actually use
class `Clock`'s member functions something must be added.
- The two lines whown below should go **inside** the
  (currently empty) `public:` section of interface `IClock`:
```
    virtual void Set(int, int, int) =0;
    virtual void TickUp(int = 1) =0;
```
- As exactly these two are already member functions of class
  `Clock` nothing needs to be done there.
   - Of course, as a good citizien knowing how to behave well in
     the light of the C++11 ISO standard you could add the
     `override` indicator a shown below.
   - **But don't do so if youe are still locked to C++98** even
     if some older compilers accept (maybe with a warning) but
     your code would  depend on a non-standard features.
```
                                  // this is new -vvvvvvvv
    void Set(int hours, int minutes, int seconds) override {
        // (all the rest as before)
    }
               // this is new -vvvvvvvv
    void TickUp(int ticks = 1) override {
        // (all the rest as before)
    }
```
- With this additions you can demonstrate that these functions
  are now available **inside function `appl`** as defined in
  `appl.cpp`:
```
    c.TickUp();
    c.Set(1, 2, 3);
```

Of course this ONLY shows that all compiles ok, NOT that we are
now able to control the clock via the `Clock` interface.
