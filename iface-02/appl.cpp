#include <iostream>

#include "IClock.h"

void appl(IClock& clk) {
    std::cout << "appl ready ..." << std::endl;
    clk.TickUp();
    clk.Set(1, 2, 3);
    std::cout << "... and works?" << std::endl;
}
