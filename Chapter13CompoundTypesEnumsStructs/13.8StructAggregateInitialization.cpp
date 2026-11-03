//Aggragate is a data type that group multiple other data types together w/o complex encapsulation methods 
#include <iostream>

struct Employee {
    int id {};
    int age {};
    double wage {};
};


int main () {
    Employee joe{ 1, 32, 60000.0 }; // id = 1, age = 32, wage = 60000.0
    Employee joe {65, 32};// creates joe, id= 65, age = 32, 0 for wage 

    //declaratioin order is mandatory, no mixing and matching

    joe = {joe.id, 45, 5.0}; // multiple type update 

    std::cout << "" << std::endl;

}