//just like standard classes, there's built in exceptions 
//these built in exceptions are really just classes 
//we can make our own exceptions (classes)

#include <string>
#include <string_view>

class ArrayException {
private:
    std::string m_error;

public:
    ArrayException(std::string_view error) : m_error{ error } {}
    const std::string& getError() const { return m_error; }
};

int getElement(int index) {
    if (index < 0 || index >= 10)
        throw ArrayException{ "Invalid index!" };

    return s_array[index];
}