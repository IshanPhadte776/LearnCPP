//By default, anything with a decimal is a double, use f at the end of the number to make it a float, ie. 3.14f
// all floats are signed, no unsigned floats 

//Doubles are favoured over float, more precision. 

//Narrow conversion = taking a variable of a larger type and converting it to a smaller type, ie. double to float, int to short, etc. This can lead to loss of precision / data loss, and is usually not what you want.

//float f = {4.5}; //error, no narrow conversion via curved braces
//float f = {4.5f}; //ok, no narrow conversion via curved braces

//std::cout has some quirks, remove trailing zeros, and will round to 6 decimal places by default, 

#include <iostream>
#include <iomanip>

int main () {

    std::cout << std::setprecision(10); //set precision to 10 decimal places

    std::cout << 3.3333333333 << std::endl;

    double d1 { 1.0 };
    double d2 { 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    if (d1 == d2) 
        std::cout << "Equal!\n";
    else 
        std::cout << "Not equal!\n"; // PRINTS THIS! (d2 is 0.99999999999999989)

}