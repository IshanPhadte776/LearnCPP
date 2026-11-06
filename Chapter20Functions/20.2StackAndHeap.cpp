//Code / Text Segment = read-only compiled machine instructions 
//Data / BSS segment .data for initialized data .bss for uninitialized / zero initialzed 
//Heap -> dynamically allocated memory at runtime, new, malloc, std::vectgor 
//Call Stack, function cals, return addresses, local variables, parameters 

//Stack frame, anything above the stack pointer is in the frame and legit, anything outside isn;t, everytjhing is done in LIFO 

//Fragmentatio only can occur for the heap, not for stack
//stack has contigious memory, heap isn't always contigious 