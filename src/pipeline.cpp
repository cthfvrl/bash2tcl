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
    if (output_file.empty())
        std::cout << " >@stdout 2>@stderr <@stdin ";
    else
        std::cout << " >>" << output_file << " 2>@stderr <@stdin ";
    if (redirectionlist)
        redirectionlist->print();
}

void Pipeline::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "set " << get_rc_str() << " [catch {exec ";
    for (size_t i = 0; i < elements.size() - 1; ++i) {
        elements[i]->print();
        std::cout << "| ";
    }
    elements.back()->print();
    std::cout << "}]";
}