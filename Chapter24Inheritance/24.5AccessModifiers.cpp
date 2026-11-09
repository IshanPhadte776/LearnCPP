//Private - only in this class's member functions (and friends)
//public - any access 
//protect only within this class and its derived classes (and friends)


class Derived : public Base     // Public inheritance (99% of use cases)
class Derived : protected Base  // Protected inheritance (rare)
class Derived : private Base    // Private inheritance (rare)

//Public inhertence , passes down all public / protected, doesn't pass down private
//protected does the same as public inhertiance, just in the base = public, now is protected.
//private inheritance makes all inherited / base class members private in this usage (only the public / protected)

//Classes have private inheritance by default 
//structs have public inheritance by default 