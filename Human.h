#pragma once
#ifndef PROJECT_PA_HUMAN_H
#define PROJECT_PA_HUMAN_H
#include <iostream>
#include<fstream>
#include <random>
#include "Globals.h"



class Human{
public:
    virtual void action();
    std::string name;
    std::string surname;
    int age;
    friend std::ostream& operator<<(std::ostream& os, Human& player);
};

std::string randomLineFromFile(std::string fileName);

#endif //PROJECT_PA_HUMAN_H
