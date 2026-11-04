#include <iostream>
#include <vector>

int main() {
    std::vector<int> stack{};

    // Push elements onto the stack
    stack.push_back(10); //Amotized O(1)
    stack.push_back(20); //This is fine (push_back) for when we are working with  small types like int
    stack.push_back(30); //for bigger types emplace_back is better, so the ibject is created in the vector's memory directly, as opposed to push_back that copies around

    // Peek at the top element
    std::cout << "Top: " << stack.back() << '\n'; // Prints 30 //O(1)

    // Pop the top element
    stack.pop_back(); // Removes 30; size is now 2 O(1)

    std::cout << "Top after pop: " << stack.back() << '\n'; // Prints 20 

    return 0;
}