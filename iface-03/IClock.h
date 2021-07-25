#ifndef ICLOCK_H
#define ICLOCK_H

#include <iosfwd>

class IClock {
public:
    virtual void Set(int, int, int) =0;
    virtual void TickUp(int = 1) =0;
    virtual std::ostream& Print(std::ostream&) const =0;
};

#endif
