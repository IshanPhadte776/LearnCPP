//raw pointer rely on manual memory management - requires devs to call delete and delete[] when the memory should be deallocated 
//enter smart pointers, automaitcally calls delete on the memoru the pointer manages when the pointer gors out of scope 

//object = vector. control block is on the stack 
//dynamiclly allocated memory is on the heap. 
//when the object (vector) leaves the scope, the vector contol block on the stack is cleared. but the heap data isn't clear, memory leak 
//smart pointers who own the vector will call delete when the smart poonter goes out of scope 
//in this casem we don't create a std::vector, we create a pointer to a std::vector, we access through the pointer, then RAII occurs through the pointer

std::vector<int> vec; // Empty vector
//This allocates 24 bytes on the stack for the control block
//add elements will go on the heap 
//we allocate memory on the heap for the elements

new std::vector<int>();
//this places both the control block and the elements on the heap, maybe in 2 different places. 

//raw pointers are just storing a 8 byte address in a variable, when the raw pointer  goes out of scope, the raw pointer is deleted, but nothing happens to the object at that memory address 

//smart pointers wrap the memory address with the class object, so when the smart pointer leaves the scope, the smart pointer calls the destructor for the object at hand, deleting the memory on the heap via delete