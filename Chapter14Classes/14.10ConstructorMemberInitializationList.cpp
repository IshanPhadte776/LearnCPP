//Initialization vs Assignment of member variables in constructors 

class Foo {
    int m_x {};
    int m_y {};
public:
    Foo(int x, int y) {
        m_x = x; // Assignment, NOT initialization
        m_y = y;
    }
};

class Foo2 {
private:
    int m_x {};
    int m_y {};

public: 
//Body executes after the variables have been initialized
    //initialized in the order in-which they show up up top, not below here 
    Foo2 (int x, int y): m_x{x}, m_y{y} {

    }

};

//This creates int m_x{} and m_y on creation of the object (using initalization), THEN goes to the contructor and reassigns values to the member variables 

//In this case, it's fine, doesn't work for const member variables 

