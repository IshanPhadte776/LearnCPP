namespace {
    void doSomething() { //Intenal Linkage 
        std::cout << "v1\n";
    }
}

int main() {
    doSomething(); //perfectly fine 
    return 0;
}

//for unnamed namespaces, no need for the :: scope resolver, 
//advantage of unnamed namespace is all functions / variables have internal linkage by default, better than naming them all static / const
//no unnamed namespaces in header files, code bloat and odr maybe 

//inline namespaces are present for API Versioning 

namespace V1 {
    void doSomething () {std::cout << "V1\n"}
}

inline namespace V2 {
    void doSomething() { std::cout << "V2\n"; }
}

doSomething(); // ->calls the inline version by default 
V1::doSomething(); // can be called explicitly 
//The lastest version gets the inline keyword

