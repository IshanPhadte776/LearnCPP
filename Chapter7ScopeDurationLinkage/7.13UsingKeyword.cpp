//using keyword important just whatever is after the using keyword 

//just imports std::cout
using std::cout;

cout << "Hello" << '\n';

//imports the entire namespace of std, can cause namespace pollution 
using namespace std;

cout << "Hi" << '\n';

void print() {
    using std::cout;
    cout << "Scoped to print()\n";
} // using declaration expires here

void other() {
    // cout << "Error: cout is not in scope\n";
}


//the issue with the using namespace std is that we over import everything, we can't use any of the variable names from std for our variables,

#include <iostream>

int count { 5 }; // Defines a variable named 'count'

using namespace std; // std::count also exists!

int main() {
    // Ambiguity error: compiler doesn't know whether you mean '::count' or 'std::count'
    cout << count << '\n'; 
    return 0;
}