//Pointers have 2 components, the pointer itself and the object it points to

//3 Combos of const usage of pointers 

int x{10};
int y{20};
const int z{30};

//Const pointer to a const object

const int* const ptr1 {&x};

//ptr1 = &y; const pointer Error
//x = 20; const object  Error

//Const pointer to a non-const object

int* const ptr2 {&x};

//ptr2 = &y; const pointer //Error
//*ptr2 = 20; non-const object //Fine

//A nonconst pointer can;'t point to a const object 