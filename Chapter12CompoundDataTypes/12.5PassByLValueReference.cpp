#include <iostream>

//Must pass in an LValue, no RValues
//Can't be const int, int& must be modifiable, can't be const int&
void addOne(int& value){
    ++value;
}

int main () {
    std::cout << "" << std::endl;
    int y{5};
    const int z {10}; //z is an LValue reference to y
    addOne(y); //y is an LValue, can be passed by reference // not pass by value

    std::cout << "y: " << y << std::endl; //6

    //addOne(10); //error: 10 is an RValue, can't be passed by reference
    //addOne(y + 10); //error: y + 10 is an RValue, can't be passed by reference

    
}