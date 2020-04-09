#include "command.hpp"
#include <iostream>

Command::Command(WordList* wordlist)
    : assignmentlist(nullptr), wordlist(wordlist), redirectionlist(nullptr) {
}

Command::Command(AssignmentList* assignmentlist)
    : assignmentlist(assignmentlist), wordlist(nullptr), redirectionlist(nullptr) {
}

Command::Command(AssignmentList* assignmentlist, WordList* wordlist)
    : assignmentlist(assignmentlist), wordlist(wordlist), redirectionlist(nullptr) {
}

Command::Command(WordList* wordlist, RedirectionList* redirectionlist)
    : assignmentlist(nullptr), wordlist(wordlist), redirectionlist(redirectionlist) {
}

Command::Command(AssignmentList* assignmentlist, WordList* wordlist, RedirectionList* redirectionlist)
    : assignmentlist(assignmentlist), wordlist(wordlist), redirectionlist(redirectionlist) {
}

void Command::print(size_t indent) {
    std::cout << std::string(indent, '\t');
    if (assignmentlist) {
        if (wordlist)
            assignmentlist->print_env();
        else
            assignmentlist->print();
    }
    if (wordlist) {
        std::cout << "exec ";
        wordlist->print();
        if (redirectionlist)
            redirectionlist->print();
        if (output)
            std::cout << " >@stdout ";
    }
    std::cout << '\n';
}