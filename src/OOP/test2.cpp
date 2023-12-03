#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "OOPUtil.h"
#include "gtest/gtest.h"



TEST(OOP2_1, OOPTest)
{
    Shape* trangle1 = ShapeFactory::getShape(ShapeFactory::ShapeType::Trangle);
    EXPECT_EQ(true, trangle1 != nullptr);

    delete trangle1;
    trangle1 = nullptr;
}