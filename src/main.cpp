#include <iostream>
#include "bash2tcl/compiler.h"

int main() {
    Compiler compiler;
    int res = compiler.parse();
    std::cout << "Compiler exited with code " << res << std::endl;
    return 0;
}