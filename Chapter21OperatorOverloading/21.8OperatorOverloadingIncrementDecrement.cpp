class Digit {
private:
    int m_digit{};

public:
    explicit Digit(int digit = 0) : m_digit{ digit } {}

    // Prefix: ++d
    Digit& operator++() {
        if (m_digit == 9)
            m_digit = 0;
        else
            ++m_digit;

        return *this;
    }

    // Postfix: d++ (note the dummy 'int' parameter)
    Digit operator++(int) {
        // 1. Create a copy of the current state
        Digit temp{ *this };

        // 2. Delegate to prefix operator++ to increment this object
        ++(*this);

        // 3. Return the saved copy by value
        return temp;
    }

    int getDigit() const { return m_digit; }
};