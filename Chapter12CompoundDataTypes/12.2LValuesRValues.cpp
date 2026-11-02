//LValues have address / identifiers, RValues do not have address / identifiers

//LValues may or may not be modifable, RValues are always modifiable

const int x = 10; // x is an LValue, but not modifiable
int y = 20; // y is an LValue and modifiable

//LValue can be on either side of an = side
//RValue can only be on the right side of an = side

//Prefix vs Postfix

++y //y is an LValue, increments and return an LValue 

y++ //y is an LValues, increments and returns an RValue of y's value before the increment

//String Literals 

//Numeric literals are RValues 3.14, 5
//C style string literals like "Hello" are lvalues because they are stored in static read-only memory as const char[6] and must have an address and decayable to a pointer