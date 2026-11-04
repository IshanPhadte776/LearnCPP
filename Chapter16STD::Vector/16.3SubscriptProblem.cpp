//vector[] is not out of bounds safe, at() is bounds safe 

#include <vector>
#include <iostream>

int main () {
    std::vector<int> primes {2,3,5,7,11};

    std::cout << primes[0] << '\n';
    primes[1] = 42;


    try {
        //just provides an std::out_of_range error
        std::cout << primes.size() << '\n';
        std::cout << primes.at(10) << '\n';
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }


    //operator[] returns a T&, non const reference, allowing for modifying 

    return 0;

}