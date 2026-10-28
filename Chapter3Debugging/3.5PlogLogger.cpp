#include "plog-master/include/plog/Log.h"
#include "plog-master/include/plog/Initializers/RollingFileInitializer.h"
#include <iostream>


int getUserInput(){
    PLOGD << "getUserInput() called";
    std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main () {

    plog::init(plog::debug, "Logfile.txt");
    
    PLOGD << "main() called"; // Step 3: Output to the log as if you were writing to the console

	int x{ getUserInput() };
	std::cout << "You entered: " << x << '\n';

	return 0;

}

//clang++ -std=c++17 -I plog-master/include 3.5PlogLogger.cpp -o logger