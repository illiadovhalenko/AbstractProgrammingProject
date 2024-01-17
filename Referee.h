//
// Created by Mac on 11/01/2024.
//

#ifndef PROJECT_PA_REFEREE_H
#define PROJECT_PA_REFEREE_H
#include "Human.h"

class Referee : public Human{
public:
    void action() override;
    Referee();
    ~Referee();
};


#endif //PROJECT_PA_REFEREE_H
