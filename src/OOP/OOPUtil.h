#pragma once


class Shape
{
    public:
    Shape();
    Shape(const Shape& other);
    Shape(Shape&& other);
    virtual ~Shape() = 0;
    
    private:
    int m_edges{0};
    double m_area{0.0};
};


class Trangle: public Shape
{
    public:
    Trangle();
    ~Trangle();
    Trangle(const Trangle& other);
    Trangle( Trangle&& other);
};

class ShapeFactory{
    public:
    enum class ShapeType{
        Trangle,
        Rectangle
    };
    ShapeFactory() = delete;
    static Shape* getShape(ShapeType type);
};