//pointer to a pointer / double pointer stores a memory address of another pointer 

// [ value: 5 ]  <--- (address: 0x100)
//      ▲
// [ ptr: 0x100 ] <--- (address: 0x200)
//      ▲
// [ ptrptr: 0x200 ]

//double pointer gotta be dereference twice, once gets to ptr, twice to get value 5 

#include <iostream>

int main() {
    int value{ 5 };

    int* ptr{ &value };
    int** ptrptr{ &ptr };

    std::cout << "value:    " << value << '\n';    // 5
    std::cout << "*ptr:     " << *ptr << '\n';     // 5
    std::cout << "**ptrptr: " << **ptrptr << '\n'; // 5

    // Modify the original value through double dereferencing:
    **ptrptr = 10;
    std::cout << "value after modification: " << value << '\n'; // 10

    return 0;
}

//traditonally, the usage of double pointers was for 2D arrays in C and early C++
//cache locality and spaital awareness was awful for this stuff 


int** ptrptr{ nullptr }; // this makes the double pointer point to the null pointer / stores the memory address of the nullptr 

*ptrptr = nullptr; //this makes the the int* point to the nullptr 