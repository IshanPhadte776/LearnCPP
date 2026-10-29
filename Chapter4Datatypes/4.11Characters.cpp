//chars are techically integers, as all chars are represented by an integer value 
//chars are 'c' single quote wrapped
//when initialzaing a char, use the 'g' representation for the variable 

#include <iostream>
#include <string>

char g = 'j';
//nah
char h = 57;

std::string string = "Hello";

// \t = tab
// \n = new line

std::cin >> g; //reads a single char from the input stream, and stores it in g
std::cin >> string; //reads a string from the input stream, and stores it in string, stops reading at whitespace