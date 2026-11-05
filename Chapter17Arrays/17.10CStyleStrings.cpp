//C style string = const char* or const char[] "Hi" = length of 2 + null terminate \0 so 3

//the number in the [] can be 3 or larger 
char str1[] {"Hi"}; //will add the null terminator string 
//size = 3
//length = 2

//doesn't add null terminater
//length is 2, size is 2
char str2[] {'a', 'b'};

char str[]{ "Alex" };
std::cout << str << '\n'; // Prints "Alex", NOT the memory address!


std::cout << str2 << '\n'; // Prints ab then garbage cause we are wating for that null temrinater 

//if u rlly want to.print the memory address, cast to a point explicitlly
std::cout << static_cast<const void*>(str) << '\n';