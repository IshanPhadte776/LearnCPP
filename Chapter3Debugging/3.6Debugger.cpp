#include <iostream>

//-g means add debug symbols
//To compile clang++ -g -std=c++20 3.6Debugger.cpp -o debugger
//To run lldb ./debugger
//b main -> makes a breakpoint at the start of main
//run -> runs the program
// n -> next line, step over function calls, moves t the next line of code, for function calls, it will execute the function and move to the next line of code
// s -> step into function calls, moves into the function call and stops at the first line
// fr v = > frame variable, shows the variables in the current frame
// fr v -a = > frame variable, shows the variables in the current frame and arguments
// fr v power = > just for 1 variable, shows the variable in the current frame
//exit -> exit the debugger

// Helper to compute a mathematical power: base^exponent
// Contains a logic/semantic bug for debugging practice!
int computePower(int base, int exponent) {
    int result = base; // Look closely at how this is initialized when exponent is 0 or 2+

    for (int count = 1; count < exponent; ++count) {
        result *= base;
    }

    return result;
}

// Computes the sum of powers: 1^p + 2^p + ... + n^p
int sumOfPowers(int n, int power) {
    int total = 0;

    for (int i = 1; i <= n; ++i) {
        int term = computePower(i, power);
        total += term;
    }

    return total;
}

int main() {
    std::cout << "--- Power Computation Test ---\n";

    int base = 2;
    int exp = 3;
    int singleResult = computePower(base, exp); // Expected: 2^3 = 8
    std::cout << base << "^" << exp << " = " << singleResult << '\n';

    // Edge case check
    int zeroExpResult = computePower(5, 0);      // Expected: 5^0 = 1
    std::cout << "5^0 = " << zeroExpResult << " (Expected: 1)\n";

    // Call stack & stepping exercise
    int n = 3;
    int power = 2;
    // 1^2 + 2^2 + 3^2 = 1 + 4 + 9 = 14
    int seriesSum = sumOfPowers(n, power);
    std::cout << "Sum of squares up to " << n << " = " << seriesSum << " (Expected: 14)\n";

    return 0;
}