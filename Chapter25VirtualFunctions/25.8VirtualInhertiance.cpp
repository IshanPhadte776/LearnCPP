//We want to solve the diamond issue 

    //     [ PoweredDevice ]
    //       /           \
    //      /             \
    // [ Scanner ]     [ Printer ]
    //      \             /
    //       \           /
    //        [ Copier ]

//Normally, we get 2 copies of powereddevice, 1 from scanner and 1 from printer 

//this comes from standard public inheritance class Copier: public Scanner {}

//Solution = virtual inheritance 
//Virtual inheritance allows the complier to prevent doubling up on instants of PoweredDevice

class Scanner : virtual public PoweredDevice { // Virtual inheritance
public:
    Scanner(int scanner, int power) : PoweredDevice{ power } {}
};

class Printer : virtual public PoweredDevice { // Virtual inheritance
public:
    Printer(int printer, int power) : PoweredDevice{ power } {}
};

class Copier : public Scanner, public Printer {
public:
    // Copier is now responsible for initializing PoweredDevice directly!
    Copier(int scanner, int printer, int power)
        : PoweredDevice{ power }, Scanner{ scanner, power }, Printer{ printer, power } {}
};

// Copier Memory Layout (Shared Virtual Base):
// ┌────────────────────────────┐
// │ PoweredDevice (Shared)     │  <-- Single shared subobject
// ├────────────────────────────┤
// │ Scanner Subobject          │
// ├────────────────────────────┤
// │ Printer Subobject          │
// ├────────────────────────────┤
// │ Copier Specific Data       │
// └────────────────────────────┘

//In virtual inheritance, the most derived class calls the constructor for the shared base class


//Constructor Order = Virtual Base Classes first (l -> r), non virtual base class (l -> r), derived class, then destruction occurs in the reverse order
