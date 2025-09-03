#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

template <typename ContainerT>
std::string container2string(const ContainerT &container)
{
    std::string result = "{";

    for (int i = 0; i < container.size(); i++)
    {
        result += std::to_string(container.at(i));
        if (i < container.size() - 1)
        {
            result += ", ";
        }
    }
    result += "}";
    return result;
}


void add_char_n_times(std::string &source, char ch, int n);
void print_char_n(char, int);
void print_line();

#endif
