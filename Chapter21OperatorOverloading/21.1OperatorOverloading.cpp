//Operators like + are defined for tyopes like int and pointer allowing for 

int x{5};
int y{5};
printf(x + y);

//This doesn't work for custom classes like Fraction / Point, the + operator isn't defined for this class 

//Translates this calls
//Fraction f3 { f1 + f2};

//To this
//Fraction f3  {operator+ (f1, f2)}; // non member function
//or this
//Fraction f3 {f1.operator+(f2)}; //member function

