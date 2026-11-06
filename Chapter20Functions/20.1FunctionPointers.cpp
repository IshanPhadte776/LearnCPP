//function is stored in the .text / executable section

//regular pointer stores the pointer to the memory address on the stack / heap 
//function pointer stores the address to the .text section that has the function's compiled machine code 

//remeber operator() > operator*

//no parameters, int return type 
//name is functionPtr
int (*functionPtr) ();

int *functionPtr(); //declares a function named functionPtr, returns int* 

//return_type (*pointer_name)(parameter_types);


#include <functional>

// Accepts free functions, lambdas, or functors matching this signature:
void process(int a, int b, std::function<bool(int, int)> callback);