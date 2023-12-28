
#include <vector>
#include <string>
#include <concepts>


class Shape{
    public:
    virtual float area() = 0;

};

class Trangle: public Shape
{
    public:
     float area()
     {
        return 50.0;
     }
     std::string type()
     {
        return "Trangle";
     }

};
/*
template<class T, class Ts>
concept same_as_any = (... or std::same_as<T, Ts>); 


template <Types... TFoos>
class shapeList
{
    public:
    template <same_As_any<<TFoos...> T>
    auto store(T value){
        return std::get<std::vector<T>>(data).push_back(value);
    }

    private:
    std::tuple<std::vector<TFoos>...> data();
};
*/