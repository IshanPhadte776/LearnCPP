#include <iostream>

//member function
struct Date {
    int year {};
    int month {};
    int day {};

    // Member function declared inside the struct
    void print() {
        std::cout << year << '/' << month << '/' << day << '\n';
    }

    // Const member function: guarantees it will not mutate member variables
    void print2() const {
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main() {
    Date today{ 2026, 11, 3 };

    // Called on the object using the member selection operator (.)
    today.print(); // Prints: 2026/11/3
    return 0;
}