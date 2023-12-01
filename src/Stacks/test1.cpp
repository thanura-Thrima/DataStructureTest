#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "StackUtil.cpp"
#include "gtest/gtest.h"


int test()
{
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    

    myStack.pop();
    myStack.pop();
    myStack.push(4);
    std::cout<< " value at top: "<<myStack.peek()<<std::endl;
    return myStack.peek();

}


TEST(ArrayTest1_1, StackTest)
{
    EXPECT_EQ(3, test());
}
