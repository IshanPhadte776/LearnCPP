//array[2] = 5 translates to array.[](2) = 5 ;


#include <cassert>
#include <iterator> // for std::size

class IntArray {
private:
    int m_data[10]{};

public:
    // Non-const overload: returns a non-const reference to allow assignment
    int& operator[](int index) {
        assert(index >= 0 && index < static_cast<int>(std::size(m_data)));
        return m_data[index];
    }
};

int main() {
    IntArray list{};

    list[2] = 42; // Calls list.operator[](2), returns int&, assigns 42
    std::cout << list[2] << '\n'; // Reads 42
}

IntArray* ptr{ new IntArray{} };

// WRONG:
// ptr[1] does pointer arithmetic: *(ptr + 1) -> accesses invalid memory!

// CORRECT:
(*ptr)[1] = 5; // Dereference pointer first, then index