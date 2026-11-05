#include <iostream>
#include <array>

int main () {
    //fixed size array
    std::array arr {1,2};
    std::array<int,5> prime {1,2,3,5,7};

    std::array<int,5> uninit; //5 garbage values 
    std::array<int,5> {}; // 5 0 init

    //we tell short, complier deducts 4 length 
    constexpr auto = std::to_array<short>({1,2,3,4});

    //array [] acts like vector[], unbounded access is ub 


    std::cout << "" << std::endl;


}