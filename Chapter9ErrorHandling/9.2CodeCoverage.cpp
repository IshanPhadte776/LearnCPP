//Statement Coverage 
//What percentage of statements are evaluted 

int foo(int x, int y) {
    int z{ y };
    if (x > y) {
        z = x;
    }
    return z;
}

//All statements are called when (1,0) when passed, not when 0,0 is passed

//Branch Coverage, what percentage of the branchs from a statement are exercised 

// foo(1,0) gets 50% branch coverage, foo(0,1) + foo(1,0) gives 100% branch coverage, handling both the true and false branch coverage  

//statement coverage = does all lines of code get executed 
//branch coverage = every decision outcome has been tested (both true and false)