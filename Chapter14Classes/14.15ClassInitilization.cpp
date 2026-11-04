//copy constructors are generated automatically if not explicitlly created 



// copy elision -> optimaization so the compiler skips calling copy/move constructors enturely, constructing the object directly in the destination memory 
//originally, creates an unnamed Fraction 5,4, then calls copy consturctor for f, double creations, but this is optimzed so it creates f directly with 5,4 

Fraction f {Fraction {5,4}};


//(unnamed)Return value optimization

Fraction create() {
    //creates the varaible directly in the callers variable
    return Fraction {1,2};
}

//Named  RVO

Fraction create() {
    Fraction f {1,2};
    //optional 
    return f;
}