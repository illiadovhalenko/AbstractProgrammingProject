//
// Created by Mac on 11/01/2024.
//

#include "Referee.h"


Referee::Referee() {
    surname = randomLineFromFile(surnamesFile);
    name = randomLineFromFile(namesFile);
    age = 25 + rand() % 30;
}

void Referee::action() {
    std::cout<<"Running to see VAR"<<std::endl;
}
Referee::~Referee() = default;