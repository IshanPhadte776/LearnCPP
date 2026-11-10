#include <iomanip>


std::cout << 42 << " " << 3.14159 << '\n';

//Under the hood, C++ converts the types to characters for output
//The state / how the variables / text gets converted to characters is dictated by the std::ios_base 

//Member functions, not preferred 
std::cout.setf(std::ios::showpos) // Set Flag
std::cout.unsetf(std::ios::showpos) //Clear Flag

//Stream maniulators (preferred)

std::cout << std::showpos << 42 << '\n'; // cleaner syntax 

//instead of printing 1 for true, will print true raw
std::cout << std::boolalpha << true << '\n'; // "true"
std::cout << std::noboolalpha << true << '\n'; // "1"

//Numeric bases
std::cout << std::hex << std::showbase << 42 << '\n'; // 0x2a

double pi{ 3.14159265 };
std::cout << std::setprecision(4) << pu << '\n'; //3.142 (sig fig)
std::cout << std::fixed << std::setprecision(2) << pi << '\n'; //3.14 - 2 digits after the dot 

//std::showpow -> display the leading + for non negative numbers 
//std::noshowpow -> oppose 



