//nullptr is a value of type std::nullptr_t. pointers should point to this when the pointer is not pointing to anything meaningful

//better than pointing to 0 or ""

int* ptr = nullptr; //ptr is a pointer to int, initialized to nullptr

std::cout << *ptr << '\n'; //ub

//nullptr is a falsely value, dangling pointer is truey

