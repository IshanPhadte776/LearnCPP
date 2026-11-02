auto add(int x, int y) {
    return x + y; // Deduces int because (x + y) evaluates to int
}

//again, type deduction happens at compile time, const is dropped (pass by value)

//auto +forward declartion doesn't work, complier doesn't know the return type of the function 

auto foo(); // Forward declaration

int main() {
    foo(); // Compile error: compiler has not seen the definition yet and cannot deduce return type
    return 0;
}

auto foo() {
    return 5;
}

//auto can;t be used to return 2 different types, doesn't work 

auto getVal(bool flag) {
    if (flag)
        return 5;   // Deduces int
    else
        return 6.7; // Compile error: inconsistent deduction (int vs. double)
}

//function parameters can't use auto 