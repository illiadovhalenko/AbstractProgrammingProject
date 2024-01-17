//
// Created by Mac on 11/01/2024.
//

#ifndef PROJECT_PA_GAME_H
#define PROJECT_PA_GAME_H
#include "Team.h"
#include "Visitor.h"
#include "Referee.h"
#include <unistd.h>
template<int N>
class Game {
    Visitor& getRandomVisitor();
    void getCard(Team<N>& team);
    void oneTime(int TimeMin, bool secondTime);
    void shot(bool whichTeam, int chanceToScore);
public:
    Referee referee;
    std::vector<Visitor> visitors;
    int numberOfVisitors;
    Team<N> team1;
    Team<N> team2;
    int score[2]= {0, 0};
    Game(Team<N> team1_, Team<N> team2_): team1(team1_), team2(team2_) {
        std::random_device rd;
        std::uniform_int_distribution<int> dist1(250, 350);
        numberOfVisitors = dist1(rd);
        for(int i=0; i<numberOfVisitors; i++){
            visitors.emplace_back();
        }
    }
    void startMatch();
};
template<int N>
void Game<N>::getCard(Team<N>& team) {
    if(team.numberOfPlayers==2){
        std::cout<<"Last player can't get card"<<std::endl;
        return;
    }
    std::random_device rd;
    std::uniform_int_distribution<int> whatPlayer(0, team.numberOfPlayers-2);
    std::uniform_int_distribution<int> whatCard(1, 5);
    if(whatCard(rd)==1){
        int temp = whatPlayer(rd);
        if(team.yellowCards[temp]){
            std::cout<<team.players[temp]<<" get a red card"<<std::endl;
            team.deletePlayer(temp);
        }else{
            std::cout<<team.players[temp]<<" get a yellow card"<<std::endl;
            team.yellowCards[temp]=true;
        }
    }
}
template<int N>
void Game<N>::shot(bool whichTeam, int chanceToScore) {
    std::random_device rd;
    std::uniform_int_distribution<int> whoShot(0, N - 2);
    std::uniform_int_distribution<int> shot(1, 100);
    std::uniform_int_distribution<int> goalkeeper(1, 100);
    if (whichTeam) {
        FieldPlayers shoter = team2.players[whoShot(rd)];
        std::cout << shoter << "(" << team2.teamName << ")" << " try to shot,";
        if (shoter.chanceToScoreGoal >= shot(rd)) {
            std::cout << " and boal flies into gate,";
            if (goalkeeper(rd) > team1.goalkeeper.chanceToCatchBall) {
                std::cout << " GOAAAALLL!!!";
                score[1]++;
            } else {
                std::cout << " goalkeeper save this boal";
            }
        } else {
            std::cout << " boal miss the gate";
        }
    } else {
        FieldPlayers shoter = team1.players[whoShot(rd)];
        std::cout << shoter << "(" << team1.teamName << ")" << " try to shot,";
        if (shoter.chanceToScoreGoal >= shot(rd)) {
            std::cout << " and boal flies into gate,";
            if (goalkeeper(rd) > team2.goalkeeper.chanceToCatchBall) {
                std::cout << " GOAAAALLL!!!";
                score[0]++;
            } else {
                std::cout << " goalkeeper save this boal";
            }
        } else {
            std::cout << " boal miss the gate";
        }
    }
    std::cout << std::endl;
}
template<int N>
Visitor& Game<N>::getRandomVisitor(){
    std::random_device rd;
    std::uniform_int_distribution<int> numberVisitor(0, numberOfVisitors-1);
    return visitors[numberVisitor(rd)];
}
template<int N>
void Game<N>::oneTime(int timeMin, bool secondTime) {
    std::random_device rd;
    std::uniform_int_distribution<int> whichTeamRandom(0, 1);
    std::uniform_int_distribution<int> chanceToScoreRandom(0, 4);
    std::uniform_int_distribution<int> extraTimeRandom(2, 7);
    std::uniform_int_distribution<int> chanceToGetCard(1, 10);
    bool whichTeam;
    int chanceToScore;
    int extraTime = extraTimeRandom(rd);
    for(int i = timeMin*secondTime+1; i <= secondTime*timeMin+timeMin + extraTime; i++){
        whichTeam=whichTeamRandom(rd);
        chanceToScore = chanceToScoreRandom(rd);
        if(chanceToScore == 1){
            std::cout<<i<<"' ";
            shot(whichTeam, chanceToScore);
        }else if(chanceToGetCard(rd)==1){
            std::cout<<i<<"' "<<referee<<" ";
            referee.action();
            if(whichTeamRandom(rd)){
                getCard(team1);
            }else{
                getCard(team2);
            }
        }else if(chanceToGetCard(rd)==2){
            Visitor vis = getRandomVisitor();
            std::cout<<i<<"' "<<vis<<" ";
            vis.action();
        }
        if(i==timeMin+timeMin*secondTime){
            std::cout<<"Extra Time "<<extraTime<<" min"<<std::endl;
        }
        usleep(30000);
    }
}
template<int N>
void Game<N>::startMatch(){
    int timeMin;
    int breakTime;
    if(N>6){
        timeMin = 45;
        breakTime = 15;
    }else{
        timeMin = 20;
        breakTime = 10;
    }
    std::cout<<"Referee: "<<referee<<std::endl;
    team1.printPlayers();
    team2.printPlayers();
    std::cout<<"Match Started"<<std::endl;
    oneTime(timeMin, false);
    std::cout<<"--------------"<<breakTime<<" minuts break"<<"----------------------"<<std::endl;
    oneTime(timeMin, true);
    std::cout<<"Match ended with score: "<<team1.teamName<<" "<<score[0]<<"-"<<score[1]<<" "<<team2.teamName<<std::endl;
    if(score[0]>score[1]){
        std::cout<<team1.teamName<<" WINS"<<std::endl;
    }else if(score[1]>score[0]){
        std::cout<<team2.teamName<<" WINS"<<std::endl;
    }else{
        std::cout<<"DRAW"<<std::endl;
    }
    std::cout<<team1.numberOfPlayers<<" "<<team2.numberOfPlayers<<std::endl;
}


#endif //PROJECT_PA_GAME_H
