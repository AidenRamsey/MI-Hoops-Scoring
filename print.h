#ifndef PRINT_H
#define PRINT_H
#include <utility> 
#include "player.h"
#include <fstream> 
void instructions(); 


void printScore(std::pair<std::string, int> home, std::pair<std::string, int> away); 

void toCSV(std::string team, std::vector<player> homeStats); 



#endif 