
// #include <iostream>

// int return7()
// {
//     return 7;
// }

// int return9()
// {
//     return 9;
// }

// int main()
// {
//     std::cout << return7() + return9() << '\n'; //16, no race issues like putting these in a function caller list

//     return 0;
// }


// #include <iostream>

// int return7()
// {
//     return 7;

//     int return9()
//     {
//         return 9;
//     }
// }

// int main()
// {
//     std::cout << return7() + return9() << '\n';

//     return 0;
// }

//Complier issues, no nested functions pls


// #include <iostream>

// int getNumbers()
// {
//     return 5;
//     return 7;
// }

// int main()
// {
//     std::cout << getNumbers() << '\n';
//     std::cout << getNumbers() << '\n';

//     return 0;
// }

//2 5's, no compile / run time issues, 7 just doesn't run ever



// #include <iostream>

// int return 5()
// {
//     return 5;
// }

// int main()
// {
//     std::cout << return 5() << '\n';

//     return 0;
// }

//What type of function declartion is this??