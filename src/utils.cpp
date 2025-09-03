#include "../include/utils.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

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
