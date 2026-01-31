#include "util.h"

int indexOfPlayer(std::vector<player> stats, std::string init) {
    for (int i = 0; i < stats.size(); ++i) {
        if (stats[i].initials == init) {
            return i; 
        }
    }
    return -1; 
} 
void twoPercent(std::string team, std::pair<std::pair<int, int>, std::pair<int, int>> twos) {
    std::cout << "-----TWOS STATS "; 
    if (team == "H") {
        std::cout << " HOME-----" << std::endl; 
        std::pair<int, int> home = twos.first; 
        std::cout << "MADE: " << home.first << std::endl; 
        std::cout << "ATTEMPTED: " << home.second << std::endl; 
        if (home.second == 0) {
            std::cout << "PERCENT: NOT ATTEMPTED" << std::endl; 
        } else {
            double result = static_cast<double>(home.first) / home.second; 
            std::cout << "PERCENT: " << result << std::endl; 
        }
        std::cout << "----------" << std::endl; 
    } else {
        std::cout << " AWAY-----" << std::endl; 
        std::pair<int, int> away = twos.second; 
        std::cout << "MADE: " << away.first << std::endl; 
        std::cout << "ATTEMPTED: " << away.second << std::endl; 
        if (away.second == 0) {
            std::cout << "PERCENT: NOT ATTEMPTED" << std::endl; 
        } else {
            double result = static_cast<double>(away.first) / away.second; 
            std::cout << "PERCENT: " << result << std::endl; 
        }
        std::cout << "----------" << std::endl; 
    }
}
void threePercent(std::string team, std::pair<std::pair<int, int>, std::pair<int, int>> threes) {
    std::cout << "-----THREES STATS "; 
    if (team == "H") {
        std::cout << " HOME-----" << std::endl; 
        std::pair<int, int> home = threes.first; 
        std::cout << "MADE: " << home.first << std::endl; 
        std::cout << "ATTEMPTED: " << home.second << std::endl; 
        if (home.second == 0) {
            std::cout << "PERCENT: NOT ATTEMPTED" << std::endl; 
        } else {
            double result = static_cast<double>(home.first) / home.second; 
            std::cout << "PERCENT: " << result << std::endl; 
        }
        std::cout << "----------" << std::endl; 
    } else {
        std::cout << " AWAY-----" << std::endl; 
        std::pair<int, int> away = threes.second; 
        std::cout << "MADE: " << away.first << std::endl; 
        std::cout << "ATTEMPTED: " << away.second << std::endl; 
        if (away.second == 0) {
            std::cout << "PERCENT: NOT ATTEMPTED" << std::endl; 
        } else {
            double result = static_cast<double>(away.first) / away.second; 
            std::cout << "PERCENT: " << result << std::endl; 
        }
        std::cout << "----------" << std::endl; 
    }
}