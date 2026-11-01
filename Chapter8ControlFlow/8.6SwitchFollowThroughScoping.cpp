switch (2) {
    case 1:
        std::cout << "1 ";
    case 2:
        std::cout << "2 "; // Matches here
    case 3:
        std::cout << "3 "; // Executes due to fallthrough!
    default:
        std::cout << "Def"; // Executes due to fallthrough!
}
// Outputs: 2 3 Def

bool isVowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

switch (x) {
    case 1: { // Explicit block created
        int y { 5 }; // Completely legal
        std::cout << y;
        break;
    } // y goes out of scope here
    case 2:
        std::cout << "Two\n";
        break;
}