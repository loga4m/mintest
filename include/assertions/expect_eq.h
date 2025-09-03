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

void EXPECT_EQ_STR(const std::string &val1, const std::string &val2);

template <typename ContainerT>
void EXPECT_EQ_CONTAINER(const ContainerT &val1, const ContainerT &val2)
{
    bool verdict = false;
    if (val1.size() == val2.size()) {
        for (size_t i = 0; i < val1.size(); i++) {
            if (val1.at(i) != val2.at(i))
                break;
        }
        verdict = true;
    }
    EXPECT_EQ_MSG_GENERIC(
        verdict,
        container2string(val1),
        container2string(val2));
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
