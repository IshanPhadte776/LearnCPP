//We don't want an IntArray Class, DoubleArray Class, FloatArray Class, etc
//We just want 1 array class with common behaviour and the Array store T type, T m=being any type
//Lets uses templates for classes 

template <typename T>
Class ArrayT {
private:
    T* arr{};
    int length;

public:
    ArrayT(int lengthI): length{lengthI}  {

    }

}

int main () {
    ArrayT<int> arrT{4};

}

//Put the class declaration and member functions in the .h file, dont put the member function in a seperate cpp file 
//Complier needs the class declaration and member functions at point of instantiation to make compiled machine code, the member functions cant be in a different translation unit 