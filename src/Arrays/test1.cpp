#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

#include "gtest/gtest.h"


bool isUnique(std::string str)
{
    if(str.empty()) return true;

    std::unordered_set<char> map;

    for(int i=0 ; i<str.size();i++)
    {
        if(map.find(str[i])!= map.end())
        {
            return false;
        }
        map.insert(str[i]);
    }
    return true;
}


bool isUniqueV2(std::string str)
{
    if(str.empty()) return true;

    std::sort(str.begin(),str.end());
    char a = str[0];
    for(int i=1 ; i<str.size();i++)
    {
        if(a == str[i])
        {
            return false;
        }
        a= str[i];
    }
    return true;
}


TEST(ArrayTest1_1, ArrayTest)
{
    EXPECT_EQ(true, isUnique(""));
}

TEST(ArrayTest1_2, ArrayTest)
{
    EXPECT_EQ(true, isUnique("abcd"));
}

TEST(ArrayTest1_3, ArrayTest)
{
    EXPECT_EQ(false, isUnique("abad"));
}


TEST(ArrayTest1_4, ArrayTest)
{
    EXPECT_EQ(true, isUnique("ab_d c"));
}

TEST(ArrayTest1_1V2, ArrayTest)
{
    EXPECT_EQ(true, isUniqueV2(""));
}

TEST(ArrayTest1_2V2, ArrayTest)
{
    EXPECT_EQ(true, isUniqueV2("abcd"));
}

TEST(ArrayTest1_3V3, ArrayTest)
{
    EXPECT_EQ(false, isUniqueV2("abad"));
}


TEST(ArrayTest1_4V4, ArrayTest)
{
    EXPECT_EQ(true, isUniqueV2("ab_d c"));
}