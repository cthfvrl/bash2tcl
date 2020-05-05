#include "condition.hpp"
#include <iostream>

int Condition::rc_max = 0;
const std::string Condition::prefix = "___rc";

Condition::Condition() : rc(rc_max++) {
}

Condition::Condition(int rc) : rc(rc) {
    if (rc >= rc_max)
        std::cerr << "Condition::Condition: suggested RC isn't less than "
                     "the RC maximum.\n";
}

int Condition::get_rc() {
    return rc;
}

void Condition::set_rc(int new_rc) {
    rc = new_rc;
}

void Condition::reset_rc(size_t indent, bool reverse) {
    std::cout << std::string(indent, '\t') << "set " << get_rc_str()
              << (reverse ? " 1\n" : " 0\n");
}

std::string Condition::get_rc_str() {
    return prefix + std::to_string(rc);
}

std::string Condition::get_rc_str(int r) {
    return prefix + std::to_string(r);
}

void Condition::reset_all_rc() {
    if (rc_max) {
        std::cout << "lassign [lrepeat " << std::to_string(rc_max) << " 0]";
        for (int i = 0; i < rc_max; ++i)
            std::cout << ' ' << prefix << std::to_string(i);
        std::cout << '\n';
    }
}