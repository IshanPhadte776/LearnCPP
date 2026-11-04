//temp objects are unnamed objects that are created and destroyed 

#include <iostream>

class Dollars {
private:
    int m_dollars{};

public:
    Dollars(int dollars) : m_dollars{ dollars } {}
    int getDollars() const { return m_dollars; }
};

void print(const Dollars& d) {
    std::cout << "$" << d.getDollars() << '\n';
}

int main () {
    //Temp Class object, unnamed, created and deleted on the same line 
    //rvalues, 
    //can't bind to non const refs
    //can bind to const refs 
    //good for one off calls, don't want to bloat the namespace 
    print(Dollars{7});
}