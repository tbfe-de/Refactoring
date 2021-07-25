#include <iostream>

#include "IClock.h"

void appl(IClock& clk) {
    clk.Print(std::cout) << std::endl;

    clk.TickUp();	
    clk.Print(std::cout) << std::endl;

    clk.Set(1, 2, 59);
    clk.Print(std::cout) << std::endl;
    clk.TickUp();	
    clk.Print(std::cout) << std::endl;
}
