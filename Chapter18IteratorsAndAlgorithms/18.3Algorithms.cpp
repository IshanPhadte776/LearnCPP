//<algorithm> explained 

//std::find and std::find_if

//std::find takes 2 iterators for a range and value and return an iterator to the spot that ha the element or the end it if the element wasn't found 
//std::find(starting iterator, ending iterator, starting value)


#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{ 13, 27, 42, 68, 99 };

    auto found{std::find(v.begin(), v.end(), 42)};

    // Always compare against end() to confirm the element was located
    if (found != v.end()) {
        std::cout << "Found value: " << *found << '\n';
    } else {
        std::cout << "Value not found.\n";
    }

    return 0;
}


bool containsRed(std::string_view s) {
    return s.find("red") != std::string_view::npos;
}

// ...
auto match{ std::find_if(words.begin(), words.end(), containsRed) };

//find_if takes a function, not a value, returns a boolean\



bool isEven(int n) {
    return (n % 2) == 0;
}

int main() {
    std::vector<int> v{ 1, 2, 3, 4, 2, 6, 2 };

    // Count exact value occurrences
    auto twos{ std::count(v.begin(), v.end(), 2) };
    std::cout << "Number of 2s: " << twos << '\n'; // 3

    // Count matching predicate condition
    auto evens{ std::count_if(v.begin(), v.end(), isEven) };
    std::cout << "Even numbers: " << evens << '\n';  // 5

    return 0;
}

//count and countif are the same as find and find if 


void doubleValue(int& n) {
    n *= 2;
}

int main() {
    std::vector<int> v{ 1, 2, 3, 4 };

    // Modifies elements in-place by taking an lvalue reference
    std::for_each(v.begin(), v.end(), doubleValue);

    for (int n : v) {
        std::cout << n << ' '; // 2 4 6 8
    }
    std::cout << '\n';

    return 0;
}

//std::for_each takes 2 ranges and a function, runs the function on each element, passing in a reference to the elment (for modifatio)



// Default: Ascending sort using operator<
std::sort(v.begin(), v.end());

//this is how sorting works 