
#include <type_traits>


//this allows for multiple types 
template <typename T, typename U>
auto add(T x, U y){
    return (x > y)? x : y;
}



template <typename T, typename U>
std::common_type_t add2(T x, U y){
    return (x > y)? x : y;
}

//std::common_type_t is the common type (that can be deducted to if required)




auto max(auto x, auto y) {
    return (x < y) ? y : x;
}

template <typename T, typename U>
auto max(T x, U y) {
    return (x < y) ? y : x;
}

//These 2 codes are the same more or less
//only difference is T,T forces the same time 