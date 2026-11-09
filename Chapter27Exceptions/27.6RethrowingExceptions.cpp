//Rethrowing error is like a regular employee seeing some issue at work, logs the issues and sending the same issue up to their manager cause they dont have the power to solve the problem 
//Swallowing an exception just means to catch an exception, and do nothing meaningful about it 
//because the object only exists when the constructor begins, if the constructor never begins, the lifecycle doesn't exist anymore 


#include <iostream>
#include <stdexcept>

// D: SWE 1 — Encounters the raw failure
void workerD() {
    // Something fundamentally broke at the lowest level (e.g., corrupted packet)
    throw std::runtime_error{ "Disk write failure on block 0x4F" };

    //nake throw like throw; just throws the same error back up the chain of command to the higher level class
}

// C: Lead SWE / Manager — Records local context, but can't resolve it alone
void managerC() {
    try {
        workerD();
    } catch (const std::exception& e) {
        std::cerr << "[Manager C]: Logged task failure for worker D (" 
                  << e.what() << "). Escalating...\n";
        throw; // Escalates the exact same error up to B
    }
}

// B: Director — Decides policy and actually resolves/recovers from the issue
void directorB() {
    try {
        managerC();
    } catch (const std::exception& e) {
        std::cerr << "[Director B]: Intercepted escalation: " << e.what() << '\n';
        std::cerr << "[Director B]: Switching system to redundant fallback database.\n";
        // Problem solved here: NO rethrow! Normal execution resumes.
    }
}

// A: Executive / main() — Never even knows a low-level error happened
void execA() {
    directorB();
    std::cout << "[Exec A]: System continuing operations normally.\n";
}

int main() {
    execA();
    return 0;
}

//   

#include <iostream>

struct Base {
    Base()  { std::cout << "Base constructed\n"; }
    ~Base() { std::cout << "Base DESTRUCTED\n"; }
};

struct MemberA {
    MemberA()  { std::cout << "MemberA constructed\n"; }
    ~MemberA() { std::cout << "MemberA DESTRUCTED\n"; }
};

struct MemberB {
    MemberB() {
        std::cout << "MemberB throwing exception!\n";
        throw "Failed to initialize MemberB";
    }
    ~MemberB() { std::cout << "MemberB DESTRUCTED\n"; }
};

struct Derived : public Base {
    MemberA m_a;
    MemberB m_b; // Throws here

    // Function-try-block
    Derived() try : Base{}, m_a{}, m_b{} {
        std::cout << "Derived body runs\n";
    }
    catch (...) {
        std::cout << "Inside catch handler: Base and m_a are ALREADY dead!\n";
        // Base and m_a no longer exist at this point.
        // Exception automatically rethrows here.
    }

    ~Derived() {
        std::cout << "Derived DESTRUCTED\n"; // Never called!
    }
};

int main() {
    try {
        Derived d;
    }
    catch (...) {
        std::cout << "Caught in main\n";
    }
}

// Base constructed
// MemberA constructed
// MemberB throwing exception!
// MemberA DESTRUCTED                 <-- Unwound in reverse order
// Base DESTRUCTED                    <-- Base destroyed BEFORE catch runs!
// Inside catch handler: Base and m_a are ALREADY dead!
// Caught in main