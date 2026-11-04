#include <iostream>

class Foo {
private:
    int m_x{};

public:
    Foo(int x) : m_x{ x } {} // Converting constructor (int -> Foo)
    int getX() const { return m_x; }
};

void printFoo(Foo f) {
    std::cout << f.getX() << '\n';
}

int main() {
    printFoo(5); // Compiles! Implicitly converts 5 to temporary Foo{ 5 }
    return 0;
}



class MyString {
public:
    MyString(int capacity); // Allocates a buffer of size `capacity`
    MyString(const char* str);
};

void printString(const MyString& s);

int main() {
    printString('x'); // BUG: 'x' is a char, implicitly converts to int (ASCII 120)!
                      // Allocates a 120-byte empty buffer instead of printing "x".
}

//Can lead to issues here, converts char -> int (preffered, remember numeric conversion)

class Foo {
private:
    int m_x{};

public:
    explicit Foo(int x) : m_x{ x } {} // Cannot be used for implicit conversions
    int getX() const { return m_x; }
};

void printFoo(Foo f);

int main() {
    // printFoo(5);     // COMPILE ERROR: Cannot implicitly convert int to Foo
    // Foo f = 5;       // COMPILE ERROR: Copy-initialization not allowed

    printFoo(Foo{ 5 }); // OK: Explicit direct-list-initialization
    Foo f1{ 5 };        // OK: Direct-list-initialization
    Foo f2(5);          // OK: Direct initialization
    Foo f3 = Foo{ 5 };  // OK: Explicit temporary
}