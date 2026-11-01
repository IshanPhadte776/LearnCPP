//assert is a preprocesser macro that used to determine if an invariant holds at runtime
//program will std::abort() if false 

//static assert enables compile time assert statements s

static_assert(sizeof(int) == 4, "Int must be 4 bytes");

assert(4 > 3);