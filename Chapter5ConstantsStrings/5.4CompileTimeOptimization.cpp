
//Profilers can be used to find how long each portion of code runs, where the bottleneck is located 
//Optimizers are programs that optimize other programs 

//As if rule, optimizes will reorder code, remove code, add code to improve the performance w/o changing the end results
//Changes include but not limited to input/out, memory access, disk cahnges, termination, etc, volatile variables

//3 Main Optimization Techniques ( -00 means debug and no optimization. using -02 (typically the standard for prod), -03 (may or may not be better than -02) flags)
// 1) Constant Folding - Replacing expressions with their values at compile time int v = 4 + 6;
// 2) Constant Propagation - Tracking variable values (that are constant) and replacing them with their values at compile time. For variables, the cpu must store the variable in register / memory. (time and space). constants are quick and simple
// 3) Dead Code Elimination - Removing code that does not affect the program's output

//Why const variables are crucial for optimization 

//Enables these strats, for non const variables, the complier has to track the state of the variable, and cant make assumptions 

//Can't rlly use a optimized version for debugging, can't see what is removed via optimization 

// Runtime vs compile time constants 
const int 5;

const int age = userinput();