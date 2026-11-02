#include <cstdint>

//explicit type casting doesn't change the original value 
//It reads the oriignal value, makes a temp copy, modifys the temp copy, and returns the modified temp version 

//5 types of explicit casting 








//C style Casting 
int x{5};

double y{(double)x};

//Not recommended because hard to search via grep
//c style cast can act like static_cast, const_cast or reintercept cast without a complier watning. Can lead to memory interpretion if no valid conversion is found

//Static Cast 
//static_cast<int>(variable)
//compile type cast 
int z = static_cast<double>(x);

//reinterpret_cast (reinterepts raw bit patterns w/o type checking)

std::uint32_t value {0x12345678};

auto* bytePtr {reinterpret_cast<const unsigned char*>(&value)};

std::cout << "First byte in memory: 0x" << std::hex << static_cast<int>(bytePtr[0]) << '\n';


//const_cast(variable) to add / remove const / volatile 
const char message[] {"Hello world"}; 

const_cast<char*>(message);

//defining a variable as const, const cast to remove const, then modifying the variable leads to ub, mainly good for passing variables into older apis 



//dynamic casting (for runtime type casting changing )
//Runs RTTI (Run time type information)

//Can be used to determine if we are working with a base pointer or pointer to the derived object class 

class Base {
public:
    virtual ~Base() = default; // Polymorphic base class (virtual required)
};

class Derived : public Base {
public:
    void specialAction() {
        std::cout << "Derived-specific behavior executed!\n";
    }
};


int main (){
    //this is a basePointer pointing to a derived object 
    Base* basePtr{ new Derived{} };

    if (Derived* dPtr{dynamic_cast<Derived*> (basePtr)}) {
            //dPtr is a Derived Pointer Pointing to a Derived Objct 
    }

    //allows for dPtr ->specialAction();
}