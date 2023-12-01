#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

#include "gtest/gtest.h"

bool oneWay(std::string str1,std::string str2)
{
    if(str1.size()<2 && str1.size()<2) return true;

    // changes
    int changesCount = 0;
    if(str1.size() == str2.size())
    {
        for(int i = 0; i<str2.size();i++)
        {
            if(str2[i] != str1[i])
            {
                if(changesCount>0)
                {
                    return false;
                }
                changesCount++;
            
            }
        }
        return true;
    }
    //check delete and insert
    if(str1.size()>str2.size())
    {
        if(str1.size() - str2.size()>1)
        {
            return false;  // more than one insertion or deletion
        }
        bool insertionDetected = false;
        for(int i = 0,j = 0; i<str2.size();i++,j++)
        {
            if(str2[i] != str1[j])
            {
                if(insertionDetected)
                {
                    return false;
                }
                insertionDetected = true;
                j++;
            }
        }
        return true;

    }else
    {
        return oneWay(str2,str1);
    }

    return false;
}


TEST(ArrayTest5_1, ArrayTest)
{
    EXPECT_EQ(true, oneWay("","x"));
}

TEST(ArrayTest5_2, ArrayTest)
{
    EXPECT_EQ(true, oneWay("abc","abc"));
}

TEST(ArrayTest5_3, ArrayTest)
{
    EXPECT_EQ(true, oneWay("abc","abd"));
}


TEST(ArrayTest5_4, ArrayTest)
{
    EXPECT_EQ(true, oneWay("acdde","abdde"));
}


TEST(ArrayTest5_5, ArrayTest)
{
    EXPECT_EQ(false, oneWay("abbcc","abcbc"));
}


TEST(ArrayTest5_6, ArrayTest)
{
    EXPECT_EQ(true, oneWay("abcdefg","abdefg"));
}


