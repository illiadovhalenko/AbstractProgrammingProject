//
// Created by Mac on 10/01/2024.
//

#ifndef PROJECT_PA_FIELDPLAYERS_H
#define PROJECT_PA_FIELDPLAYERS_H
#include "Player.h"

class FieldPlayers: public Player{
public:
    int chanceToScoreGoal;
    explicit FieldPlayers(int chanceToScore);
    virtual ~FieldPlayers();
};


#endif //PROJECT_PA_FIELDPLAYERS_H
