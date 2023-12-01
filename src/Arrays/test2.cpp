#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

#include "gtest/gtest.h"


bool checkPermutation(std::string a, std::string b)
{
    if(a.empty() && b.empty()) return true;

    if(a.size()==b.size())
    {
        std::unordered_map<char,int> map;
        for(int i = 0 ; i<a.size();i++ )
        {
            int count = map[a[i]];
            if(count ==0)
            {
                map[a[i]]=count+1;
            }   
            else 
            {
                map[a[i]]=count+1;
            }

        }
        for(int i = 0 ; i<b.size();i++)
        {
            int count = map[b[i]];
            if(count <= 0)
            {
                return false;
            }else {
                map[b[i]] = count-1;
            }
        }
        return true;

    }else{
        return false;
    }
}

TEST(ArrayTest,ArrayTest2_1)
{
    EXPECT_EQ(true, checkPermutation("",""));
}

TEST(ArrayTest,ArrayTest2_2)
{
    EXPECT_EQ(false, checkPermutation("","a"));
}

TEST(ArrayTest,ArrayTest2_3)
{
    EXPECT_EQ(false, checkPermutation("aa",""));
}


TEST(ArrayTest,ArrayTest2_4)
{
    EXPECT_EQ(true, checkPermutation("abcd","cdab"));
}

TEST(ArrayTest,ArrayTest2_5)
{
    EXPECT_EQ(false, checkPermutation("abcd","cdb"));
}

TEST(ArrayTest,ArrayTest2_6)
{
    EXPECT_EQ(false, checkPermutation("abcd","ccdb"));
}

TEST(ArrayTest,ArrayTest2_7)
{
    EXPECT_EQ(true, checkPermutation("abcd","abcd"));
}

TEST(ArrayTest,ArrayTest2_8)
{
    EXPECT_EQ(false, checkPermutation("aaabcd","aabcde"));
}

TEST(ArrayTest,ArrayTest2_9)
{
    EXPECT_EQ(true, checkPermutation("aabcd","abcda"));
}