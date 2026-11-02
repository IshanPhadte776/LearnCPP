
// = delete deletes / removes an overload. 





#include <iostream>

void print(int x){
    std::cout << x << '\n';
}

//removes the char and bool function overloading 
//has to be done at namespace scope or class member function, not block scope 
void print(char) = delete;
void print(bool) = delete;


int main () {
    std::cout << "" << std::endl;

    print(5); // gives 5 

    print(true); //normally, true gets converted vip numeric promotion from true to 1 (bool -> int)
    //compile error because the bool overload has been disabled. it matchs print(int) with print(true), but checks if its valid, but notices it is not valid as print(bool) was deleted, compile error 


}