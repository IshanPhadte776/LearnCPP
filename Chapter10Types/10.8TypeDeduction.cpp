// all variable types must be known at compile time 
//auto type deduction is done at compile time, not runtime 
//no memory / performance penalty for using auto 

//For auto, initialization is mandatory.

auto var; // compile error 

auto a{5};

auto b{5u};

auto c{5.0};


//auto acts like pass by value copy, gets rid of top level const 

const int x{5};

auto y{x}; // y is just int 

y = 20; //allowed

//to preserve const, explocitly add the const 

const auto z{y}; //const int

//pros of auto uis that no need to retype types and makes the cod emore clean