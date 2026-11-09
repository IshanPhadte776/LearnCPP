//Partial template specialization is a specialization will provide a subset of 1 type+ but requires at least 1 generic type as well 

template <typename T, int size> // Primary: 2 parameters
class StaticArray;

// Partial specialization: 'T' is locked to double, 'size' is still passed in
template <int size>
class StaticArray<double, size> { /* ... */ };

//We locked in double for the static array, still gotta pass in an INT 

template <typename T> // Primary: 1 parameter
class Storage;

// Partial specialization: Matches ANY pointer type (T*, int*, double*, Widget*)
template <typename T>
class Storage<T*> { /* ... */ };

//We reduce the set inwhich T can be from a any -> pointer 

//Full specialization = template<>, the types are unbounded, all values must be hardcoded and passed in at compile time StaticArray<int,5> 

//Partial Specialization = at least 1 time is generic. either pass the type in <double>, <int> or value <5>