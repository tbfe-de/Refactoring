#include <iostream>
#include <sstream>

#define SHOW(...)\
    (void)(std::cout << __FILE__ <<  ':' << __LINE__ << '\t'\
                     << #__VA_ARGS__ << " --> " << (__VA_ARGS__)\
                     << std::endl)
int SHOW_tests{0};
int SHOW_failed{0};
#define SHOW_(expect, ...)\
    do {\
        ++SHOW_tests;\
        std::ostringstream result;\
        result.copyfmt(std::cout);\
        result << (__VA_ARGS__);\
        if (result.str() != expect) {\
                std::cout << __FUNCTION__ <<  ':' << __LINE__ << '\t'\
                          << #__VA_ARGS__ << " --> " << result.str()\
                          << " != " << expect << std::endl;\
                ++SHOW_failed;\
        }\
    }\
    while (0)
#define SHOW_TEST_SUMMARY()\
    ((void)((SHOW_failed == 0)\
            ? std::cout << "*** " << SHOW_tests << " tests PASSED" << std::endl\
            : std::cout << "!!! " << SHOW_failed << " of "\
                                  << SHOW_tests << " tests FAILED" << std::endl))

#include "IClock.h"

void appl(IClock& clk) {
                        SHOW_("00:00:00", clk);
    clk.TickUp();       SHOW_("00:00:01", clk);
    clk.TickUp();       SHOW_("00:00:02", clk);
    clk.TickUp();       SHOW_("00:00:03", clk);
    clk.Set(0, 0, 58);  SHOW_("00:00:58", clk);
    clk.TickUp();       SHOW_("00:00:59", clk);
    clk.TickUp();       SHOW_("00:01:00", clk);
    clk.TickUp();       SHOW_("00:01:01", clk);
    clk.TickUp(60);     SHOW_("00:02:01", clk);
    clk.TickUp(60);     SHOW_("00:03:01", clk);
    clk.Set(23, 59, 0); SHOW_("23:59:00", clk);
    clk.TickUp(60);     SHOW_("00:00:00", clk);
    SHOW_TEST_SUMMARY();
}
