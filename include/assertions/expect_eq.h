#ifndef EXPECT_EQ_H
#define EXPECT_EQ_H
#include "../utils.h"
#include <iostream>
#include <string>
#include <vector>


void EXPECT_EQ_MSG_GENERIC(
    const bool verdict,
    const std::string &,
    const std::string &);

void EXPECT_EQ(const std::string &val1, const std::string &val2);

template <typename U>
void EXPECT_EQ(const std::vector<U> &val1, const std::vector<U> &val2)
{
    bool verdict = val1 == val2;
    EXPECT_EQ_MSG_GENERIC(
        verdict,
        vector2string(val1),
        vector2string(val2));
}

template <typename T>
void EXPECT_EQ(const T &val1, const T &val2)
{
    bool verdict = val1 == val2;
    EXPECT_EQ_MSG_GENERIC(
        verdict,
        std::to_string(val1),
        std::to_string(val2));
}

#endif
