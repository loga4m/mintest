# mintest
Minimal testing framework for C++.

|> Just runs tests, shows what values were given, and presents the verdict on the fly (with colors!).

You can use to test your DSA implementations. Here is a **quick** example.

```cpp
#include "suit.h"
#include "utils.h"
#include <vector>
#include <iostream>

void basic_vector_test()
{
    std::vector<int> myVec = {1, 2, 3};
    EXPECT_EQ(myVec, {1, 2, 3});
    myVec.push_back(2);
    EXPECT_EQ(myVec, {1, 2, 3, 2});
}

void basic_string_test()
{
    std::string myStr = "Hello world";
    EXPECT_EQ(myStr[0], 'H');
}

void basic_math_test()
{
    EXPECT_EQ(1 + 2, 3);
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
```


**P.S**.: *It may feel childish or un-smart, but I am primarily going to use to test my DSA implementations.*
