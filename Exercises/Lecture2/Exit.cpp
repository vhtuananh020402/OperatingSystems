#include <cstdlib>
#include <iostream>

int main() {
    // Perform some tasks
    std::cout << "Hello, world!" << std::endl;

    // Terminate the program with an exit status of 0
    std::exit(0);

    // This line will not be executed
    std::cout << "Goodbye, world!" << std::endl;

    return 0;
}
