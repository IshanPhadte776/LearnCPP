// ref qualifers can be used to limit the usage of specific function calls for only lvalues or rvalues

class Example {
public:
    void print() & {
        std::cout << "Called on an lvalue\n";
    }

    void print() && {
        std::cout << "Called on an rvalue\n";
    }
};

int main() {
    Example e{};
    e.print();            // Calls print() &  (e is an lvalue)

    Example{}.print();    // Calls print() && (Example{} is an rvalue temporary)
    std::move(e).print(); // Calls print() && (std::move casts e to an rvalue)
}


// void func() const &: Can be called on const or non-const lvalues.
// void func() &: Can only be called on non-const lvalues.
// void func() &&: Can only be called on non-const rvalues.
// void func() const &&: Can be called on const rvalues (rarely used in practice).

