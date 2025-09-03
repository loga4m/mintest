#pragma once
#include <iostream>
#include <string>
#include "../overloads/to_string.h"

template <typename ContainerT>
std::string container2string(const ContainerT &container)
{
    std::string result = "{";

    for (size_t i = 0; i < container.size(); i++)
    {
        result += mintest::to_string(container.at(i));
        if (i + 1 < container.size()) {
            result += ", ";
        }
    }
    result += "}";
    return result;
}

template <typename ContainerT>
std::string array2string(const ContainerT &container, size_t container_size)
{
    std::string result = "{";

    for (size_t i = 0; i < container_size; i++)
    {
        result += mintest::to_string(container[i]);
        if (i + 1 < container_size) {
            result += ", ";
        }
    }
    result += "}";
    return result;
}
