
struct Something {
    int x{5}; //5 init
    int y{};  // zero init
    int z; //no default value init // doesn't allocate memory 
};

//explicit values in the callers initialization list is the first priority
//second priority = default member fallback 
//third priority = 0 init if {}
//4th -> garbage  