#include "command.hpp"
#include <iostream>

Command::Command(WordList* wordlist) : wordlist(wordlist) {
}

void Command::print(size_t indent) {
    wordlist->print(indent);
}