//How operator>>  works. 
//1. Removes all leading whitespaces 
//2. Extracts all valid characters 
//2a. for numeric types (int) -> reads until it hits a non number / whitespace 
//2b. For std::string, it reads until it hits whitespace 
//leaves trailing characters in the buffer 
//leaves the '\n' in the buffer too 
cin >> x;

//cin.get() -> gets just the next char, only 1 char 

std::getline(std::cin,var ) //puts the entire line into the variable 

//cin >>   -> std::getline wombo combo 

int age{};
std::cout << "Enter age: ";
std::cin >> age; // User types "22" and presses [Enter]
//the '\n' is still in the buffer

std::string name{};
std::cout << "Enter name: ";
std::getline(std::cin, name); // BUG: Appears to be skipped completely!
//sees the '\n' first and skips 


//this is the way 

#include <limits>

std::cin >> age;

// Discard all characters up to and including the next newline:
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

std::getline(std::cin, name); // Now prompts and reads correctly!

// cin.peek(): Returns the next character in the input stream without removing it from the buffer (lookahead).

// cin.unget(): Puts the most recently extracted character back into the stream.

// cin.putback(ch): Puts a specific character ch back into the stream to be extracted on the next read.

// cin.gcount(): Returns the number of unformatted characters extracted by the last unformatted read operation (such as get(), getline(), or read()).