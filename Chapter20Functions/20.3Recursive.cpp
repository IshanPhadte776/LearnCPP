#include <iostream>

void countDown(int count) {
    std::cout << "Pushing frame " << count << '\n';

    if (count <= 0) // Base case (termination condition)
        return;

    countDown(count - 1); // Recursive call

    std::cout << "Popping frame " << count << '\n';
}