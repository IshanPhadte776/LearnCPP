//Length/size = number of elements in the container 
// Capacity = amount of memory in bytes  that the container takes up 

// Container Class = Value_type, iterator 

//Psuedo Containers = std::string, std::vector<bool>

//C Style arrays  T arr[N]

//Array in C++ == contingious memory 

#include <vector>

//C Style arrays = stores memory on Stack / Static w/ fixed size, decays to pointers, unsafe bounds, no size tracking 
int arr[5];

//dynamic heap, dynamically resizable, manages its own memory via RAII, general purpoise
std::vector<int> vec{1,2,3};

//Fixed size known at compile time, stack / direct storage spot,  zedro overhead wrapper over c array 
std::array arrayyy[5];
