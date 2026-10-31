
//C Style strings are fine, but have issues 
// Can't use assignment to assign a C style string to a new value, can't use = to reassign str = "hello world doesn't work"
// Space dangerous, if you place a larger string in a bvox for smaller string, UB

//C++ offers std::string

std::string var = {"Ishan"};
//This works, isn't O(n)
//handles the size change fine 
var = "Batman";

//If the string grows. /changes beyond its max capacity, it dynamically allocates more memory on the heap 
//Tradeoff, flexibility, but slow as stack is fast, heap is slow 

//.length() is used to get the length of a std::String (unsigned) unsigned int
//can't mix signed and unsigned ints
std::cout << var.length();

// pass by value  is not recommended, leads to copying and making heap allocations 
//Use std::string_view or const std::string& for function parameters 

//returning an std:string is fine, we use move semantics / Return value optimization, transferring the internal buffer pointer without deep copying memory 

using namespace std::string_literals;

auto hello = "Hello"s;

//constexpr std::string doesn't work. std::string stores data on the heap (runtime)

