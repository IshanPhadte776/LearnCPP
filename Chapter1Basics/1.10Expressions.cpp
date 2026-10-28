#include <iostream>

#include <iostream>

int main()
{
	std::cout << 2 + 3 << '\n'; //expression within expression

	int x{ 6 }; //statement
	int y{ x - 2 }; //expression within a statement
	std::cout << y << '\n'; //expressions

	int z{}; //statement
	z = x; //expression 
	std::cout << z * x << '\n'; //expression

	return 0;
}

//Q1. Statements vs Expressions 
//Expressions are for calculations (operator, summarize to a value), Statements are for actions (decalring vars, loops, ending with ;)
//Statements can have expressions within it

//2a) int x; statement w/o expression
//2b) int x = 5; statement w/ expressions
//2c) x = 5; expression statement 
//2d) foo(); expression statement 
//2e) std::cout << x; expression statement 