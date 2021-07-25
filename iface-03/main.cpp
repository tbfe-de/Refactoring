#include "Clock.h"

#include <iostream>

#define SHOW(...)\
    (void)(std::cout << __FILE__ <<  ':' << __LINE__ << '\t'\
                     << #__VA_ARGS__ << " --> " << (__VA_ARGS__)\
                     << std::endl)

extern void appl(IClock&);

int main() {
    Clock c{};
    appl(c);
}
