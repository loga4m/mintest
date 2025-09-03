#include "../include/suit.h"
#include "../include/utils.h"
#include <iostream>
#include <stdexcept>

TestSuit::TestSuit()
    : tests{} {};

void TestSuit::run_tests()
{
    print_char_n('\n', 1);
    test_runner();
    print_line();
}

void TestSuit::test_runner()
{
    print_line();
    std::cout << BOLD << GREEN << "RUNNING TESTS...\n" << RESET;
    print_char_n('\n', 1);

    for (auto &test : tests)
    {
        std::cout << BOLD << test.first << "...\n" << RESET;
        test.second();
    }
}

void TestSuit::add_test(std::string test_name, TestFunction fPtr)
{
    tests.insert(
        {test_name, fPtr});
}

void TestSuit::reset()
{
    tests = {};
}
