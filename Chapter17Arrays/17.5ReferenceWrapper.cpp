#include <array>
#include <functional>
#include <iostream>


// you can't have an array of references 



int x{6};

int y{7};

//This isn't going to work int& intRef[] {x,y};
//References are objects, thye lack memory addresses, container require its objcts to be distinct 

//Solution -> std::reference_wrapper


int main () {
    int a{6};

    int b{7};

    //this is more or less a an array of references
    std::array<std::reference_wrapper<int>,2> arr {x,y};


    arr[1].get() = 2; //updates x
    

}