template <typename T>
class Storage {
private:
    T m_value{};
public:
    Storage(T value) : m_value{ value } {}
    ~Storage() = default;

    void print() const { std::cout << m_value << '\n'; }
};

//This code works fine for Storage<int> or Storage<double>, the print prints the value of m_value, its chill

//For Storage<int*>, it gets dicey. std::cout << m_value(type of int*) prints the memory address 

//Shallow pointer semantics -> this container stores mere pointers, if the objects that the pointers point to are deallocated, the pointers become dangling 

// Destructor Dilemma, who calls delete?

//OVerall, best to have a partial specialization for T*

#include <iostream>

// Primary template for non-pointers
template <typename T>
class Storage {
private:
    T m_value{};
public:
    Storage(T value) : m_value{ value } {}
    ~Storage() = default;

    void print() const {
        std::cout << m_value << '\n';
    }
};

// Partial specialization for ANY pointer type T*
template <typename T>
class Storage<T*> {
private:
    T* m_value{};
public:
    // Takes a pointer, makes a dynamic deep copy
    Storage(T* value) {
        if (value)
            m_value = new T{ *value }; // Deep-copy the single value
    }

    // Safely free the allocated copy
    ~Storage() {
        delete m_value;
    }

    // Dereference when printing
    void print() const {
        if (m_value)
            std::cout << *m_value << '\n';
        else
            std::cout << "nullptr\n";
    }
};

//Char* pitfall 
//this is a C style string literal 
Storage<char*> stringStorage{ "Hello, world!" };

//The type T is deduced as char, because the specialization is for T*, T = char, so we get char* 
//m_value is just the first char, not the whole string (multiple chars)
m_value = new char{ *value }; 

//Solution is for a whole new specialization just for char* (C Style strings)

#include <cstring>

// Full specialization for C-style strings
template <>
class Storage<char*> {
private:
    char* m_value{};
public:
    Storage(const char* value) {
        if (value) {
            // Allocate memory for entire string including null terminator
            m_value = new char[std::strlen(value) + 1];
            std::strcpy(m_value, value);
        }
    }

    ~Storage() {
        delete[] m_value; // Array delete
    }

    void print() const {
        if (m_value)
            std::cout << m_value << '\n'; // Prints full string, not just 1st char
        else
            std::cout << "nullptr\n";
    }
};

