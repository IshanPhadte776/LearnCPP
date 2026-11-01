#include <optional>
#include <iostream>

//optional makes it clear if a variable is invalid / non-present , no need for ambigous if NULL or 0 or "" is invalid or a legit input 

std::optional<int> doIntDivision(int x, int y) {
    if (y == 0)
        return std::nullopt; // No value returned

    return x / y;
}


int main() {
    std::optional<int> result{doIntDivision(5,0)};

    if (result) {
        std::cout <<  *result << '\n';
    } else {
        std::cout << "Division by Zero " << '\n';
    }
    std::optional<int> result2{doIntDivision(5,2)};

    if (result2) 
        std::cout <<  *result2 << std::endl;
    else 
        std::cout << "Division by Zero " << std::endl;
    

    return 0;
}