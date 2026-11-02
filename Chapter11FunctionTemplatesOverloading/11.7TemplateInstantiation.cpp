// Function isn't machine code, its a blueprint 

//when we call a function template, the compliers examines the types, makes a copy of the template, replaces all istances of T w/ the type it picked

// This process is called template instantiation 
//the generated function is called a instantiated function (function instance)

//we only generate 1 copy of a template instantiation on subsequent calls 

template <typename T>
T max(T x, T y){
    return (x > y)? x : y;
}

//this allows for multiple types 
template <typename T, typename U>
int add(T x, U y){
    return (x > y)? x : y;
}


//mixxing and matching types is fine 
template <typename T>
void printRepeated(T value, int times) {
    while (times-- > 0) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}



int main() {
    max(2,3); //makes the int, int function instance, type deduction 
    max<int>(4,5); // uses the int function instance 

    //max(2,3.5); //doesn't work because there's only 1 type for T, T can't be both an int and double here 

    max<double(2,3.5); // this is fine, calls the double instance directly and does type conversion 
}



//Instantiation and multi file projects 

//function templates must have their definitions placed in header files 
//they are treated as inline by default 

//Because template instiantiation happens at compile time, all translation units must have the definition if they use it. 