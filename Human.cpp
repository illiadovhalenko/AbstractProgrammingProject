//
// Created by Mac on 09/01/2024.
//

#include "Human.h"



std::string randomLineFromFile(std::string fileName) {
    std::string line;
    std::ifstream File(fileName);
    std::random_device rd;
    srand(time(0));
    int linesInFile;
    if(fileName=="names.txt"){
        linesInFile=linesInNames;
    } else{
        linesInFile=linesInSurnames;
    }
    std::uniform_int_distribution<int> distribution(0, linesInFile);
    int randomLine = distribution(rd);
    int numOfLines=0;
    while(std::getline(File, line)){
        numOfLines++;
        if(numOfLines==randomLine)
            break;
    }
    return line;
}

void Human::action() {}
std::ostream& operator<<(std::ostream &os, Human& human){
    os<< human.name<<" "<<human.surname<<" "<<human.age;
    return os;
}