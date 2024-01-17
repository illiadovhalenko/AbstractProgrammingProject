#include "Goalkeeper.h"


Goalkeeper::Goalkeeper() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist1(18, 38);
    age = dist1(rd);
    surname= randomLineFromFile(surnamesFile);
    name = randomLineFromFile(namesFile);
    std::uniform_int_distribution<int> dist2(70, 95);
    chanceToCatchBall=dist2(rd);
}
Goalkeeper::~Goalkeeper()= default;