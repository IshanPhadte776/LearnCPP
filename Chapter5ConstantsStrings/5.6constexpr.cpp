//Problems with the const keyword
//const can enable a const expression. but only under specific circumstances 
//1. only for integral types (int, char, bool) no doubles 
//2. const float grav = {9.8} //no because its a float, not integral base 

//const int x { getValue() } //we don't knwo if x is a compile time expression without hunting down the definition of getValue()

//const keyword rlly just means read-only after initialization. Just to prevent accidently writes after initilization, complier rlly doesn't do anything. can be doen at compile or runtime
//const expressions lead to constant folding and constant propagation (performance improvement)

//const expressions requires 3 conditions to be true 
//known at compile time using solely compile known variables and literals 
//evaluted at compile time (no heap alloc, no cin cout)
//no runtime dependencies / ub

//C++ 11 introduced constexpr to remove this confusion 
//constexpr forces compile time eval and works for floating point types  

//function parameters can be const, not constexpr

int func (const int var) {}

//this function can be ran at compile time, no problems
constexpr int func1 (int var) {}