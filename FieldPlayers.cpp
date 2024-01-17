//
// Created by Mac on 10/01/2024.
//

#include "FieldPlayers.h"

FieldPlayers::FieldPlayers(int chanceToScore) {
    surname = randomLineFromFile(surnamesFile);
    name = randomLineFromFile(namesFile);
    std::random_device rd;
    std::uniform_int_distribution<int> dist(18, 38);
    age = dist(rd);
    chanceToScoreGoal = chanceToScore;
}
FieldPlayers::~FieldPlayers() = default;