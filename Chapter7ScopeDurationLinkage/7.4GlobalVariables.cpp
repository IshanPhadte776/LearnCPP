//Global Variable = defined outside of blocks, functions, namespaces. (or within a namespace)
//global variables are zero initialzed 

//constant expressions for global variables are done at compile time 
//non const is done dynamically at runtime 

//naming convention is g_ 

int g_variable;  

//non-const global variables are an anti-pattern, leads to difficulty of debugging, difficult to isolate 