// a conversion doesn't alter the original object . It read the original value, constructs a temp copy holding the converted value 

float getValue() {
    return 3.0; // double 3.0 -> float 3.0f
}

//implicit conversion fails when there isn't a valid conversion 

//brace initialization blocks implicit conversion 


int i = 3.5; ///this is 3

int j {3.5}; //This doesn't work 