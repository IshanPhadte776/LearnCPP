#include <iostream>
#include <vector>

int main () {
    std::vector testScores{ 84, 92, 76, 81, 56 };

    //ref prevents the double copy 
    for (const auto& score: testScores) {
        std::cout << score << std::endl;
    }

    //loop by non cosnt ref (modifable )
    for (int& score: testScores) {
        std::cout << score << std::endl;
    }

    //loop by value
    //lacks index, sequential 1->2->3, no skips / funny loooping 
    for (int score: testScores) {
        std::cout << score << std::endl;
    }

    //ssize is signed size 
    std::cout << std::ssize(testScores) << std::endl;

}