//        basic_istream           basic_ostream
//              ▲                       ▲
//              │                       │
//       basic_ifstream          basic_ofstream
//              ▲                       ▲
//              │       ┌───────────────┘
//              │       │
//           basic_fstream

//istream is a parent to ifstream 

//file io is a subclass of io 
//if/ofstream is used for streaming bytes into and out of files 

//std::ofstream 

#include <fstream>
#include <iostream>
#include <string>

int main () {
    //outputs to a file (writing to a file)
    // std::ofstream outf{"Sample.txt"};


    // //if the file is opened successfully
    // if (!outf){
    //     std::cerr << "Error";
    //     return 1;
    // }

    // outf << "Line 1";
    // outf << 42;

    std::ifstream inf{"Sample.txt"};

    //if the file is opened successfully
    if (!inf){
        std::cerr << "Error";
        return 1;
    }

    // Reading line by line until EOF
    std::string strInput{};
    while (std::getline(inf, strInput)) {
        std::cout << strInput << '\n';
    }

    return 0;
}