//shared pointer keeps a pointer to the managed object and pointer to the control block on the stack 
//mamanged object and control block itsself on the heap 

// Stack Frame                                   Heap
// +-------------------------+                   +-------------------------+
// | shared_ptr<T>           |                   | Managed Object (T)      |
// |  - T* ptr -------------->-----------------> |                         |
// |  - ControlBlock* cb ---->--\                +-------------------------+
// +-------------------------+   \               +-------------------------+
//                                \------------> | Control Block           |
//                                               |  - Strong Ref Count (1) |
//                                               |  - Weak Ref Count   (0) |
//                                               |  - Custom Deleter/Alloc |
//                                               +-------------------------+

//std::make_shared > new 

//make_shared does just 1 allocation onnthe heap. jsut 1 spot 
//new makes 2 allocations on the heap 


//this makes 2 allocations on the heap,
std::shared_ptr<Resource> ptr {new Resource()};

auto ptr = std::make_shared<Resource>();

//use case is for caches, many owning, many caching stuff