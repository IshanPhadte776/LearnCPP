#include <iostream>

struct Employee {
    int id {};
    int age {};
    double wage {};
};

int main () {
    std::cout << "" << std::endl;

    Employee joe {4,5,6.7};
    Employee* ptr{&joe};

    //*ptr.age -> doesn't work 
    //member selec tion has Level 2 Priority
    //pointer dereference is Level 3  

    //*(ptr.age) doesn't work 
    //(*ptr).age works, but clunky 

    ptr -> age; //this is the way 

}

