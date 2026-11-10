Operation,Syntax,Action
Allocation,Type* p = new Type{ value };,Allocates memory on the heap and initializes the object.
Deallocation,delete p;,Destructs object and releases heap block back to the OS.
Post-Delete Habit,p = nullptr;,Prevents accidental dereferencing of a dangling pointer.
Failure Mode,Throws std::bad_alloc,Pass (std::nothrow) if you want a nullptr return instead.
Double Free,Calling delete twice,Undefined behavior unless reset to nullptr between calls.

