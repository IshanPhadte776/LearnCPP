for (int i{ 0 }; i < 3; ++i) {
    for (int j{ 0 }; j < 3; ++j) {
        if (j == 1)
            break; // Exits only the inner j loop; outer i loop continues
        std::cout << i << ',' << j << '\n';
    }
}

//break breaks out the inner most enclosing loop / switch 

int count{ 0 };
while (count < 10) {
    if (count == 5)
        continue; // Bug! Bypasses ++count below, leaving count stuck at 5 forever

    std::cout << count << ' ';
    ++count;
}

//continue ends this iteration, moves to the next iteration

for (int count{ 0 }; count < 10; ++count) {
    if (count == 5)
        continue; // Safe: execution still jumps to ++count before checking condition

    std::cout << count << ' ';
}