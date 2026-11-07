//Shallow Copy, take the base object, takes each field and copies and pastes them over 
//copies fundemental types, bit by bit

//Issue, what happens when the original object manages memory via a raw pointer 
//This means the second object will point the the same memory address. 
//here, the first object has a pointer to a memory address for m_data
//second object of mystring copies the same memory address 
//Dangling pointer, if 1 objec goes out of scope, then the other object has a dangling pointer

#include <cstring>
#include <iostream>

class MyString {
private:
    char* m_data{};
    int m_length{};

public:
    MyString(const char* source = "") {
        m_length = static_cast<int>(std::strlen(source)) + 1;
        m_data = new char[m_length];
        std::copy(source, source + m_length, m_data);
    }

    ~MyString() {
        delete[] m_data; // Frees dynamic memory
    }

    // Relying on compiler-generated default copy constructor:
    // MyString(const MyString& source) = default;
};

//Mutating the variable (memory address)


//Deep Copy allocates space on the heap for the new object, copies the actual contents from the source buffer 
//each object gets its own, seperate memory / data to manage