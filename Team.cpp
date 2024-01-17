//
// Created by Mac on 10/01/2024.
//

#include "Team.h"


int chanceToScore(int n){
    std::random_device rd;
    std::uniform_int_distribution<int> dist1((4-n%3)*20, (4-n%3)*20+10);
    return dist1(rd);
}

