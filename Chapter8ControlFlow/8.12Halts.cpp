//normal termination -> moving to the end of the int main(){} function, exit status code is passed to the operating system. 

//halt = function call to cease execution 

#include <cstdlib>
#include <iostream>

void cleanup() {
    std::cout << "Running cleanup tasks...\n";
}

void terminateEarly(){
    std::cout << "Terminating... \n";
    std::exit(0);
    //std::exit  flushs all open files and io streams 

    //Calls static destruction, all global and statck variables are cleaned up
    //passes the exit code to the os 
    //stack variables aren't unwinded / clean upped
}

int main () {
    std::cout << "" << std::endl;

    //std::atexit allows a callback for cleanups
    std::atexit(cleanup);

    std::abort(); //Hard stop, no cleanup of streaming io, files, static variables


    std::quick_exit(); // in between exit() and abort(), no full object destruction, but flushs logs / released critial hared resources
}

//best is to exit via main()

//exit is bad, undermines RAII

//abort is good when the program is just corrupted beyond repair 