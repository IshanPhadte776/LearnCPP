
//Logical AND Symbol == &&   x && y. Checks if both symbols are True 
//Logical OR Symbol || x || y Checks if at least 1 symbol is True s
//Logical NOT ! !x  Flips the operant 

//! is a unary operator, it has higher level than other commands 

if (!x > y) // !x is above > 

// && beats || 

if (a || b && c) // (B and C) or A

if (x == 1 && ++y == 2) // DANGEROUS! // Side effects can cause bugs, C++ short circuits, x != 1, the statement is false, and the right operand is not evaluted and y is never incremented

if (value == 0 || 1) // BUG: '1' converts to true, so this is ALWAYS true!

if (value == 0 || value == 1) // Correct