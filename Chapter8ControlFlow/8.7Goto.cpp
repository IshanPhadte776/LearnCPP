//goto makes an unconditional jump that directs the cpu to another location in the function 
//goto is awful, leads to confusing code 

goto skip;
int x { 5 }; // Compile error: jump bypasses variable initialization
skip:
    // x is in scope here, but uninitialized

    // you ccan't jump pass variable intilization 

    //goto allows for breaking outta nested loops, only good usecase 