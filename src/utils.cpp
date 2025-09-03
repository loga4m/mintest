#include "../include/utils.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


std::string vector2string(std::vector<std::string> vec)
{
    std::string result = "{";

    for (int i = 0; i < vec.size(); i++)
    {
        result += vec[i];
        if (i < vec.size() - 1)
        {
            result += ", ";
        }
    }
    result += "}";
    return result;
}

void add_char_n_times(std::string &source, char ch, int n)
{
    for (int i = 0; i < n; i++)
    {
        source += ch;
    }
}

void print_char_n(char ch, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << ch;
    }
}

void print_line()
{
    print_char_n('-', 80);
    std::cout << std::endl;
}
