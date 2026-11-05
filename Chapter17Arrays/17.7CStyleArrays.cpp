//basic c style array 
//fixed size 
int scores[5];
//5 garbage values

//like std::array data iotself to stored on the stack
//can't have size of 0 unlike std::array 

int scores2[5]{}; //5 zeros 

int scores3[4]{3,21,4};

int scores[]{53,43,43}; // size is deducted 

//C style arrays decay to pointers unlike std::array 

//arr1 = arr2 doesn't work for c style arrays, unlike std::array
//c style array lack member functions 