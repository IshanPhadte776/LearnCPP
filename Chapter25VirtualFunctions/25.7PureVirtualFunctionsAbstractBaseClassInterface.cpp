//Pure virtual functions, functions that are virtual and no implementaiton at the base class level

class Base {
public:
    virtual void function() const = 0; 
};

//For Abstract Base Classes, they can't be instantiated 

//A Abstarct class is one where there's at least 1.= 0; pure virtual function  