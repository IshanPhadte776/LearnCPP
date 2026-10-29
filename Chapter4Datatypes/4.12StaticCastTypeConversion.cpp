
//Implicit type conversion doesn't modify the original variable, just makes a temporary copy of the variable in the new type, and uses that temporary copy in the expression. The original variable is unchanged.
//int y {5};
//print(y); // implicit conversion from int to double to print 

//Safe vs Unsafe inplicit conversions 
//Safe (widing) small data type to a bigger, no loss of data int -> long or long long float to double 
//Unsafe (narrowing) big data type to a smaller, loss of data double -> float or long long -> int

//Explicit type conversion (casting) modifies the original variable, and changes the type of the variable to the new type. The original variable is changed to the new type, and the new type is used in the expression.

//static_cast<type>(expression)

#include <iostream>

int main () {
    int h = {5};

    static_cast<double>(h);

    

    std::cout << "" << std::endl;

}