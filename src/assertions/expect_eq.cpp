#include <iostream>
#include "../../include/assertions/expect_eq.h"
#include "../../include/utils.h"


void EXPECT_EQ(const std::string &val1, const std::string &val2)
{
    bool verdict = val1 == val2;
    EXPECT_EQ_MSG_GENERIC(verdict, val1, val2);
}

void EXPECT_EQ_MSG_GENERIC(
    const bool verdict,
    const std::string &value1,
    const std::string &value2)
{
    print_char_n(' ', 5);

    if (verdict) {
        std::cout << GREEN << BOLD << "PASS..." << RESET << std::endl;
    } else {
        std::cout << RED << BOLD << "FAIL..." << RESET << std::endl;
    }

    print_char_n(' ', 10);
    std::cout << "value 1: " << value1 << std::endl;

    print_char_n(' ', 10);
    std::cout << "value 2: " << value2 << std::endl;

    print_char_n('\n', 1);
}
