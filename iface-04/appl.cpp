#include <iostream>

#define SHOW(...)\
    (void)(std::cout << __FILE__ <<  ':' << __LINE__ << '\t'\
                     << #__VA_ARGS__ << " --> " << (__VA_ARGS__)\
                     << std::endl)

#include "IClock.h"

void appl(IClock& clk) {
                        SHOW(clk);
    clk.TickUp();       SHOW(clk);
    clk.TickUp();       SHOW(clk);
    clk.TickUp();       SHOW(clk);
    clk.Set(0, 0, 58);  SHOW(clk);
    clk.TickUp();       SHOW(clk);
    clk.TickUp();       SHOW(clk);
    clk.TickUp();       SHOW(clk);
    clk.TickUp(60);     SHOW(clk);
    clk.TickUp(60);     SHOW(clk);
}
