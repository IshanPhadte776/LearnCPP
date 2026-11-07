#include <iostream>
//overloading via friend functions are good if there's no getters, friend functions are needed to access the private parts of classes
//non member works w/ geters 
class Point {
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z } {}

    friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

std::ostream& operator<<(std::ostream& out, const Point& p){
    out << p.m_x << p.m_y << p.m_z;

    return out;
}

int main () {
    Point p{1,2,3};

    std::cout << p << std::endl;
}