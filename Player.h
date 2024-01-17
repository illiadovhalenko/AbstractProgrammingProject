
#ifndef PROJECT_PA_PLAYER_H
#define PROJECT_PA_PLAYER_H
#include "Human.h"

class Player: public Human{
public:
    void action() override;
};

#endif //PROJECT_PA_PLAYER_H