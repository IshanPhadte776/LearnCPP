// object pointer are stored in the stack 
//the manaaged object is on the heap

//plain objects (assume in function) uis on the stack
//object via new, make_unqiue, make_shared goes in the heap, stack gets the pointeer

#include <iostream>
#include <memory>
#include <string>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
    void sayHello() const { std::cout << "Hello!\n"; }
};


struct Player {
    std::string name;

    Player(std::string n) : name{ std::move(n) } {
        std::cout << name << " entered the game.\n";
    }

    ~Player() {
        std::cout << name << " left the game (destroyed).\n";
    }

    void attack() const {
        std::cout << name << " attacks!\n";
    }
};

// Factory: allocates on the heap and transfers ownership out
std::unique_ptr<Player> spawnPlayer(std::string name) {
    return std::make_unique<Player>(std::move(name));
}

void runBattle() {
    // 1. spawnPlayer creates the object on the heap
    // 2. Ownership is moved directly to 'hero' in this stack frame
    auto hero = spawnPlayer("Warrior");

    hero->attack();

    // Imagine an early return or game-over condition:
    bool quitEarly = true;
    if (quitEarly) {
        return; // No memory leak! 'hero' goes out of scope here.
        //raw pointer / no pointer would require us to call delete on everything
        //in this case, because our hero is a smart pointer, the destructor is called uatomaitcally and the std::string is deallocated on the heap 
    }

    // No manual 'delete' needed anywhere
}

int main() {
    //so we create a REsource object to work wt/ and wrap it with a smart pointer, smart pointer gives us RAII, in this case, its overkill as res doesn't store anything on the heap.
    //smart pointers are needed when we want the resource to outlive the lifetime of the function that created it 
    //this example is an overkill for smart pointers 
    std::unique_ptr<Resource> res { new Resource{}};

    runBattle();

}