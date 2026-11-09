#include <iostream>
#include <cmath> // For std::sqrt

// Function that raises an exception
double mySqrt(double x) {
    if (x < 0.0) {
        // 1. THROW: Send an error object out of the function
        throw "Cannot take sqrt of negative number!"; // Throws a const char*
    }

    return std::sqrt(x);
}

int main() {
    std::cout << "Enter a number: ";
    double d{};
    std::cin >> d;

    // 2. TRY: Guard the code that can fail
    try {
        double result{ mySqrt(d) };
        std::cout << "The sqrt of " << d << " is " << result << '\n';
    }
    // 3. CATCH: Handle exceptions matching this specific type
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }

    std::cout << "Program execution continues normally...\n";
    return 0;
}

try {
    // Code that might throw int, double, or const char*
    doWork();
}
catch (int errorCode) {
    std::cerr << "Integer error code: " << errorCode << '\n';
}
catch (double errorValue) {
    std::cerr << "Double precision error: " << errorValue << '\n';
}
catch (const char* errorMessage) {
    std::cerr << "String error: " << errorMessage << '\n';
}

//implicit type conversion isn't done for catching errors. 

//If an exception is not caught, std::terminate() is called, calling std::abort() and aborts the program 