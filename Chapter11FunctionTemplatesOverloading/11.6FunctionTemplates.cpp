//We want to prevent rewriting similiar code over and over again
// this a add function, we dont' need add(int,int) and add(double,double)
//Also future proofing for future types 


template <typename T> // Template parameter declaration
T max(T x, T y){ //Function template definition (primary template)
    return (x>y)? x : y;
}


//template <> tells the complier this is a template declaration
//typename T, definies a type template parameter of type T, placeholder for the type 

//Scope of type T is just for the single function / class directly following it 

//typename and class are the same to the complier, typename is prefered in modern c++, more generic
// Its the convenetion to use uppercase single letters for it, letters are for any reasonable type 

//Descriptive names are fine like Allocator / TCompare when we want specific behaviour 

//Primary Template -> oriignal template definition 
//Type Template Parameter (T)
//Template arguments, types that are being substituted in 
//Instantiated function -> what the complier subs in for the primary template. 
