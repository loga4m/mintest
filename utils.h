#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


void EXPECT_EQ_MSG_GENERIC(
    const bool verdict,
    const std::string&,
    const std::string&
);
void EXPECT_EQ(const std::string val1, const std::string val2);

template <typename T>
std::string vector2string(std::vector<T> vec) {
    std::string result = "{";

    for (int i = 0; i < vec.size(); i++) {
        result += std::to_string(vec[i]);
        if (i < vec.size() - 1) {
            result += ", ";
        }
    }
    result += "}";
    return result;
}

template <typename U>
void EXPECT_EQ(const std::vector<U> val1, const std::vector<U> val2) {
    bool verdict = val1 == val2;
    EXPECT_EQ_MSG_GENERIC(
        verdict,
        vector2string(val1),
        vector2string(val2)
    );
}

template <typename T>
void EXPECT_EQ(const T val1, const T val2) {
    bool verdict = val1 == val2;
    EXPECT_EQ_MSG_GENERIC(
        verdict,
        std::to_string(val1),
        std::to_string(val2)
    );
}


void add_char_n_times(std::string& source, char ch, int n);
void print_char_n(char, int);
void print_line();

#endif
