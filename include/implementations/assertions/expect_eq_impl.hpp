#pragma once
#include "../../overloads/to_string.h"
#include "../../assertions/expect_eq.h"

template <typename T>
void EXPECT_EQ_ARRAY(const T &arr1, size_t arr1_size, const T &arr2, size_t arr2_size)
{
    bool verdict = true;

    if (arr1_size != arr2_size)
    {
        verdict = false;
    }
    else
    {
        for (size_t i = 0; i < arr1_size; i++)
        {
            if (arr1[i] != arr2[i])
                verdict = false;
        }
    }

    EXPECT_EQ_MSG_GENERIC(
        verdict,
        array2string(arr1, arr2_size),
        array2string(arr2, arr2_size));
}

template <typename ContainerT>
void EXPECT_EQ_CONTAINER(const ContainerT &val1, const ContainerT &val2)
{
    bool verdict = true;

    if (val1.size() != val2.size())
    {
        verdict = false;
    }
    else
    {
        for (size_t i = 0; i < val1.size(); i++)
        {
            if (val1.at(i) != val2.at(i))
                verdict = false;
        }
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
        mintest::to_string(val1),
        mintest::to_string(val2));
}
