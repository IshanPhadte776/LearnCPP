void badResourceManagement() {
    Person* p = new Person{ "John" }; // Raw dynamic allocation

    doSomethingRisky(); // Throws!

    delete p; // Bypassed during stack unwinding — permanent leak
}

//manual resource allocations + exceptions can lead to memory leaks
//smart pointers. / containers can. prevent these issues from occurs 
//destructors can't have exceptions, destructors run during stack unwinding, can't handle 2 excpetions at the same time

//4 Levels of Exception Safety 

//No Guarantee 
//memory leaks can occur, data invariants can occur, ub can occur 

//Basic Gaurantee
//no memory leaks, data invariants will be fine 
//objects can be safetly destoryed / reassigned 

//Strong Gaurantee
//If any exceptions occurs, the state of the program will be reverted back to the state before the error 

//No Throw / No fail guarantee
//won't throw / fail 


//Exceptions vs Error Codes 

//Error codes (0, -1) are for predictable errors (like invalid password)
//Error codes are good for real time systems 

//Exceptions are for big / weird issues 

