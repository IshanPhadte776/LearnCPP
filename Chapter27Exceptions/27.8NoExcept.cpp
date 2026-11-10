//in c++ 98, we could declare what types a function could throw
void doSomething() throw(int, double); // C++98: promised only to throw int or double
void neverThrows() throw();            // C++98: promised not to throw anything

//could not be checked at compile time

//Modern solution is to use noexcept specifier
//For Modern C++, functions are classised in 2 broad categories 

//1. Potentially throwing functions 
//2. Non throwing functions (marked w/ noexcept)


void printValue(int x) noexcept { // Guaranteed not to emit exceptions
    std::cout << x << '\n';
}

//We promise not to throw any exceptions 

//if an exception does occur, it will be contained here, if not, std::terminate will be called, stack unwinded isn't guaranteed 

//noexcept can be used as a compile operator too, checks if a function is marked as noexcept  == true 

void fastTask() noexcept;
void normalTask();

int main () {
    constexpr bool b1 {noexcept(fastTask())};
    constexpr bool b2 {noexcept (normalTask())};
}