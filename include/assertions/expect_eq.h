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

template <typename T>
void EXPECT_EQ_ARRAY(const T &arr1, size_t arr1_size, const T &arr2, size_t arr2_size);

template <typename ContainerT, typename ContainerU>
void EXPECT_EQ_CONTAINER(const ContainerT &val1, const ContainerU &val2);

template <typename T>
void EXPECT_EQ(const T &val1, const T &val2);

// Template implementation
#include "../implementations/assertions/expect_eq_impl.hpp"

#endif
