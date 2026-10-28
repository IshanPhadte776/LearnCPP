
//Forward declaration (function prototype), declare the identifier first, then the main function, then function implementation at the bottom, helps with ordering issues

//function declartion -> void (int x) -> maybe a body
//function definition -> void (int x) {} -> has a body 
//pure declaration -> no body 



//ODR (One Definition Rule) 
//1 Definition for an identifier for the scope 

// int add(int x, int y)
// {
//      return x + y;
// }

// int add(int x, int y) // violation of ODR, we've already defined function add(int, int)
// {
//      return x + y;
// }

// int main()
// {
//     int x{};
//     int x{ 5 }; // violation of ODR, we've already defined x
// }


//Q1. Function Protoype -> Pure declartion of a function, name, parameter type and count, return type, mauybe parameter name

//Q2 Forward declartion -> Declartion, then definition later

//Q3 How to do a forward declaration 

// int func(int x);

// int func(int x) {
//     return 3;
// }

//Q4 

// int doMath(int first, int second, int third, int fourth)
// {
//      return first + second * third / fourth;
// } 
// int doMath(int first, int second, int third, int fourth);

//Failing to Link is different than failing to compile for forward declarations

//4a

// #include <iostream>
// int add(int x, int y);

// int main()
// {
//     std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
//     return 0;
// }

// int add(int x, int y)
// {
//     return x + y;
// }

//This doesn't compile, add(int,int,int), forward declartioned for add(int,int), doesn't work

//4b 

// #include <iostream>
// int add(int x, int y);

// int main()
// {
//     std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
//     return 0;
// }

// int add(int x, int y, int z)
// {
//     return x + y + z;
// }
//Same problem, doesn't compile for the same reason

//4c

// #include <iostream>
// int add(int x, int y);

// int main()
// {
//     std::cout << "3 + 4 = " << add(3, 4) << '\n';
//     return 0;
// }

// int add(int x, int y, int z)
// {
//     return x + y + z;
// }

//Linking error, matchs add(3,4) to the forward delcartion, but no implementation, linker complains

//4d


// #include <iostream>
// int add(int x, int y, int z);

// int main()
// {
//     std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
//     return 0;
// }

// int add(int z, int y, int x) // names don't match the declaration
// {
//     return x + y + z;
// }

//Compiles and links, names that dont line up is fine 

//4e

// #include <iostream>
// int add(int, int, int); // no parameter names

// int main()
// {
//     std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
//     return 0;
// }

// int add(int x, int y, int z)
// {
//     return x + y + z;
// }

//compiles and links, names don't need to picked in the forward declartion. 

// #include <iostream>

// int add(int x, int y);

// int add(int x, int y, int z)
// {
//     return x + y + z;
// }

// int main()
// {
//     std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
//     return 0;
// }

//Works, add(int,int) is un used 