//Ways to display Errors 

//Option 1. Return Code for functions / Error Flags 

func() {
    return -1;
}

//Simple, but can be cluttered and be lose in the code, -1 return can mean something else, -1 is the sume of a n address


//Option 2. Out parameters 

double divide(double x, double y, bool& success) {
    if (y == 0.0) {
        success = false;
        return 0.0;
    }
    success = true;
    return x / y;
}

//success variable is passed into the function, is updated within the code of the function. 
//issue is that the dev can forget to check the success variable, just takes more memory, more cpu cycles to valid


//Option 3. Global Error Variable 
//Issue is constantly checking for a global error. Wastes CPU cycles and storage space 