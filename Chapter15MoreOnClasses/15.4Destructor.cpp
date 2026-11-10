//For Local Stack storage duration -> runs out of order of creation when object goes out of scope 

//for dynamically allocated object, runs on calling delete

//for static / global objects, called at program termination 


//no need for custom destructor if the class only holds standard primitives (int, double) and / or variables that manage its own resrouces (std::String , std::vector)

//custo destructor is needed for member variables that don't manage memory autoamtually and need a "delete" call

#include <iostream>
#include <cassert>

class IntArray {
private:
    int* m_array{};
    int  m_length{};

public:
    IntArray(int length) : m_length{ length } {
        assert(length > 0);
        m_array = new int[static_cast<std::size_t>(length)]{};
    }

    // Custom destructor cleans up raw heap memory
    ~IntArray() {
        delete[] m_array;
    }

    void setValue(int index, int value) { m_array[index] = value; }
    int getValue(int index) const { return m_array[index]; }
};

int main() {
    IntArray arr{ 10 };
    arr.setValue(0, 42);
    // arr goes out of scope -> ~IntArray() automatically frees m_array memory!
    return 0;
}