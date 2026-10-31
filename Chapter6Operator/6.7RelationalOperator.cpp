
if (b1 == true)  // Redundant and cluttered
if (b1)          // Clean idiomatic C++

if (b1 == false) // Redundant
if (!b1)         // Clean idiomatic C++

//avoid == comparing 2 double / floating points 

constexpr double d1{ 100.0 - 99.99 }; // Mathematically 0.01, actually ~0.010000000000005116
constexpr double d2{ 10.0 - 9.99 };   // Mathematically 0.01, actually ~0.0099999999999997868

if (d1 == d2) // Evaluates to false!

bool approximatelyEqualAbs(double a, double b, double absEpsilon) {
    return std::abs(a - b) <= absEpsilon;
}

//naive fallback, just check if the difference is lower than an epsilon