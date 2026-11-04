#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{ 1, 2, 3 };

    std::cout << "size: " << v.size() << '\n';         // 3
    std::cout << "capacity: " << v.capacity() << '\n'; // >= 3 (often 3 on MSVC/GCC)

    int& v1 {v[2]}; //alias to the current second element in the vector 

    v.push_back(4); // triggers resizing, the v1 alias is dangling and ub 

    v.resize(6); //modifyes the size variable, add zero elements or destory elements if resizing down

    v.reserve(30); //allocating for 30 ints

    v.shrink_to_fit(); //cuts down capacity to == size 

    return 0;
}

//Resizing. -> Allocats news memory (maybe new space, maybe old space)
//transfer element (via move at first, copy as a backup) 

//deallocates the old memory 
//updates the points 