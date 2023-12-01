#include <stdint.h>
#include <vector>

template<class T>
struct Layer{
    T data;
    Layer* next = nullptr;
};

template<class T>
class Stack{
    Layer<T>* top;
    size_t size = 0;
    public:
    T peek()
    {
        if(size == 0)
        {
            return T();
        }
        return top->data;
    }

    T pop()
    {
        if(size == 0)
        {
            return T();
        }
        T temp = top->data;
        top = top->next;
        size--;
        return temp;
    }

    void push(T data)
    {
        Layer<T>* temp = top;
        top =new Layer<T>();
        top->data = data;
        top->next= temp;
        size++;
    }

};

template<class T>
class StackV2{
    std::vector<T> array;
    public:
    T peek()
    {
        if(size == 0)
        {
            return T();
        }
        return array[array.size()-1];
    }

    T pop()
    {
        if(size == 0)
        {
            return T();
        }
        T temp= array[array.size()-1];
        array.resize(array.size()-1);
        return temp;
    }

    void push(T data)
    {
        array.push_back(data);
    }

};