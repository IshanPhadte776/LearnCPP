//function overloading is resolved at compile time
//ambigious function calls are bad, there needs to be 1 best matching for a function call

//Matching Hierachy 

//Rank 1: Exact Match / Trivial Conversion 

//int -> int
//lvalue to rvalue conversions
//adding a const to get to const int&
//non ref to ref conversion

//Rank 2: Numeric Promotion 

//bool/char/short -> int 
//float -> double 

//Rank 3: Numeric Conversion 

//int -> long
//int -> float
// rlly anything else 


//Rank 4 (User Defined Conversions)

//Converting constructors or overloaded type case operators in classes 

//Rank 5 Ellipsis Catch call (...)


void print(int);

void print(double);

print(5L); //ambigous function call

void display(int, double);
void display(double, int);

display(5, 5.0); // display(int, double) is strictly better for both
display(5.0, 5); // display(double, int) is strictly better for both

display(5, 5);   // Ambiguous! 
                 // First func is better for arg 1 (exact int vs double)
                 // Second func is better for arg 2 (exact int vs double)



//How to avoid ambigious calls, 

//Explicit casting 

print(static_cast<int>(5L));

//use suffix 

//define a new overload 