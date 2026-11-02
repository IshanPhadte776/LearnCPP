//DEfault argument is a fallback value provided for a function parameter, if calls omits an argument, this default value is used 

//default arguments must be rightmost, else compile error
void print(int x, int y = 4){
    std::cout << "x:" << x << "y:" << y << '\n';
}


int main () {
    print(1,2); //calls for 1,2
    print(3); // 3,4
}

//under the hood, the arguments are handled at compile time, complier rewrites the call during complication, rewrites print(3) as print(3,4)

//must use copy initlization int x = 5 , no direct() or brace initilizatiion is allowed 



//No Redefiniton 
//If the header / forward declartion has a default argument, the implementaion must also have a default argument 

// In foo.h:
void print(int x, int y = 4); // Put default argument here

// In foo.cpp:
#include "foo.h"
void print(int x, int y)      // Do NOT put '= 4' here! Redefinition error!
{
    std::cout << x << ' ' << y << '\n';
}

//this isn't allowed 


//Default arguments w/ Overloading 

//DEfault arguments aren't a part of the function's type signature, therefore, can lead to ambigious function calls 

void foo(int x = 0);

void foo(double x = 0.0);

foo(); //can go over the first or second option

void print(int x);
void print(int x, int y = 10);

int main() {
    print(1, 2); // OK: calls print(int, int)
    print(1);    // Compile error: ambiguous!
                 // Matches print(int) exactly,
                 // but ALSO matches print(int, int) via default argument!
}