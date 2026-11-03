
//Composing Globally Defined Types 
struct Employee{
    int id{};
    int age{};
    double wage{};
};

struct Company {
    int numberOfEmployees{};
    Employee ceo{};
}

//Nested Structs 
//Good when employee2 is only needed within company2
struct Company2 {
    struct Employee2{
            int id{};
            int age{};
            double wage{};
    };
    
    int numberOfEmployees{};
    Employee ceo{};
};

struct BadPerson {
    std::string_view name {}; // Viewer! Dangerous inside a struct!
};

//string_view as a struct member is not a great idea 

int main () {

    Company techComp {45,{12,12,34.88}}; 
}

//Padding: Compilers insert invisible padding bytes to enforce CPU memory alignment.

//Ordering: Declare data members from largest to smallest to avoid wasteful memory gaps.

//ints must start on an address that starts w/ 4
//doubles must start on address that start w/ 8 etc

struct BadLayout {
    short a {}; // 2 bytes
                // [2 bytes of invisible padding inserted here]
    int b {};   // 4 bytes (must align on 4-byte boundary)
    short c {}; // 2 bytes
                // [2 bytes of trailing padding to align whole struct]
}; // Total size: 12 bytes!

struct OptimalLayout {
    int b {};   // 4 bytes
    short a {}; // 2 bytes
    short c {}; // 2 bytes (packs cleanly next to 'a')
}; // Total size: 8 bytes!