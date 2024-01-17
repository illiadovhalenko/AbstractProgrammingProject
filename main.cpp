#include <iostream>
#define __MAIN__
#include "Game.h"

int main() {
    std::string name1 = "Barca";
    std::string name2 = "Real";
    Team<11> team1(name1);
    Team<11> team2(name2);
    Game<11> game(team1, team2);
    game.startMatch();
    return 0;
}
