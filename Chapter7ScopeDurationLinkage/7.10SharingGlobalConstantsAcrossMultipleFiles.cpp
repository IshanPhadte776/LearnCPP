// constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {
    inline constexpr double pi { 3.14159 };
    inline constexpr double gravity { 9.8 };
}

#endif

//How to have global external const variable, use the inline keyword
//inline tells the compile, 1 memory address, all translation units share the same variable 