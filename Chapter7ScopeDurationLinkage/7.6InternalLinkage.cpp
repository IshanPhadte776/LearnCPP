//Internal Linkage -> variable is accessible anywhere in the translation unit (this file + header files). not accessible by linker and other translation units 

// const / constexpr / static leads to internal linkage 
// else -> external linkage 

static int g_x; //internal (non zero)
static int g_x{1}; //internal non const 

const int g_y {2}; // internal 
constexpr int g_z {3}; // internal 


extern const int g_x { 5 }; // External linkage (accessible from other files)

inline constexpr int g_x { 5 }; // External linkage 

//local varaible have no linkage 

