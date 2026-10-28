
//Naming collisons, when multiple functions/ variables / entities have the same name. Generic and can happen in any language. ODR is C++ exclusive
//Naming collisions are caught by the complier / linker. ODR commonly isn't and causes undefined behavior
//naming collisions, 2 different things have the same name 
//ODR = Same logical entity has multiple definitions


//Namespaces
//entites must be unique in their namespace, but can have the same name as entities in different namespaces 
//Namespace = named scoped region for entities to exist. 
//Namespace is like a last name, there's john smith and john doe, Doe::john and smith::John. 


//Global namespace
//For all variables not in functions
//That's why std exists, so we have the std::list and list = {1,2,3}

//Access namespace variables 
//use the :: operator, scope resolver operater
//std::cout

//using directives works as well 

//using namespace std;
//not recommended as it can cause name collisions


//{} specific scope 