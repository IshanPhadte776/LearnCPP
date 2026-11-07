// 5 Types of object relationships 

//1. Composition (part-of, shared lifecycle)
//2. Aggragation (has-a independent lifecycle)
//3. Association (use-a, peer/ interactive)
//4. Dependency (depends-on, transient via parameter)
//5. Inheritance (is-a, parent/child subtyping)

//Composition (Part of)

//Strong ownership, theres a complex object with smaller parts. the whole owns the parts, lifecycle of the parts are tied to the owner
//Example - Car has an engine, wheels, door
//Fraction has a numerator, denominator 
//implementation via a unique pointer for the parts 

//Aggregation (Has a / Weak ownership)

//complex object where the smaller objects do not have their lifecycles managed by the big object 
//a part can belong to multiple aggregates 
//Folder has a file 
//Structs 

//Association (Uses-a Peer/Peer Relationship)

//Two independent classes that interact w/ each other, they are decoupled.
//Doctor and Patient classes are peers, both persons 
//uses weak pointers to prevent circular dependencies 

//Dependency 
//Depends on relationship 

//Class A uses Class B, through a single member function 


//Inheritance 
//Is a relationship via interfaces 

//Sedan is a Car, Circle is a Shape