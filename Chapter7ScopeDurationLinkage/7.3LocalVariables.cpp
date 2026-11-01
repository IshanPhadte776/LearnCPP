// Local variavle  = variable within a block or a function parameter. 

//Local variables have 3 fundemental properties

// 1. Automatic storage Duration (lifetime)
// 2. Block scope (Visibility)
// 3. No linkage 

// Lifetime (memory) of a local variable is from its created and initialized to the enclosing braces 

int main() {
    int a { 5 }; // a created and initialized

    {
        int b { 10 }; // b created and initialized
    } // b destroyed here

    // b does not exist here
    return 0;
} // a destroyed here

// Scope (visibility), from declaration to end of the block 

//Scope is a compile time property, governing visbility of the identifier 
//Lifetime is a runtime property governing the existence of object in memory 

//Linkage, local variables have o linkage, variables in different blocks with the same name are different entities all together. 


// 4 Storage Durations for variables 
//1. Automatic (Stack Variables)
//2. Dynamic (Heap allocations via new / delete)
//3. Thread (thread_local)
//4. Static 

//Automatic Storage Duration 
// From initialization to closing block (storage lives on the stack call)

//Dynamic Storage Duration
//For dyanmically allocated memory 
// starts on creation, ends w/ delete 

//Thread storage duration
//exists within thread-local storage (TLS) segment 
// allocated when the thread starts, ends when the thread terminates 

thread_local int threadCounter { 0 }; // Each thread gets its own unique copy

//Static storage duration 
//global variavles, exists within .data for initilzed and .bss for zero-initlizaed data
//exists for the entire duration of the program 
//destoryed in reverse order of creation 