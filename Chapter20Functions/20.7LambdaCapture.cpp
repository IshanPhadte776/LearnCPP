//capturing can be done by value, reference (when passing a specific variable)
//Then there is default capturing [=] [&]
//default cpaturing captures all referenced local variables in this scope. 
//[=] default capture by value 
//[&] default capture by reference 
//default capturing isn't recommended, less information is being passed and communicated 

//When capturing by reference, don't allow its lifetime to exceed thje lifetime of the original variable 


#include <iostream>

int main () {
    std::cout << "" << std::endl;
    int target {10};

    auto checkMatch {[target](int val){return target == val ;}};
    auto checkMatch2 {[&target](int val){return target == val;}};

    //by default, () variables  are marked as const, so val can't be mutated unless the mutable key follows after ()

    auto checkMatch3 {[&target](int val) mutable {val++; return target == val;}};


    target = 20; // doesn't change anything for the function

    std::cout << checkMatch(10) << '\n'; // Prints 1 (true)
    std::cout << checkMatch2(10) << '\n'; // Prints 0 (true)

}