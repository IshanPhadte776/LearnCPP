#include <array>
#include <iostream>
#include <iterator>

int main() {
    constexpr std::array primes{ 2, 3, 5, 7, 11 };

    std::cout << primes.size() << '\n';       // 5 (unsigned size_type)
    std::cout <<  std::size(primes) << '\n';   // 5 (unsigned)
    std::cout <<  std::ssize(primes) << '\n';  // 5 (signed std::ptrdiff_t)

    std::cout << std::get<0>(primes) << '\n'; // Compile time gets the element at index 0

    // Can be used in constant expressions:
    constexpr std::size_t len{ primes.size() }; // Valid constexpr
}