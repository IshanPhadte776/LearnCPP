//For cin >>, the data is first written to a internal buffer, then moved to the variable

//2 main sources of error 

//1. cin >> x but a user provides "apple", cin chokes and leaves the "apple" in the internal buffer, this enables te failure bit and blocks all cin 

// cin >> 5a >> y, 5 goes into variable, but a stays in the buffer   

#include <iostream>
#include <limits>

void clearBuffer() {
    //ignore tells cin to discard some characters
    //std::cin.ignore(count, delimiter), discard until 1 of two condiitoners occur 
    //count -> throw away x amount of characters
    //delimiter -> hit the delimiter and throw it away and everything before it
    //std::streamsize returns the stream buffer size
    //std::streamsize is like the std::size_t but for the size of streams and buffers 
    //enter key leads to '\n', discards everything

    //std::numeric_limits<int>::max() -> gets the maximum value that an integer can hold 
    //std::numeric_limits<std::streamsize>::max() -> gets maxiumum value a stream can hold 9 quilion (9 + 18 zeros)
    //either clear the max size of the buffer, or clean until u find the '\n'

    //sid::cin is a static variable in static / bss section
    //stream buffer is on the heap 
    //Step 1 os takes bytes from keyboard to heap buffer
    //Step 2 heap buffer bytes to the stack for the local variable 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(){
    while (true) {
        std::cout << "Enter a number: ";
        int x{};
        std::cin >> x;
    
        //if there's an error with cin and the flag has been turned off 
        if (!std::cin) {
            std::cin.clear(); //Turns std::cin back on 
            clearBuffer(); //Clears the buffer 
            std::cout << "That wasn't a valid integer. Try again.\n";
            continue;
        }

        clearBuffer();
        return x;
    }
}