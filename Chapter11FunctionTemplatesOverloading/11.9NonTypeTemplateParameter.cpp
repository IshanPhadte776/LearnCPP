//Non-type template parameters (NTTP)

//assert -> run time checking 
//static_assert -> compile time checking 

//static_assert requires all variables / literals to be constexpr 

//For function calls, void func(int 5) func(5), 5 is allocated at runtime on the stack., function call is placed in the stack (nonconstexpr)

//NTTP solves this problem, passes in the variable at compile time (allows for static_assert)


template <int N>
void func () {
    static_assert(1 < N, "N gotta be above 1");
}

int main (){
    func<5>();
}