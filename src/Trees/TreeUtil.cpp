#include <stdint.h>
#include <vector>

template<class T>
struct Node{
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
    
    void add(Node* node)
    {
        if(this->data >= node->data)
        {
            if(left == nullptr)
                left = node;
            else    
                left->add(node);
        }else
        {
            if(right == nullptr)
                right = node;
            else
                right->add(node);
        }
    }
};

template<class T>
class Tree{
    public:
    Node<T>* root = nullptr;
    public:
    void insert(T data)
    {
        std::cout<<"data : "<<data<<std::endl;
        Node<T>* temp = new Node<T>();
        temp->data = data;

        if(root == nullptr)
        {
            std::cout<<"insert root"<<std::endl;
            root = temp;
            return;
        }
        std::cout<<"root available"<<std::endl;
        root->add(temp);

    }
};