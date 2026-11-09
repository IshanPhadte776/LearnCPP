
//The child / subclass can't initialize member variables for the parent class in the subclass

class Person {
public:
    std::string m_name;
    int m_age;
};

class Employee : public Person {
public:
    double m_hourlySalary;

    // ANTI-PATTERN:
    Employee(std::string_view name, int age, double hourlySalary)
        : m_name{ name }        // COMPILE ERROR or BAD PRACTICE
        , m_age{ age }          // Cannot initialize base members here
        , m_hourlySalary{ hourlySalary } {}
};

//Rule of initialization - a class can only initialize the member variables for itself 


//Solution - just call the parent constructor 

// public:
//     // Call the base constructor Person(...) in the initializer list:
//     Employee(std::string_view name, int age, double hourlySalary, long id)
//         : Person{ name, age } // 1. Construct Person base subobject first
//         , m_hourlySalary{ hourlySalary } // 2. Construct Employee members
//         , m_employeeID{ id } {}
// };

//Execution Order:
// When frank is instantiated, memory for Person + Employee is allocated.

// The Employee constructor calls Person{ name, age }.

// Person's constructor initializes m_name and m_age.

// Control returns to Employee, initializing m_hourlySalary and m_employeeID.

// The Employee constructor body executes.


// class Derived : public Base {
// public:
//     // Base is ALWAYS constructed first, even if written second:
//     Derived(int b, int d) : m_derivedVar{ d }, Base{ b } {} 
// };