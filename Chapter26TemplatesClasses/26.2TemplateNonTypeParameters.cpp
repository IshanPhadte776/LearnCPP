//NTTP ( Non type template parameters)

template <typename T> 
//in this code, the template is a T, T is a parameter for the class / function


template <typename T, int size> 
//in this code, int size is a non type template parameter 

//only integral, floats, std::nullptr_t, enum are fine for non type template parameters 
//void, anything heap-allocated objects aren't allowed for nttp  
template <typename T, int size> // 'size' is a non-type template parameter
class StaticArray {
private:
    T m_data[size]{}; // Allocated directly on the stack!

public:
    T* getData() { return m_data; }

    T& operator[](int index) { return m_data[index]; }
    const T& operator[](int index) const { return m_data[index]; }

    constexpr int getLength() const { return size; }
};

int main () {
    StaticArray<int,5> sarray;



}