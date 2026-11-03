//underlying integral values for the valus for enum 

//The underlying integral values can be dups
//First is 0, then going forward, each value is the prev value +1, unless we explicitly assign a value to the enum value, then the next value will be prev + 1
enum Animal {
    dog, // 0
    cat, // prev + 1 = 1
    bird, // prev + 1 = 2
};

enum Animal2 {
    catty = -3,   // -3
    doggy,        // -2
    pig,        // -1
    horse = 5,  //  5
    giraffe = 5,//  5 (duplicate alias)
    chicken,    //  6
};


enum Color { black, red, blue }; // 0, 1, 2

//constexpr isn't required, i/o is handled at runtime anyways 
//std::string_view is a non-owning view of a string, it doesn't allocate memory, it just points to the string literal in memory
//std::string would be allocated memory on the heap, which isn't neccessary
//string literals of black, red , blue arfe stored in the .rodata section of the binary (read-only section)
constexpr std::string_view getColorName(Color color) {
    switch (color) {
        case black: return "black";
        case red:   return "red";
        case blue:  return "blue";
        default:    return "unknown";
    }
}

// Teach std::cout how to handle Color objects

//std::out is an instance of std::ostream class
//we can't just copy the std::ostream object, we need to pass it by reference, so we can use the same instance of std::ostream object that is used by std::cout
//ohh, out is to the left, color is to the right
//then we put the color name into the out stream, which is std::cout
std::ostream& operator<<(std::ostream& out, Color color) {
    //pass by value is cheap here 
    out << getColorName(color);
    return out; // Return stream to allow operator chaining
}



#include <iostream>

int main () {
    Animal2 a{chicken}; // a holds value 6
    Animal a1{}; // a1 holds value 0, which is the enumerator dog

    std::cout << "Animal2 a: " << a << std::endl; //6
    std::cout << "Animal1 a1: " << a1 << std::endl; //0

    Color shirt{ blue };
    //this writes the string literal "blue" to the buffer
    //Then the runtime will determine when to empty the buffer to the console
    //buffer is of type std::streambuf in ram 
    //System call (assembly code) comes in and covnerts the application from userspace to kernel space and outputs the bytes top the terminal (tty)
    std::cout << shirt; // Prints "blue"

}