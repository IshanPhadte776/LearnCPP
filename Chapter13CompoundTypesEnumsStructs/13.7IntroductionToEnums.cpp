#include <iostream>

//struct = default member access = public, not private like classes
struct Employee {
    int id{}; //zero initialized
    std::string name{}; //zdero initialize 
    float salary; //garbage va;ue 
};



int main () {
    Employee frank{};

    frank.id = 67;



    std::cout << "" << std::endl;

}