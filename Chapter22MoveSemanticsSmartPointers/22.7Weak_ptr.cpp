// if you have 2 objects that have shared_pointers member variables that point to each other, they never get deleted 

//obj1 -> obj2.       obj2 -> 1. Both can't be deleted as they point on each other. 
//obj1 has use_count 2, obj2 has use_count2, after obj is deleted, obj1 use_count = 1, but obj2 use_count = 2
//after obj2 is deleted, obj2 use_case goes to 1. both are at 1 and stuck 



//if both oibjects hold weak pointers, then its different. 

//obj1 -> obj2 (weak) and obj2 -> obj1(weak)

//object 1 can be deleted at first, object 2 is fine cause object 2 holds a weak, non owning pointer to object 1
//then object 2 gets deleted, no issues 



//std::weak_ptr can't be deferred directly using operator* or operator->, must convert to temp std::shared_ptr using .lock()


// Check if the object still exists and acquire temporary shared ownership:
if (auto partnerShared = m_partner.lock()) {
    // Successfully acquired: partnerShared is a valid std::shared_ptr
    std::cout << "Partner's name: " << partnerShared->getName() << '\n';

}


#include <iostream>
#include <memory>
#include <string>

class Person {
private:
    std::string m_name;
    std::weak_ptr<Person> m_partner; // Shared ownership to partner

public:
    Person(const std::string& name) : m_name{ name } {
        std::cout << m_name << " created\n";
    }
    ~Person() {
        std::cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2) {
        if (!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';
        return true;
    }
};

int main() {
    auto lucy = std::make_shared<Person>("Lucy");
    auto ricky = std::make_shared<Person>("Ricky");

    partnerUp(lucy, ricky);

    return 0;
}