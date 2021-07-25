#ifndef ICLOCK_H
#define ICLOCK_H

class IClock {
public:
    virtual void Set(int, int, int) =0;
    virtual void TickUp(int = 1) =0;
};

#endif
