// Base::Function() allows for the base version of a function to be called through the derived object 

#include <iostream>

class Base {
public:
    void identify() const {
        std::cout << "Base::identify()\n";
    }
};

class Derived : public Base {
public:
    void identify() const {
        std::cout << "Derived::identify()\n";
    }
};

int main() {
    Derived d{};
    d.identify();        // Calls Derived::identify()
    d.Base::identify();  // Explicitly calls Base::identify()

    return 0;
}

//we can also extend the behaviour of the base class by  calling the base class version in the derived version first

class Derived : public Base {
public:
    void identify() const {
        Base::identify(); // Run base behavior first
        std::cout << "Adding extra derived logic here!\n";
    }
};


//name lookup happens before overload resolution  

//if a derived object calls a derived method, it will pick the definition in the derived class, ignoring the overloading in the base class

class Base {
public:
    void print(int x) {
        std::cout << "Base::print(int): " << x << '\n';
    }
    void print(double d) {
        std::cout << "Base::print(double): " << d << '\n';
    }
};

class Derived : public Base {
public:
    // This definition hides BOTH Base::print(int) and Base::print(double)!
    void print(std::string_view s) {
        std::cout << "Derived::print(string): " << s << '\n';
    }
};

int main() {
    Derived d{};
    d.print("Hello"); // OK: matches Derived::print(std::string_view)

    // d.print(5);    // COMPILE ERROR: Base::print(int) is hidden by Derived!
    
    // Explicit call still works:
    d.Base::print(5); // OK
}


//The solution 

class Derived : public Base {
public:
    // Bring all overloads of Base::print into Derived's scope:
    using Base::print; 

    // Add the new derived overload:
    void print(std::string_view s) {
        std::cout << "Derived::print(string): " << s << '\n';
    }
};

int main() {
    Derived d{};
    d.print(5);       // OK: calls Base::print(int)
    d.print(3.14);    // OK: calls Base::print(double)
    d.print("Hello"); // OK: calls Derived::print(string_view)
}

//How to delete specific function overloads 

//Method A - call using Base::function in the private section

class Derived : public Base {
private:
    using Base::printValue; // Disallows d.printValue()
};


//Method B is to delete it straight up 

class Base {
public:
    int getValue() const { return 5; }
};

class Derived : public Base {
public:
    // Mark getValue() as deleted in Derived:
    int getValue() const = delete;
};

int main() {
    Derived d{};
    // d.getValue(); // COMPILE ERROR: attempting to use a deleted function!

    // Still bypassable via static_cast to Base&:
    static_cast<Base&>(d).getValue(); // OK (calls Base::getValue)
}