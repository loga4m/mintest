#ifndef SUIT_H
#define SUIT_H
#include <unordered_map>
#include <vector>
#include <string>

using TestFunction = void (*)();

class TestSuit
{
private:
    std::unordered_map<std::string, TestFunction> tests;

public:
    TestSuit();
    void run_tests();
    void test_runner();
    void add_test(std::string test_name, TestFunction fPtr);
    void reset();
};

#endif