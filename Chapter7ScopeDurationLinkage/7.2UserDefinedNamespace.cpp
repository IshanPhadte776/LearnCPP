// Naming Collisions, 2 functions can't have the same name, 2 variables can't have the same name, ODR Rule 
//Namespaces can fix this, they are like last names. 

namespace Foo {
    int doSomething (int x, int y) {
        return x + y;
    }
}

namespace Goo {
    int doSomething (int x,int y) {
        return x - y;
    }
}


// ::identifer selects from the global namespace.
void print () { std::cout << "Global\n"; }

namespace Coo {
    void print () {std::cout << "Foo\n";}

    void test() {
        print(); //picks the print from this namespace 
        ::print(); //picks the print from the global namespace
    }
}

namespace Poo {
    namespace Loo {
        int add(int x, int y) { return x + y; }
    }
}


//Namespaces can only exist all global level or nested in another namespace, never within a function or block 

// :: is the scope resolution operator 

int main() {
    std::cout << Foo::doSomething(4,3) << "\n";
    std::cout << Goo::doSomething(4,3) << "\n";
}

//First, look for current namespace, then nested namespace, then global namespace, then error 


//namespace Alias 

namespace Active. = Poo:Loo;

std:: cout << Active::add(1,2);