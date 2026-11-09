//calling a function virtual in a base class, name resolution of objects go from base to derived class


#include <iostream>
#include <string_view>

class Animal {
protected:
    std::string m_name;

public:
    Animal(std::string_view name) : m_name{ name } {}

    const std::string& getName() const { return m_name; }
    
    // Virtual function enables dynamic dispatch
    virtual std::string_view speak() const { return "???"; }
};

class Cat : public Animal {
public:
    Cat(std::string_view name) : Animal{ name } {}

    // Overrides Animal::speak()
    std::string_view speak() const { return "Meow"; }
};

class Dog : public Animal {
public:
    Dog(std::string_view name) : Animal{ name } {}

    // Overrides Animal::speak()
    std::string_view speak() const { return "Woof"; }
};

void report(const Animal& animal) {
    // Late binding: resolves to the dynamic object's speak()
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main() {
    Cat cat{ "Fred" };
    Dog dog{ "Garbo" };

    report(cat); // "Fred says Meow"
    report(dog); // "Garbo says Woof"

    return 0;
}