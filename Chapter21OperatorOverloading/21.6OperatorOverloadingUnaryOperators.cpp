#include <iostream>

class Point {
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    // Default and parameterized constructor
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z } {}

    // --- Unary Operator Overloads (Member Functions) ---

    // Unary - (negation): produces a negated copy
    Point operator-() const {
        return { -m_x, -m_y, -m_z };
    }

    // Unary + (identity): returns a copy of *this
    Point operator+() const {
        return *this;
    }

    // Unary ! (logical NOT): true if point sits at the origin (0, 0, 0)
    bool operator!() const {
        return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
    }

    // --- Stream Overloads (Non-Member Friends) ---

    // Stream insertion (chained output)
    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';
        return out;
    }

    // Transactional stream extraction (prevents partial-state corruption)
    friend std::istream& operator>>(std::istream& in, Point& point) {
        double x{};
        double y{};
        double z{};

        if (in >> x >> y >> z) {
            point = Point{ x, y, z }; // Commit only if all reads succeed
        }

        return in;
    }

    // Getters
    double x() const { return m_x; }
    double y() const { return m_y; }
    double z() const { return m_z; }
};

int main() {
    const Point p1{ 1.5, -2.0, 3.25 };
    Point origin{};

    std::cout << "Original p1: " << p1 << '\n';

    // Unary minus: invokes p1.operator-()
    Point negated{ -p1 };
    std::cout << "Negated p1:  " << negated << '\n';

    // Unary plus: invokes p1.operator+()
    Point identity{ +p1 };
    std::cout << "Identity p1: " << identity << '\n';

    // Unary !: invokes origin.operator!() and p1.operator!()
    if (!origin) {
        std::cout << "origin is set to (0, 0, 0)\n";
    }

    if (!p1) {
        std::cout << "p1 is at origin\n";
    } else {
        std::cout << "p1 is not at origin\n";
    }

    return 0;
}