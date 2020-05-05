#pragma once
#include "element.hpp"
#include <string>

class Condition : virtual public Element {
    int rc;
    static int rc_max;
    static const std::string prefix;

protected:
    Condition();
    Condition(int);
    void set_rc(int);
    void reset_rc(size_t indent = 0);

public:
    int get_rc();
    std::string get_rc_str();
    static std::string get_rc_str(int);
    static void reset_all_rc();
};