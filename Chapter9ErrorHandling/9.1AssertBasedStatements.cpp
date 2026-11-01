#include <cassert>
#include <iostream>

bool isLowerVowel(char c) {
    switch (c) {
        case 'a': case 'e': case 'i': case 'o': case 'u': return true;
        default: return false;
    }
}

int main () {
    std::cout << "" << std::endl;

    //When an assert fails, the program crashs

    assert(isLowerVowel('a'));
    assert(!isLowerVowel('b'));
    assert(!isLowerVowel('c'));
    assert(isLowerVowel('e'));

}