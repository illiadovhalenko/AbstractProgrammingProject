//
// Created by Mac on 11/01/2024.
//

//#ifndef PROJECT_PA_GLOBALS_H
//#define PROJECT_PA_GLOBALS_H

#pragma once
#include <string>
#ifdef __MAIN__
    #define __EXTERN(type, name, value)     type name = value
#else
    #define __EXTERN(type, name, value)     extern type name;
#endif

__EXTERN(std::string, surnamesFile, "surnames.txt");
//std::string namesFile = "names.txt";
//std::map<std::string, int> mapWithLines{{"names.txt", 2943}, {"surnames.txt", 1000}};
__EXTERN(std::string, namesFile, "names.txt");
__EXTERN(int, linesInNames, 2943);
__EXTERN(int, linesInSurnames, 1000);


//#endif //PROJECT_PA_GLOBALS_H
