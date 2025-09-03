/* Tests by Claude.ai (and the author) */

#include <mintest/suit.h>
#include <mintest/utils.h>
#include <mintest/assertions/headers.h>
#include <vector>
#include <array>
#include <string>
#include <iostream>

void test_expect_eq_primitives()
{
    // Integer types
    EXPECT_EQ(42, 42);
    EXPECT_EQ(int(10), int(10));
    EXPECT_EQ(long(100L), long(100L));
    EXPECT_EQ(short(5), short(5));
    
    // Floating point
    EXPECT_EQ(3.14, 3.14);
    EXPECT_EQ(2.5f, 2.5f);
    EXPECT_EQ(double(1.0), double(1.0));
    
    // Character types
    EXPECT_EQ('a', 'a');
    EXPECT_EQ(char('z'), char('z'));
    
    // Boolean
    EXPECT_EQ(true, true);
    EXPECT_EQ(false, false);
}

void test_expect_eq_container()
{
    // Vector comparison
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    EXPECT_EQ_CONTAINER(vec1, vec2);


    std::vector<std::string> vec_str1 = {"Hello"};
    std::vector<std::string> vec_str2 = {"Hello"};
    EXPECT_EQ_CONTAINER(vec_str1, vec_str2);
    
    // Different element types
    std::vector<double> vec_double1 = {1.1, 2.2, 3.3};
    std::vector<double> vec_double2 = {1.1, 2.2, 3.3};
    EXPECT_EQ_CONTAINER(vec_double1, vec_double2);
    
    // Array containers
    std::array<int, 4> arr1 = {10, 20, 30, 40};
    std::array<int, 4> arr2 = {10, 20, 30, 40};
    EXPECT_EQ_CONTAINER(arr1, arr2);
    
    // Empty containers
    std::vector<int> empty1, empty2;
    EXPECT_EQ_CONTAINER(empty1, empty2);
}

void test_expect_eq_array()
{
    // Integer arrays
    int* arr1 = new int[4]{1, 2, 3, 4};
    int* arr2 = new int[4]{1, 2, 3, 4};
    EXPECT_EQ_ARRAY(arr1, 4, arr2, 4);
    delete[] arr1;
    delete[] arr2;
    
    // Double arrays
    double* darr1 = new double[3]{1.1, 2.2, 3.3};
    double* darr2 = new double[3]{1.1, 2.2, 3.3};
    EXPECT_EQ_ARRAY(darr1, 3, darr2, 3);
    delete[] darr1;
    delete[] darr2;
    
    // Character arrays
    char* carr1 = new char[3]{'a', 'b', 'c'};
    char* carr2 = new char[3]{'a', 'b', 'c'};
    EXPECT_EQ_ARRAY(carr1, 3, carr2, 3);
    delete[] carr1;
    delete[] carr2;
    
    // Stack arrays (cast to pointer)
    int stack_arr1[] = {10, 20, 30};
    int stack_arr2[] = {10, 20, 30};
    EXPECT_EQ_ARRAY(static_cast<int*>(stack_arr1), 3, static_cast<int*>(stack_arr2), 3);
    
    // Zero-size arrays
    int* null_arr1 = nullptr;
    int* null_arr2 = nullptr;
    EXPECT_EQ_ARRAY(null_arr1, 0, null_arr2, 0);
}

void test_expect_eq_str()
{
    // Basic string comparison
    std::string s1 = "hello";
    std::string s2 = "hello";
    EXPECT_EQ_STR(s1, s2);
    
    // Empty strings
    EXPECT_EQ_STR(std::string(""), std::string(""));
    
    // Concatenated strings
    std::string base = "test";
    EXPECT_EQ_STR(base + "_suffix", std::string("test_suffix"));
    
    // String literals to std::string
    EXPECT_EQ_STR(std::string("literal"), std::string("literal"));
    
    // Long strings
    std::string long1 = "This is a very long string for testing purposes";
    std::string long2 = "This is a very long string for testing purposes";
    EXPECT_EQ_STR(long1, long2);
}

int main()
{
    TestSuit TS;
    
    TS.add_test("EXPECT_EQ with Primitives", &test_expect_eq_primitives);
    TS.add_test("EXPECT_EQ_CONTAINER", &test_expect_eq_container);
    TS.add_test("EXPECT_EQ_ARRAY", &test_expect_eq_array);
    TS.add_test("EXPECT_EQ_STR", &test_expect_eq_str);
    
    TS.run_tests();
    return 0;
}
