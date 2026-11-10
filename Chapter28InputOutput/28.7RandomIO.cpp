#include <fstream>
#include <iostream>

int main() {
    // 1. Create a sample file with known content
    {
        std::ofstream out{ "test.txt", std::ios::binary };
        out << "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 26 bytes (indices 0 to 25)
    }

    // 2. Open for reading and writing in binary mode
    std::fstream file{ "test.txt", std::ios::in | std::ios::out | std::ios::binary };
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    // --- tellg() and tellp() ---
    //tellg = current read position 
    //tellp = current write position 
    std::streampos readPos = file.tellg();
    std::streampos writePos = file.tellp();
    std::cout << "Initial read pos: " << readPos << ", write pos: " << writePos << '\n';

    // --- seekg(pos) - Absolute offset from file start ---
    file.seekg(4); // Jump read pointer directly to byte offset 4 ('E')
    std::cout << "tellg() after seekg(4): " << file.tellg() << '\n';
    char ch{};
    file.get(ch);
    std::cout << "Character at byte 4: " << ch << '\n'; // Prints 'E'

    // --- seekg(offset, dir) - Relative seeks ---
    // Move 2 bytes forward from current position:
    file.seekg(2, std::ios::cur); 
    file.get(ch);
    std::cout << "2 bytes forward from current: " << ch << '\n'; // Prints 'H'

    // Move 3 bytes backward from the end of the file:
    file.seekg(-3, std::ios::end); 
    file.get(ch);
    std::cout << "3 bytes before EOF: " << ch << '\n'; // Prints 'X'

    // --- seekp(pos) - Absolute write positioning ---
    file.seekp(0); // Jump write pointer to start of file
    file.put('*'); // Overwrites 'A' with '*'

    // --- seekp(offset, dir) - Relative write positioning ---
    file.seekp(-1, std::ios::end); // Jump to last character before EOF ('Z')
    file.put('#');                 // Overwrites 'Z' with '#'

    // Verify modifications by rewinding and reading the whole file
    file.seekg(0, std::ios::beg);
    std::cout << "Modified content: ";
    while (file.get(ch)) {
        std::cout << ch;
    }
    std::cout << '\n';

    return 0;
}