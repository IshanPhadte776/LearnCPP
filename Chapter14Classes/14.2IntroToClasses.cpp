//proiblem with structs is that member variables are public by default -> allowing for direct modifcation, even when it shouldn't, also, allows for any value in the type, which isnt' always great

struct Fraction {
    int numerator { 0 };
    int denominator { 1 }; // Class invariant: denominator must NEVER be 0
};

void printFractionValue(const Fraction& f) {
    std::cout << f.numerator / f.denominator << '\n';
}

int main() {
    Fraction f{ 5, 0 };   // Compiles cleanly, but violates the invariant immediately!
    printFractionValue(f); // Crash: divide-by-zero runtime error
    return 0;
}

//Classes are compound types that hold data AND enforce invariants that bind this behaviour to the data directly 

//Technically, classes are structs are the same under the hood, just struct has default public member access
//class has default private member access

//Struct is for passive data holders w/o invariants 

//Classes have data memberships, constraintsm invariants must be validated, encapulated , protected 

//std::string is class that manages a dynamic character array with a size / capacity invaraint variable 
