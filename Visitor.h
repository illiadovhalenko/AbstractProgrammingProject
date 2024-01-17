//
// Created by Mac on 11/01/2024.
//
#ifndef PROJECT_PA_VISITOR_H
#define PROJECT_PA_VISITOR_H
#include "Human.h"

class Visitor : public Human{
public:
    void action() override;
    Visitor();
    virtual ~Visitor();
};

#endif //PROJECT_PA_VISITOR_H
