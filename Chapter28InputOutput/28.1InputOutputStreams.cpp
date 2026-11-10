//Streams are a core abstarction built so programs can easily collect / send text to specific end points without worrying about the implemation details 

//Stream = Ordered Sequence of bytes that flows between application and external device / buffer 

//Input Stream = carries data from source (keyboard / file / network) into a program's memory 

//Output Stream = carries data from program's memory into external devices (terminal window)

// Narrow (char) Wide (wchar_t) Standard Channel,        Buffering   Behavior,Default Destination
// std::cin.     std::wcin.     Standard Input (stdin)   Buffered    Keyboard / Input redirection
// std::cout.    std::wcout.    Standard Output (stdout) Buffered    Terminal screen / Output redirection
// std::cerr.    std::wcerr.    Standard Error (stderr)  Unbuffered  Terminal screen
// std::clog.    std::wclog.    Standard Log (stderr)    Buffered    Terminal screen

Performance Rule: In performance-sensitive code or tight loops, prefer '\n' over std::endl to avoid redundant system calls.

// /n is buffered, endl is unbuffered 