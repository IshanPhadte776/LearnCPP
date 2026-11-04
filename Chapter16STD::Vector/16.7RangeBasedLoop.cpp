#include <iostream>
#include <vector>

int main () {
    std::vector testScores{ 84, 92, 76, 81, 56 };

    //ref prevents the double copy 
    for (const auto& score: testScores) {
        std::cout << score << std::endl;
    }

    //ssize is signed size 
    std::cout << std::ssize(testScores) << std::endl;

}