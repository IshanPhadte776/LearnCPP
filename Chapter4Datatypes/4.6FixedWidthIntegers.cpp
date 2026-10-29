// There's a minimum width and maximum width for each integer type, and the fixed width integer types are guaranteed to have that width on all platforms. For example, int32_t is guaranteed to be 32 bits on all platforms, while int is only guaranteed to be at least 16 bits. The fixed width integer types are defined in the <cstdint> header.

#include <cstdint>



std::int8_t a = 127; // 8-bit signed integer

std::int16_t b = 32767; // 16-bit signed integer

std::int32_t c = 2147483647; // 32-bit signed integer

std::int64_t d = 9223372036854775807; // 64-bit signed integer

//use int for basic variables and/or you know which bit arch (32 vs 64) you are one 
//use int8_t when you want portable code that is guaranteed to be 8 bits on all platforms, and you want to save memory


//sizeof(int) returns a std::size_t, its a portable class that is guaranteed to be able to hold the size of any object in bytes, and is the type returned by sizeof operator. std::size_t is an unsigned integer type, and is defined in the <cstddef> header.
//std::size_t will scale down on smaller systems, holds the largest unsigned interger that can be represented on the system, and is guaranteed to be able to hold the size of any object in bytes. std::size_t is an unsigned integer type, and is defined in the <cstddef> header.