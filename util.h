#ifndef UTIL_H
#define UTIL_H
#include <vector> 
#include <utility> 
#include "player.h"
#include <iostream>




int indexOfPlayer(std::vector<player> stats, std::string init); 
void twoPercent(std::string team, std::pair<std::pair<int, int>, std::pair<int, int>> twos); 
void threePercent(std::string team, std::pair<std::pair<int, int>, std::pair<int, int>> threes); 





#endif 