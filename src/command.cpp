#include "command.hpp"
#include <iostream>

Command::Command(WordList* wordlist)
    : assignmentlist(nullptr), wordlist(wordlist) {
}

Command::Command(AssignmentList* assignmentlist)
    : assignmentlist(assignmentlist), wordlist(nullptr) {
}

Command::Command(AssignmentList* assignmentlist, WordList* wordlist)
    : assignmentlist(assignmentlist), wordlist(wordlist) {
}

void Command::print(size_t indent) {
    if (assignmentlist) {
        if (wordlist)
            assignmentlist->print_env(indent);
        else
            assignmentlist->print(indent);
    }
    if (wordlist) {
        std::cout << std::string(indent, '\t') << "exec ";
        wordlist->print();
        std::cout << '\n';
    }
}