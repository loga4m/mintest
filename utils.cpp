#include "utils.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

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

    /*

        PASS..
            value 1: sds
            value 2: sdsd

    */

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

std::string vector2string(std::vector<std::string> vec)
{
    std::string result = "{";

    for (int i = 0; i < vec.size(); i++)
    {
        result += vec[i];
        if (i < vec.size() - 1)
        {
            result += ", ";
        }
    }
    result += "}";
    return result;
}

void add_char_n_times(std::string &source, char ch, int n)
{
    for (int i = 0; i < n; i++)
    {
        source += ch;
    }
}

void print_char_n(char ch, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << ch;
    }
}

void print_line()
{
    print_char_n('-', 80);
    std::cout << std::endl;
}
