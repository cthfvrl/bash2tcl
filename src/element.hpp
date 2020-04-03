#pragma once
#include <string>

class Element {
protected:
    Element();

public:
    void print();
};

typedef struct {
    std::string string;
    Element* element;
} DATA;
#define YYSTYPE DATA