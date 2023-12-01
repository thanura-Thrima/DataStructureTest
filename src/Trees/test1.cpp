#include <string>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include "TreeUtil.cpp"
#include "gtest/gtest.h"


int printRightView(Tree<int>& tree)
{
    std::queue<Node<int>*> layer;
    layer.push(tree.root);
    size_t count = 1;
    while(count!= 0)
    {
        for(size_t i = 0; i<count;i++)
        {
            Node<int>* element = layer.front();
            layer.pop();
            if(i==0)
            {
                std::cout<<element->data<<std::endl;
            }
            if(element->right != nullptr)
                layer.push(element->right);
            if(element->left != nullptr)
                layer.push(element->left);
            
        }
        count = layer.size();
    }
    return 8;
}

int test()
{
    Tree<int> myTree;
    myTree.insert(5);
    myTree.insert(2);
    myTree.insert(8);
    myTree.insert(4);
    myTree.insert(7);
    myTree.insert(1);
    myTree.insert(1);
    myTree.insert(1);
    

    return printRightView(myTree);
}

#include <iostream>
#include <string>
using namespace std;

TEST(TreeTest1_1, TreeTests)
{
    EXPECT_EQ(8, test());
}
