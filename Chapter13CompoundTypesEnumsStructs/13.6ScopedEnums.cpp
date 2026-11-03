#include <utility>

enum class Color {
    red,
    blue.
};

enum class Fruit {
    banana,
    apple,
};

int main () {
    //These don't implicitly convert to Ints
    //scoped enums are the deffault for idiomatic C++
    Color c{Color::red};
    Fruit f{Color::banana};

    std::cout << static_cast<int>(c) << '\n'; //This will get your integer
    std::cout << std::to_underlying(c) << '\n';
}