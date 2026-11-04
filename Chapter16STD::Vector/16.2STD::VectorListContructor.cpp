//std::vector is rlly a template for std::vector<T> for any type 

//contignous memory 

//Vector Control Object is on the stack (where its instantiate ) begin pointer, end pointer, capacity pointer 

//The element buffer which has the elements is in the heap and handled by RAII

#include <vector>

std::vector<int> v {1,2,3,4}; // this uses a std::initializer_list // uses list contructor 
//this above creates a lightweight copy obejcty of type std::initialization_list<T>
std::vector v2 {1,2,3}; //CTAD works 

//std::vector v3 {}; This doesn't work, which type does CTAD end up w/ 



std::vector<int> v1(5); // Creates a vector with length 5, value initialized to 0 
std::vector<int> v1(5,42); // Creates a vector with length 5, value initialized to 42

const std::vector<int> fixedData {5,4}; //read-only access, can't be resized