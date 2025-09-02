#include "utils.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


template <typename T>
void EXPECT_EQ(T val1, T val2) {
    std::string err_msg;
    if (val1 != val2) {
        err_msg = EXPECT_EQ_MSG_GENERIC(
            std::to_string(val1),
            std::to_string(val2)
        );
        throw std::runtime_error()
    }
}

void EXPECT_EQ(std::string val1, std::string val2) {
    std::string err_msg;
    if (val1 != val2) {
        err_msg = EXPECT_EQ_MSG_GENERIC(val1, val2);
        throw std::runtime_error()
    }
}

template <typename U>
void EXPECT_EQ(std::vector<U> val1, std::vector<U> val2) {
    std::string err_msg;
    if (val1 != val2) {    
        err_msg = EXPECT_EQ_MSG_GENERIC(
            vector2string(val1),
            vector2string(val2)
        );
        throw std::runtime_error(err_msg)
    }  
}

std::string EXPECT_EQ_MSG_GENERIC(std::string& value1, std::string& value2) {
        add_char_n_times(err_msg, '-', 5);
        add_char_n_times(err_msg, '\n', 1);
        add_char_n_times(err_msg, ' ', 5);
        err_msg += "Value 1: ";
        err_msg += value1;
        err_msg += ", ";
        err_msg += "Value 2: ";
        err_msg += value2;
        add_char_n_times(err_msg, '\n', 1);
}

std::string vector2string(std::vector<std::string> vec) {
    std::string result = "{";

    for (int i = 0; i < vec.size(); i++) {
        result += vec[i];
        if (i < vec.size() - 1) {
            result += ", ";
        }
    }
    result += "}";
    return result;
}

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

void add_char_n_times(std::string& source, char ch, int n) {
    for (int i = 0; i < n; i++) {
        source += ch;
    }
}

void print_char_n(char ch, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << ch;
    }
}

void print_line() {
    std::cout << LINE;
}