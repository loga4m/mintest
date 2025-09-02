#ifndef UTILS_H
#define UTILS_H
#define LINE "=========================================>"

template <typename T>
void EXPECT_EQ(T val1, T val2);
std::string EXPECT_EQ_MSG_GENERIC(std::string&, std::string&);
std::string vector2string(std::vector<T> vec);
void add_char_n_times(std::string& source, char ch, int n);
void print_char_n(char, int);
void print_line();

#endif