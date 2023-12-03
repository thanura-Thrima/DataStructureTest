#include <iostream>
#include "OOPUtil.h"

Shape::Shape(){
    std::cout<<"Constructor :"<<__FUNCTION__<<std::endl;
}

Shape::Shape(const Shape& other){
    std::cout<<"Copy Constructor :"<<__FUNCTION__<<std::endl;
    this->m_area = other.m_area;
    this->m_edges = other.m_edges;
}

Shape::Shape(Shape&& other){
    std::cout<<"Move Constructor :"<<__FUNCTION__<<std::endl;
    this->m_area = other.m_area;
    this->m_edges = other.m_edges;
}

Shape::~Shape(){
    std::cout<<"Destructor :"<<__FUNCTION__<<std::endl;
}

Trangle::Trangle():Shape()
{
    std::cout<<"Constructor :"<<__FUNCTION__<<std::endl;
}


Trangle::~Trangle()
{
    std::cout<<"Distructor :"<<__FUNCTION__<<std::endl;
}

Trangle::Trangle(const Trangle& other):Shape(other){

    std::cout<<"Copy Constructor :"<<__FUNCTION__<<std::endl;
}

Trangle::Trangle(Trangle&& other):Shape(std::move(other)){
    std::cout<<"Move Constructor :"<<__FUNCTION__<<std::endl;
}


///////////////////////////// ShapeFactory //////////////////////

Shape* ShapeFactory::getShape(ShapeFactory::ShapeType type)
{
    Shape* ret = nullptr;
    switch(type)
    {
        case ShapeType::Trangle :{
            ret = new Trangle();
            break;
        }
        default:
        {

        }
    }
    return ret;
}