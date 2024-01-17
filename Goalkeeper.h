//
// Created by Mac on 10/01/2024.
//

#ifndef PROJECT_PA_GOALKEEPER_H
#define PROJECT_PA_GOALKEEPER_H
#include"Player.h"

class Goalkeeper: public Player{
public:
    int chanceToCatchBall;
    Goalkeeper();
    ~Goalkeeper();
};

#endif //PROJECT_PA_GOALKEEPER_H
