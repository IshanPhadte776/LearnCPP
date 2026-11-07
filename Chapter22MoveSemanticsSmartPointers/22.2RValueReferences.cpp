int x{ 5 };

int& lref{ x }; // OK: l-value reference binds to l-value
// int& lref2{ 5 }; // COMPILE ERROR: cannot bind non-const l-value ref to r-value

int&& rref1{ 5 };      // OK: r-value reference binds directly to temporary literal
int&& rref2{ x + 1 };  // OK: binds to temporary expression result
// int&& rref3{ x };   // COMPILE ERROR: cannot bind r-value ref to an l-value!

int&& rref{ 10 };
rref = 20; // Completely legal! Modifies the underlying temporary storage

#include <iostream>

void process(const int& lref) {
    std::cout << "l-value reference (COPY semantics): " << lref << '\n';
}

void process(int&& rref) {
    std::cout << "r-value reference (MOVE semantics): " << rref << '\n';
}

int main() {
    int x{ 42 };

    process(x);     // 'x' is an l-value -> calls process(const int&)
    process(100);   // '100' is an r-value -> calls process(int&&)
    process(x + 2); // 'x + 2' is an r-value -> calls process(int&&)
}