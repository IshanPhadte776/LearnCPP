// Internal Stream State Flags 

//State Flag: goodbit -> stream is healthy.      stream.good() 
//State Flag: eofbit  -> stream hit eof          stream.eof()
//State Flag: failbit -> recoverable error       stream.fail()
//State Flag: badbit  -> unrecoverable i/o error stream.bad()

std::cin.clear() -> flips off the stream.fail bit 

std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');