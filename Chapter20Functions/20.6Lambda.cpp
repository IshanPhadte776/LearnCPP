//unnamed functions 

[captureclause](parameters) -> returnType {statements;}

captureclause = passes outer variables into the scope of the lambda function
paremeters

//[] {}; -> This is a bare minimum lambda function

#include <iostream>
#include <algorithm>
#include <array>

int main() {
    constexpr std::array temperatures{ 5, -2, 12, -8, 0, -1, 7 };

    auto isNegative {[](){return n < 0}};

    negativeDays{std::count_if(temperatures.begin(), temperatures.end(), isNegative)};

    std::cout << "Days below freezing: " << negativeDays << '\n'; // 3
}