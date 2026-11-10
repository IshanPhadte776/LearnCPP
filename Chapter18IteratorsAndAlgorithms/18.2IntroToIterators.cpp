//iterators are just a wrapper class for a pointers to iterate through a container class 
//vector has contigious memory, list moves to the next element via next pointers cause the memor is non contigious 
//set stores then in a balance binary tree (sorted)


//Half open range 
//[begin, end)

begin points to the first element in the container class 
end points to the memory address one past the last element 

//one past end idea 
//When traversing the iteratorwe go it != end
//So we go from the first element to the last element, move to the end, then stop
//we never want to dereference the endm, it pointers to some element that isn't in the container, UB

#include <iostream>
#include <vector>
#include <iterator> // for std::begin, std::end

int main() {
    std::vector<int> v{ 10, 20, 30, 40 };

    // Standard iterator loop
    for (auto it{ v.begin() }; it != v.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    return 0;
}

//vec.begin() -> returns an iterator that is starting at the first element in the container 
//vec.end() ->returns an iterator that is pointing to 1 past the last element 

//Range based loop

for (const auto& element: v) {
    std::cout << element <<'\n';
}



#include <vector>

int main() {
    std::vector<int> v{ 1, 2, 3 };
    auto it{ v.begin() };

    // Adding elements can trigger a reallocation:
    v.push_back(4); 

    // UNDEFINED BEHAVIOR:
    // If v reallocated its buffer, 'it' points to freed heap memory!
    // *it = 10; 
}

//Iterators can be invalidated because of dynamic memory allocates change the memory addresses the container 

