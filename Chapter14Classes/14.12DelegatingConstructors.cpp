//Delegating Constructors allow a constructor to call another constructor 


class Employee {
private:
    std::string m_name{};
    int m_id{};

public:
    //calls the second constructor 
    Employee(std::string_view name): Employee{name, 0} {

    }

    Employee(std::string name, int id): m_name(name), m_id(id) {
        std::cout << "Employee" << id << " " << std::endl;
    }
};

//Executing order -> Member variable initialization -> cosntructor -> destructor -> member variable destructor 