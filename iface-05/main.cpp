#include "Clock.h"

#include <iostream>

extern void appl(IClock&);

int main() {
    Clock c{};
    appl(c);
}
