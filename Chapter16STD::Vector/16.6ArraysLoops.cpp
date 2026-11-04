#include <iostream>
#include <vector>

int main() {
    std::vector testScores{ 84, 92, 76, 81, 56 };
    std::size_t length{ testScores.size() };

    int sum = 0;

    for (int i{0};i < length;i++) {
        sum+=testScores[i];
    }

    int average = sum / (static_cast<int>(length));

    
    std::cout << "Average: " << average << '\n';

    return 0;
}