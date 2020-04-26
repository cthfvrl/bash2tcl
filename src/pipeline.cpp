#include "pipeline.hpp"
#include <iostream>
#include <string>

PipelineCommand::PipelineCommand(WordList* wordlist)
    : wordlist(wordlist), redirectionlist(nullptr) {
}

PipelineCommand::PipelineCommand(WordList* wordlist, RedirectionList* redirectionlist)
    : wordlist(wordlist), redirectionlist(redirectionlist) {
}

void PipelineCommand::print(size_t indent) {
    wordlist->print();
    if (output)
        std::cout << " >&@stdout <@stdin ";
    if (redirectionlist)
        redirectionlist->print();
}

void Pipeline::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "catch {exec ";
    for (size_t i = 0; i < elements.size() - 1; ++i) {
        elements[i]->print();
        std::cout << "| ";
    }
    elements.back()->print();
    std::cout << '}';
}

void Pipeline::print_condition(size_t indent) {
    std::cout << std::string(indent, '\t') << "![catch {exec ";
    for (size_t i = 0; i < elements.size() - 1; ++i) {
        elements[i]->print();
        std::cout << "| ";
    }
    elements.back()->print();
    std::cout << "}]";
}
