// unary plus and minux 

//5 - -3
//answer is 8 

// Integer Divison vs Floating Point Division 

// If both operands are integers, then the decimal portion is cut off 

#include <iostream>

int main () {
    std::cout << "" << std::endl;

    int a = 7 / 4; //-> 2 ints,  answer is 1 
    int b = 7 / -4; // -> 2 ints, answer is -1 


    // if even 1 operand is  a floating point, then the answer is a floating point with decimal 

    double  c = 7.0 / 4; // -> 1 fp, 1 int, answe is 1.75 

    //forcing float point division 

    // static cast 1 operand to a double (7 -> 7.0)

    double d = static_cast<double>(7) / 4;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    // int division / 0 -> UB, usually creates a crash 

    //fp division / 0 yields NaN

    //Arithmetic assignment operators 

    //+=, -=, *=, /= Operators 

    //Modifying vs Non-modifying operators 

    //Non modifying operations (+, /, == doesn't modify the operands )

    //Modifying Operators (+=, -=, ++)

    //Modifyes the operands 


}

