void display(int x);

void display(const int x); //this doesn't work for function overloading (Adding high level const), const copy by value


void print(int x);
void print(int& x);

int a{ 5 };
print(a); // Compile error: ambiguous! Both functions are viable matches

void process(int& x);       // Matches non-const lvalues
void process(const int& x); // Matches const lvalues and rvalues (literals, temporaries)
//const references are fine for function overloading 

