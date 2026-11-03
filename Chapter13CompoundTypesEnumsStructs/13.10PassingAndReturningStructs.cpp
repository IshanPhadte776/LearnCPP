//Two general approachs, pass by value and pass by const ref 
//pass by value can be expensive for bigger structs 


//pass by rvalue 


struct Employee {
    int id {};
    int age {};
    double wage {};
};

struct Point3d {
    double x { 0.0 };
    double y { 0.0 };
    double z { 0.0 };
};

Point3d getZeroPoint() {
    // Return by value using an aggregate initializer list
    return { 0.0, 0.0, 0.0 }; 
}

// Efficient: passes an 8-byte reference/address, zero member copies
void printEmployee(const Employee& e) {
    std::cout << "ID: " << e.id << ", Age: " << e.age << ", Wage: " << e.wage << '\n';
}


int main() {
    Employee joe {4,5,6.0};// pass by const ref 
    printEmployee(joe);
    printEmployee({4,6,6.8}); //pass by rvalue
}