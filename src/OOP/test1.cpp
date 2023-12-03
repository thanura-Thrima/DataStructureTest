#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "OOPUtil.h"
#include "gtest/gtest.h"



TEST(OOP1_1, OOPTest)
{


    Shape* shape1 = new Trangle();

    EXPECT_EQ(true, shape1 != nullptr);

    delete shape1;
    shape1 = nullptr;
}


TEST(OOP1_2, OOPTest)
{

    Shape* shape1 = new Trangle();

    Shape* shape2 = new Trangle(*reinterpret_cast<Trangle*>(shape1));

    EXPECT_EQ(true, shape2 != nullptr);

    delete shape1;
    delete shape2;
    shape1 = nullptr;
    shape2 = nullptr;
}


TEST(OOP1_3, OOPTest)
{

    Trangle trangle1;

    Trangle shape2 = std::move(trangle1);

    EXPECT_EQ(true, &shape2 != nullptr);
}
