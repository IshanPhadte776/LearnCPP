// auto drops reference 

int x{5};

int& ref {x}; //ref is an LValue reference to x

auto a{ref};

//auto comes int, not int&

//if we want &, add it explcitly 

auto& b{ref};

//auto drops high level const 

const int x{ 5 };

auto a{ x };       // Deduced type: int (top-level const dropped; a can be modified)
const auto b{ x }; // Explicitly const: const int

//pointers aren't dropped by auto 

int x{ 5 };
int* ptr{ &x };

auto p1{ ptr };  // Deduced type: int*
auto* p2{ ptr }; // Deduced type: int* (explicitly signals pointer syntax)


//Constness w/ Pointers, high level const is dropped, low level const is not dropped


//low level const 
const int* cptr{ &x };

auto p3{ cptr };  // Deduced type: const int* (low-level const preserved)
auto* p4{ cptr }; // Deduced type: const int* (can reseat p4, but can't modify the value it points to)

//high level const

int* const cptr2{ &x };
auto p5{ cptr2 };  // Deduced type: int* (high-level const dropped; p5 can be reseated)
const auto* p6{ cptr2 }; // Deduced type: int* const (high-level const preserved)