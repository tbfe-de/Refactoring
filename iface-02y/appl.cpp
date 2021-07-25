#include <iostream>

#define SHOW(...)\
    (void)(std::cout << __FILE__ <<  ':' << __LINE__ << '\t'\
                     << #__VA_ARGS__ << " --> " << (__VA_ARGS__)\
                     << std::endl)

#include "Clock.h"  // <--- creates unwanted dependency to `Clock`

void appl(IClock& clk) {
    Clock* cptr{static_cast<Clock*>(&clk)}; if (cptr) SHOW(*cptr);
    cptr->TickUp();                         if (cptr) SHOW(*cptr);
    cptr->Set(1, 2, 3);                     if (cptr) SHOW(*cptr);
}
