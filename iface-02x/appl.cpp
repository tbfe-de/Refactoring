#include <iostream>

#define SHOW(...)\
    (void)(std::cout << __FILE__ <<  ':' << __LINE__ << '\t'\
                     << #__VA_ARGS__ << " --> " << (__VA_ARGS__)\
                     << std::endl)

#include "Clock.h"  // <--- creates unwanted dependency to `Clock`

void appl(IClock& clk) {
    Clock& c{static_cast<Clock&>(clk)}; SHOW(c);
    c.TickUp();                         SHOW(c);
    c.Set(1, 2, 3);                     SHOW(c);
}
