//std::initialization_list is a lightweight proxy object that provides access to an array of const T objects \

//in the {}, a std::initialization_list of 4 ints is passed 
std::vector<int> v{10,20,30,40};

//under the hood, the complier makes a hidden, contigious array of const int {10,20,30,40}
// complier creates a std::initialization_list<int> and pointers to this array 
//init list is just 2 pointers(start pointer and size), begin() and end()

#include <initializer_list>
#include <algorithm>
#include <iostream>

class SimpleList {
private:
    int* m_data{};
    int m_size{};

public:
    // Initializer-list constructor:
    SimpleList(std::initializer_list<int> list)
        : m_size{ static_cast<int>(list.size()) }
        , m_data{ new int[list.size()] } 
    {
        // Copy elements from the initializer_list proxy into our heap buffer:
        std::copy(list.begin(), list.end(), m_data);
    }

    ~SimpleList() {
        delete[] m_data;
    }

    void print() const {
        for (int i = 0; i < m_size; ++i)
            std::cout << m_data[i] << ' ';
        std::cout << '\n';
    }
};

int main() {
    SimpleList numbers{ 5, 10, 15, 20 }; // Braced list matches the constructor
    numbers.print();                     // 5 10 15 20
}