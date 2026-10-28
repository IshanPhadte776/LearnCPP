
//Problem, multiple defintions of functions / structs / classes / can cause errors
//main.cpp imports wave.h and square.h. square.h import wave.h. main.cpp will import wave.h twice.
//for function declarations, this is fine, but for classes / structs, can be problematic

//headerguards can be used to prevent ODR issues 
//modern approach
//#pragma once

//old approach 

#ifndef SQUAREH
#define SQUAREH

//all structs, functions go here

#endif

// #Q1) 

#ifndef ADD

#define ADD
int add(int x, int y);
#endif
