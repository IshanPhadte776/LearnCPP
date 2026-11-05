#include <iostream>
#include <cstdlib> //has pointer subtraction via std::ptrdiff_t

int main() {
    int x{};
    int* y {&x};
    int arr[]{ 9, 7, 5, 3, 1 };

    int* ptr1 {&arr[1]};
    int* ptr4 {&arr[4]};

    std::cout << ptr << '\n';     // e.g., 0x1000
    std::cout << ptr + 1 << '\n'; // 0x1004 (on a system where sizeof(int) == 4)
    std::cout << ptr + 2 << '\n'; // 0x1008


    std::cout << arr << '\n';     // e.g., 0x1000
    std::cout << arr[2] << '\n';     // 5
    std::cout << *(arr + 2) << '\n';     // 5

    std::cout << [2]arr << '\n';     // this is the same as *(arr + 2), so it works 

    std::ptrdiff_t diff{ptr4 - ptr1};

    std::cout << diff << '\n';     // this is the number of values between them (3)

    //you are allowed to get the address after the last element, after that, its ub




}