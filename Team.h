//
// Created by Mac on 10/01/2024.
//

#ifndef PROJECT_PA_TEAM_H
#define PROJECT_PA_TEAM_H
#include "Goalkeeper.h"
#include "FieldPlayers.h"
#include <vector>
#include <utility>
#include <algorithm>
//TODO requeirs liczby graczy
template<int N>
concept BiggerThan1Less11 = 12 > N and N > 1;

int chanceToScore(int n);
template<int N> requires BiggerThan1Less11<N>
class Team;

template<int N> requires BiggerThan1Less11<N>
class Team{
public:
    std::string teamName;
    std::vector<FieldPlayers> players;
    Goalkeeper goalkeeper;
    int numberOfPlayers;
    std::vector<bool> yellowCards;
public:
    explicit Team(std::string name){
        teamName = std::move(name);
        numberOfPlayers = N;
        goalkeeper = Goalkeeper();
        for(int i=0; i<N-1; i++){
            players.emplace_back(chanceToScore(i));
            yellowCards.emplace_back(false);
        }
    }
    void deletePlayer(int numberOfPlayer);
    void printPlayers();
};
template<int N>
requires BiggerThan1Less11<N>
        void Team<N>::deletePlayer(int numberOfPlayer) {
            yellowCards.erase(yellowCards.cbegin()+numberOfPlayer);
            players.erase(players.cbegin()+numberOfPlayer);
            numberOfPlayers--;

        }

template<int N>
requires BiggerThan1Less11<N>void Team<N>::printPlayers() {
    std::cout<<"Team Name: "<< this->teamName<<std::endl;
    std::cout<<"Goalkeeper:\t"<<this->goalkeeper<<std::endl;
    std::cout<<"Field Players:  "<<players[0]<<std::endl;
    for(int i=1; i<numberOfPlayers-1; i++)
        std::cout<<"\t\t"<<players[i]<<std::endl;
}


#endif //PROJECT_PA_TEAM_H
