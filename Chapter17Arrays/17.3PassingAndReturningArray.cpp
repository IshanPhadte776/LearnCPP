//For fixed size arrays, std::array<int,5> and std::array<int,4> are different types, 

//Passing int array is best via Templates 

#include <array>
#include <iostream>


//pass the array via reference, not value to prevent copying 
template <std::size_t T>
void printIntArray(const std::array<int,T>& arr){
    for (int elem : arr)
        std::cout << elem << ' ';
    std::cout << '\n';
}

//pass the array via reference, not value to prevent copying 
template <std::size_t T, typename U>
void printArray(const std::array<U,T>& arr){
    for (auto& elem : arr)
        std::cout << elem << ' ';
    std::cout << '\n';
}

//reutnring an array via value is fine, rvo is doen under the hood 



int main() {
    std::array a1{ 1, 2, 3 };          // std::array<int, 3>
    std::array a2{ 10, 20, 30, 40, 50 }; // std::array<int, 5>
    std::array a3{ 1.1, 2.2 };          // std::array<double, 2>

    printIntArray(a1); // Instantiates printIntArray<3>
    printIntArray(a2); // Instantiates printIntArray<5>

    printArray(a3);    // Instantiates printArray<double, 2>
}