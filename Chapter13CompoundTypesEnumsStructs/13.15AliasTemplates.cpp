// Type Alias only works when we provide concrete types 

template <typename T, typename U>
struct Pair {
    T first{};
    U second{};
};


using Point2D =  Pair<int,int>; // This will work, passes in the type at compile time 




//Alias Template 

template <typename T>
using Coord = Pair<T,T>;

int main () {
    Coord<int> p1 {4,5};
    Coord<double> p2 {5.4,5.5};
}