//early return for nullptr
void print(const int* ptr) {
    if (!ptr)
        return;
    std::cout << *ptr << '\n';
}

void badReseat(int* ptr) {
    ptr = nullptr; // Only changes the local copy of the pointer!
}

int main() {
    int x{ 5 };
    int* p{ &x };
    badReseat(p);
    // p STILL points to x!
}

void reseat(int*& ptrRef) { // Reference to a pointer
    ptrRef = nullptr; // Modifies the caller's pointer directly
}

int main() {
    int x{ 5 };
    int* p{ &x };
    reseat(p);
    // p is now nullptr!
}

//pass by address is rlly pass by value of the address, 