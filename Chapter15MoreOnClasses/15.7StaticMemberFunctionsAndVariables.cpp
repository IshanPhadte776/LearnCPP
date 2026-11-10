// Feature,Non-Static Members,Static Members
// Storage / Lifetime,Per instance; created/destroyed with object,One copy for entire program; static storage duration
// Invocation / Access,Requires an object (obj.member),Directly via class scope (Class::member)
// this Pointer,Passed implicitly (Type* const),None
// Can Access,Both static and non-static members,Only static members (unless passed an explicit instance)
// const Qualified?,Yes (void foo() const;),No (syntax error)
// Initialization,In constructor or member default,inline static (C++17) or defined in .cpp