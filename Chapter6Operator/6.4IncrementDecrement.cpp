#include <iostream>

int main () {
    std::cout << "" << std::endl;

    //Prefix operator ++x / --x
    //Increments x in place, then produces x, evalutes to the new, updated value 


    //Pstfix operator x++ / x--
    //Creates a temp copy of x, increments x, returns the old copy
    //returns the odd copy of x

    int x {5};
    int y {++x}; //x is incremented, then the updated 6 is returned and stored in y 

    int a {5};
    int b {a++}; //a makes a temp copy (a), a is incremented (6), but the old version, 5 is returns, b = 5

    //prefix ++x, --x is better, reduces the need for th temp variable, more machine instructions 

    //Side Effects 

    //Side Effect is an observable change in a program state outside of simply producing a return value 
    //x = 5 x++, 

    int c {1};
    int val = c + ++c; // UB, can't have multiple mutating refernecs in 1 expression

    int add(int a, int b) { return a + b; }

    int g { 5 };

    int result { add(g, ++g) }; // DANGEROUS! //no guareete on which argument is evaluted first
}