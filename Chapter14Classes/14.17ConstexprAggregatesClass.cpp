// Constexpr classes / aggregates can be used to instantiate class objects at compile time
// bake values / objects at compile time, folded data into assembly instructions
//allows for static_assert
//allows for non-type templat arguments 
//alows for constxpr arays and stuff 

//struct doesn't have to be decalred as a constexpr
struct Point {
    int x{};
    int y{};
};

constexpr Point p {1,2}; //works 


//for classes, if the object is a constexpr (wants to be created at compile time, the constructor it uses, and any functions it calls must be constexpr)

class Fraction {
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Constexpr constructor
    constexpr Fraction (int numerator = 1, int denominator = 1): m_numerator{numerator},
    m_denominator{denominator} {

    }

    //after c++ 14, we need need to make the function as const 
     constexpr int getNumerator() const {
        return m_numerator;}

};

int main() {
    // Evaluated at compile time!
    constexpr Fraction f1{ 3, 4 };
    static_assert(f1.getNumerator() == 3);

    // Can still be used at runtime:
    int n{ 5 };
    Fraction f2{ n, 2 }; // Non-constexpr runtime instantiation
}