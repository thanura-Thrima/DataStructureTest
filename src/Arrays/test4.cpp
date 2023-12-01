#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

#include "gtest/gtest.h"


bool isPalandrom(std::string str)
{
    if(str.size()<2) return true;
    std::unordered_map<char, int> map;
    for(int i =0; i<str.size();i++)
    {
        auto it = map.find(str[i]);
        if(it!= map.end())
        {
            map[str[i]] =map[str[i]]+1;

        }else{
            map[str[i]]= 1;
        }
    }
    int singleCount = 0;
    for(auto it = map.begin(); it!= map.end(); it++)
    {
        if(it->second%2 == 1)
        {
            singleCount++;
            if(singleCount>1)
            {
                return false;
            }
        }
    }

    return true;
}




TEST(ArrayTest4_1, ArrayTest)
{
    EXPECT_EQ(true, isPalandrom(""));
}

TEST(ArrayTest4_2, ArrayTest)
{
    EXPECT_EQ(true, isPalandrom("a"));
}


TEST(ArrayTest4_3, ArrayTest)
{
    EXPECT_EQ(true, isPalandrom("aba"));
}


TEST(ArrayTest4_4, ArrayTest)
{
    EXPECT_EQ(true, isPalandrom("bbbaa"));
}

TEST(ArrayTest4_5, ArrayTest)
{
    EXPECT_EQ(true, isPalandrom("abab"));
}

TEST(ArrayTest4_6, ArrayTest)
{
    EXPECT_EQ(false, isPalandrom("aababxyyydd"));
}

TEST(ArrayTest4_7, ArrayTest)
{
    EXPECT_EQ(false, isPalandrom("ab"));
}