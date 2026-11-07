//unqiue / smart pointers enable runtime polymorphism (which prevents object slicing)
//allows for dynamic dispatch, doesn't slice derived objects 
//smart pointers allow for the base pointer to preserve all details of the derived object


#include <iostream>
#include <memory>
#include <vector>

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default; // Essential for virtual cleanup!
};

class Circle : public Shape {
public:
    void draw() const override { std::cout << "Drawing Circle\n"; }
};

class Rectangle : public Shape {
public:
    void draw() const override { std::cout << "Drawing Rectangle\n"; }
};


int main (){
    //polymorphive containers, only works with the unqiue ptr wrapping, w/o, the Circle / Rectangel object would have their dervived portion slcied off, only retaining their shape portion
    std::vector<std::unique_ptr<Shape>> scene;

    scene.push_back(std::make_unique<Circle>());
    scene.push_back(std::make_unique<Rectangle>());

    for (const auto& shape : scene) {
        shape->draw(); // Virtual dispatch works cleanly
    }

    return 0;
}