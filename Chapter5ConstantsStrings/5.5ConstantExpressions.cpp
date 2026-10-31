
//compile time expression -> all values are known at compile time 

//runtime expression -> some values are not known until runtime 


//compile time programming is good because it moves work away from the executable binary. Compile time programming errors out which is better than UB

//Examples of constant expressions

//literals, "543" , 4, 4.6
//technically, non integral (int) types can be true const, doubles aren't
//constexpr 

//What can't be constant expression
//non const variables, non constexprs function calls

//variable is non-const, a can bne changed 
//'q' is a const literal, we can't change it 
char a = "q";

//variable is const 
// 0 is a const expression, we can't change it
const int b { 0 };

//variable is non-const, a can bne changed 
//'q' is a const literal, we can't change it 
const double c { 5.0 };

//a is non const, so a* 2 is non const. initialization is non const
//d is a non-const expression because it depends on a, which is non-const, so d can be changed at runtime
const int d { a * 2 }; // a defined as char a { 'q' };


int e { c + 1.0 };