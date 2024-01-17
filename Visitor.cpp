#include "Visitor.h"

Visitor::Visitor(){
    name = randomLineFromFile(namesFile);
    surname = randomLineFromFile(surnamesFile);
    age = 10 + rand() % 70;
}

void Visitor::action() {
    std::cout<<"Hurra!!!"<<std::endl;
}
Visitor::~Visitor() = default;