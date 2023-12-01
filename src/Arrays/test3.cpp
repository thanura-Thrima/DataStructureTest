#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "gtest/gtest.h"
#include <sstream>

std::string URLify(std::string a)
{
    if(a.empty()) return a;
    a.erase(a.find_last_not_of(" \n\r\t")+1);

    for(int i = 0;i<a.size();i++)
    {
        if(a[i]==' ')
        {
            a.replace(i,1,"%20");
        }
    }
    return a;
}

std::string URLify(char* a, int count)
{
    if(count <= 0) return std::string(a);
    int spaceCount = 0;
    int i;
    for(i = 0;i<count;i++)
    {
        if(a[i]==' ')
        {
            spaceCount++;
        }
    }

    while(a[i-1]==' ')
    {
        spaceCount--;
        i--;
    }
    int new_length = i + spaceCount * 2 + 1;
    int index = new_length - 1;
    a[index--] = '\0';
 
    // Fill rest of the string from end
    for (int j=i-1; j>=0; j--)
    {
        // inserts %20 in place of space
        if (a[j] == ' ')
        {
            a[index] = '0';
            a[index - 1] = '2';
            a[index - 2] = '%';
            index = index - 3;
        }
        else
        {
            a[index] = a[j];
            index--;
        }
    }

    return std::string(a);
}

TEST(ArrayTest,ArrayTest3_1)
{
    std::string a = "";
    std::string b = "";
    EXPECT_STREQ(a.c_str(), URLify(b).c_str());
}


TEST(ArrayTest,ArrayTest3_2)
{
    std::string a = "abc";
    std::string b = "abc";
    EXPECT_STREQ(a.c_str(), URLify(b).c_str());
}

TEST(ArrayTest,ArrayTest3_3)
{
    std::string a = "ab c";
    std::string b = "ab%20c";
    EXPECT_STREQ(b.c_str(), URLify(a).c_str());
}

TEST(ArrayTest,ArrayTest3_4)
{
    std::string a = "ab c  ";
    std::string b = "ab%20c";
    EXPECT_STREQ(b.c_str(), URLify(a).c_str());
}

//TEST(ArrayTest,ArrayTest3_5)
//{
//    std::string a = "ab c  ";
//    std::string b = "ab%20c";
//    EXPECT_STREQ(b.c_str(), URLify((char *)a.c_str(),a.size().c_str()));
//}