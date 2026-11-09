//In the constructor member initialization list, its a blind spot for exceptions to occur, nothing at first can handle an exception that occurs there 

class A {
public:
    A(int x) {
        if (x <= 0)
            throw "A failed!";
    }
};

class B {
private:
    A m_a;
public:
    // How do you catch an exception thrown by m_a(x) here?
    B(int x) : m_a{ x } {
        // A regular try-catch inside this body is too late!
        // m_a is already initialized before the opening brace '{' is reached.
    }
};


//Solution - add a try block there anyways 

#include <iostream>

class A {
private:
    int m_x{};
public:
    A(int x) : m_x{ x } {
        if (x <= 0)
            throw "Error: x must be positive";
    }
};

class B {
private:
    A m_a;

public:
    // 'try' comes before the colon ':' of the initializer list
    B(int x) try: m_a{x} {
        // Constructor body runs if initialization succeeds
        std::cout << "B successfully created\n";
    }
    catch (const char* exception) {
        // Catches exceptions thrown by m_a's constructor OR B's constructor body
        std::cerr << "Caught exception in B: " << exception << '\n';
        
        // WHAT HAPPENS HERE? (See Rule #3 below)
    }
};