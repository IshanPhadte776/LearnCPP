class Fraction {
private:
    int m_numerator{ 0 };     // Default value
    int m_denominator{ 1 };   // Default value

public:
    // 1. Default constructor: uses in-class default values
    Fraction() = default;

    // 2. Initializer list constructor: explicitly overrides default values
    Fraction(int numerator, int denominator)
        : m_numerator{ numerator }, m_denominator{ denominator } {}

    // 3. Partial constructor: overrides m_numerator, keeps m_denominator's default
    Fraction(int numerator)
        : m_numerator{ numerator } {}
};