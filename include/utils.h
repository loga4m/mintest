#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

template <typename ContainerT>
std::string container2string(const ContainerT &container);

template <typename ContainerT>
std::string array2string(const ContainerT &container, size_t container_size);

template <typename ContainerT>
std::string container2string_generic(
    const ContainerT &container,
    size_t container_size,
    bool supports_at);

void add_char_n_times(std::string &source, char ch, int n);
void print_char_n(char, int);
void print_line();

#include "implementations/utils_impl.hpp"

#endif
