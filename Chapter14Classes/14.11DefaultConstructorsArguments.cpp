//default constructor is th ecosntructor that is invovled when passed in 0 arguments
//default constructor != default initilization 

class Ambiguous {
public:
    //Ambiguous() = default //Explicitly default contructor 

    Ambiguous() {}
    //this is also a default constructor, cause it works when u pass in no arguments
    Ambiguous(int x = 0; int y = 0) {}


};


//implicit default constructor 

class AutoGen {
    //auto generates 
    //AutoGen() {}
    int x{};
};

//Implicit is better, complier does zero initalization

Foo foo{}; // value initialization, calls Foo() default constructor
Foo foo2;  // default initialization, calls Foo() default constructor