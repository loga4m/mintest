#include "../include/suit.h"
#include "../include/utils.h"
#include "../include/assertions/headers.h"
#include <vector>
#include <iostream>

void basic_vector_test()
{
    std::vector<int> myVec = {1, 2, 3};

    EXPECT_EQ(myVec, {1, 2, 3});
    EXPECT_EQ(myVec.at(0), 3);
    EXPECT_EQ(myVec.at(2), -10);

    myVec.push_back(2);

    EXPECT_EQ(myVec, {1, 2, 3, 2});
    EXPECT_EQ(myVec.front(), 1);
    EXPECT_EQ(myVec.back(), 2);
}

void basic_string_test()
{
    std::string myStr = "Hello world";

    EXPECT_EQ(std::string(myStr + "yeah"), std::string("Hello world yeah"));
    EXPECT_EQ(myStr[0], 'H');
}

void basic_math_test()
{
    EXPECT_EQ(1 + 2, 3);
    EXPECT_EQ(6 / 3, 2);
    EXPECT_EQ(6.0 / 3, 2.0);
}

int main()
{
    TestSuit TS;
    TS.add_test("Basic Vector Test", &basic_vector_test);
    TS.add_test("Basic String Test", &basic_string_test);
    TS.add_test("Basic Math Test", &basic_math_test);
    TS.run_tests();
    return 0;
}
