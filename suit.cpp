#include "suit.h"
#include "utils.h"
#include <isotream>
#include <stdexcept>


class TestSuit {
    public:
        TestSuit()
            : tests{}
            , success_tracker{}
            , fail_msgs{}
        {}

        void run_tests() {
            test_runner();
            print_fails();
            print_summary();
        }

        void test_runner() {
            for (auto& test: tests) {
                std::cout << test.first << ": ";
                try {
                    test.second();
                    success_tracker.insert(
                        {test, true}
                    );
                    std::cout << "PASS" << std::endl;

                } catch (const std::runtime_error& e) {
                    fail_msgs.insert(
                        {test, e.what()}
                    );
                    success_tracker.insert(
                        {test, false}
                    );
                    std::cout << "FAIL" << std::endl;
                }
            }
        }

        void print_fails() {
            std::cout << "FAILS" << LINE << 
            std::cout << std::endl;

            for (auto& fail: fail_msgs) {
                std::cout << fail.first.first << "-->" << std::endl;
                std::cout << fail.second << std::endl;
            }
            print_line();
            std::cout << std::endl;
        }

        void print_summary() {
            int test_size = tests.size();
            int passes = count_passes();
            int fails = test_size - passes;

            std::cout << "SUMMARY";
            print_line();
            std::cout << std::endl;
            std::cout << "TESTS: " << test_size << ", ";
            std::cout << "PASSED: " << passes << ", ";
            std::cout << "FAILED: " << fails << std::endl;
            print_line();
            std::cout << std::endl;
        }

        void add_test(std::string test_name, TestFunction fPtr) {
            tests.insert(
                {test_name, fPtr}
            );
        }

        void reset() {
            tests = {};
            success_tracker = {};
            fail_msg = {};
        }

        int count_passes() {
            int count = 0;
            for (auto& test: success_tracker) {
                count += test.second;
            }
            return count;
        }
}