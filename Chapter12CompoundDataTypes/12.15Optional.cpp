
#include <optional>


std::optimal<int> findValue(int x) {
    if (x > 0) {
        return x; // Return a valid value
    } else {
        return std::nullopt; // Return an empty optional
    }
}

int main() {
    int input = 5;
    std::optional<int> result = findValue(input);

    if (result) {
        std::cout << "Found value: " << *result << std::endl;
    } else {
        std::cout << "No value found." << std::endl;
    }

    return 0;
}