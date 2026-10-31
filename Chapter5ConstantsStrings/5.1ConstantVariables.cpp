// Constants are variables thats dont change throughout the course of the program

//Named constants are variables with names, (w/ identifiers) > const int x = 5; //x is a named constant, it has a name, and it is a constant variable, it cannot be changed after initialization
//Literal constants -> lack names "Hello World" is a literal constant, it is a constant value, but it does not have a name, it cannot be changed after initialization

//Consts can;'t be changed accidently 
//allows compliers to make optimizations, like pasting the constant straight into assembly instructions 

//const > preprocessor macros, consts are type safe, preprocessor macros are not, preprocessor macros are just text replacement, they don't have a type, they don't have a scope, they don't have a lifetime, they don't have a storage class, they don't have a linkage, they don't have a visibility, they don't have a storage duration

//no const for return by value, no const for value parameters