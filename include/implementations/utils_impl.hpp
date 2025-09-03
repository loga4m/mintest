#pragma once
#include <iostream>
#include <string>

template <typename ContainerT>
std::string container2string(const ContainerT &container)
{
    std::string result = "{";

    for (int i = 0; i < container.size(); i++)
    {
        result += std::to_string(container.at(i));
    }
    result += "}";
    return result;
}

template <typename ContainerT>
std::string array2string(const ContainerT &container, size_t container_size)
{
    std::string result = "{";

    for (int i = 0; i < container_size; i++)
    {
        result += std::to_string(container[i]);
    }
    result += "}";
    return result;
}
