//VTable - its created at compile time, an in-memory representation of the vtable is present at runtime 
//There's a per-instance virtual table pointer (__vptr)

//vtable -> complier makes 1 table per class if theres at least 1 virtual function
//has an array of pointers corresponding virtual methods availiable for the class

// the __vptr is a hidden member variable that the complier adds to every class that has a vtable. 
//its a pointer to its VTable 

//Concrete exmaple of a VTable 

// class Base {
// public:
//     virtual void function1() {}
//     virtual void function2() {}
// };

// class D1 : public Base {
// public:
//     void function1() override {} // Overrides function1
//     // function2() is inherited as-is from Base
// };

// class D2 : public Base {
// public:
//     void function2() override {} // Overrides function2
//     // function1() is inherited as-is from Base
// };

// Base's Vtable:

// Slot 0: &Base::function1()
// Slot 1: &Base::function2()

// D1's Vtable:

// Slot 0: &D1::function1() (overridden)
// Slot 1: &Base::function2() (inherited entry)

// D2's Vtable:

// Slot 0: &Base::function1() (inherited entry)
// Slot 1: &D2::function2() (overridden)

// Signature Matching at Compile Time: While parsing the derived class, the compiler walks up the inheritance tree and checks if any inherited function shares the exact same name, parameter types, const qualification, and the virtual marker.

// Slot Overwrite in the Derived Vtable: If all criteria match, the compiler identifies the assigned index slot for that base virtual function and writes the address of the derived function (&D1::func1) into the derived class's vtable instead of the base version.

// Verification via override: Appending the override specifier forces the compiler to fail compilation immediately if it cannot find an exact matching virtual base signature, preventing accidental shadows or typos.