#ifndef SUIT_H
#define SUIT_H
#include <unordered_map>
#include <vector>
#include <string>

using TestFunction = void (*)();

class TestSuit {
    private:
        std::unordered_map<std::string, TestFunction> tests;
        std::unordered_map<auto, bool> success_tracker;
        std::unordered_map<auto, std::string> fail_msgs;
    public:
        TestSuit();
        void run_tests();
        void test_runner();
        void print_fails();
        void print_summary();
        void add_test(std::string test_name, TestFunction fPtr);
        void reset();
        int count_passes();
}

#endif