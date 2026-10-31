
//Owners vs Viewers Model 

//std::string is an owner 
//will allocate memory for the const char* when making a string 
//allocates memory on the heap for the storage data 
//copies are expensive 

//std::string_viewer is a viewer 
//doesn't allocate any memory for the underlying raw data, just has a pointer 
//viewing is free, requires the owner to not die, can lead to dangling pointer / ub


//Trap) Dangling Pointers 

//Trap) string view from literal 

//Trap) modifying the std::string invalidates the std::string_view 

//Null terminator  
//std::string_view isn't guareeted to end with a null terminator 

//when returning local variables, return std::string,
//when returning sgring literals, std::string_view is better  