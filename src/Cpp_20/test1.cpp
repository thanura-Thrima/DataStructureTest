#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "Cpp_20Utils.cpp"
#include "gtest/gtest.h"

template<class T>
bool func(T t)
{
    if constexpr (std::is_arithmetic_v<T>)
    {
        std::cout<<t<<std::endl;
        return true;
    }else{
        std::cout<<" not a number"<<std::endl;
        return false;
    }
}

TEST(Cpp_20_1_1, Cpp20Test)
{

    Trangle* shape1 = new Trangle();

     EXPECT_EQ(true,func<float>(shape1->area()));

     EXPECT_EQ(false,func<std::string>(shape1->type()));

    delete shape1;
    shape1 = nullptr;
}
