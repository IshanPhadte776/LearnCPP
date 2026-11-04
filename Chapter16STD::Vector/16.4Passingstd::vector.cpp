//pass by value for vector is expensive, involves allocating memory in heap
//use pass by (const) reference


//returning a std::vector is fine, modern c++ uses copy elison (RVO / NRVO to prevent double creation)


#include <iostream>
#include <vector>

std::vector<int> func(std::vector<int>& inputvec){

    inputvec[4] = 4;

    return inputvec;
}

int main () {
    std::vector<int> vec{1,2,3};
    func(vec);
    std::cout << "Done" << std::endl;

}