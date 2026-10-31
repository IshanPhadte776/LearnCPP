
// ?: has level 16 (just better than comma)
constexpr bool inBigClassroom {false};

//if true -> 1 else -> 2
constexpr int classSize { inBigClassroom? 30 : 20};


//Pitfalls 

//std::cout << beats ?:
int x { 2 };
std::cout << (x < 0) ? "negative" : "non-negative"; // BUG! , just prints 0
//Complier sees this as (std::cout << (x < 0)) ? "negative" : "non-negative";

std::cout << (x < 0) ? "negative" : "non-negative";

