#include "print.h"
#include <iostream> 
void instructions() {
    std::cout << "CREDITS: AIDEN RAMSEY. 1-5! " << std::endl; 
    std::cout << "This is the basketball stats/ score tracker for MI bb. I am making this cause "; 
    std::cout << "I don't have anything better to do. This should be fun though. :)> " << std::endl;
    
    std::cout <<"----------" << std::endl; 


    std::cout << "Instructions: " << std::endl; 
    std::cout << "1) Start by defining the HOME (H) and AWAY (A) teams. " << std::endl; 
    std::cout << "Input home team section and away team section when prompted ";
    std::cout << "to input the Home section and the away section. This is somewhat arbitrary, but both teams need to be in the system regardless." << std::endl; 
    std::cout << "2) input player initials. Start by entering in Home team players by the command (FirstInitialLastInitial) " << std::endl; 
    std::cout << "END to end input of home team. Input SKIP to skip insertion of away team members, or insert away team members and end with END" << std::endl; 
    std::cout << "COMMANDS:" << std::endl; 
    std::cout << "COMMAND : Refresh Command list" << std::endl; 
    std::cout << "SCORE : Displays score and team with that score. Not H/A, but their actual names. " << std::endl;
    std::cout << "STATS : Displays Points/Rebounds/Assists/Fouls of a player. Follow prompts when selected." << std::endl; 
    std::cout << "UPDATE : Update's a players Points(PO)/Rebounds(RE)/Assists(AS)/Fouls(FO). Follow prompts when selected" << std::endl;
    std::cout << "MISSED : Increment the total attempts for Two/Three pointers for a team (H/A)" << std::endl; 
    std::cout << "ATTEMPT : Displays the total made shots, total attempted shots, and FG PERCENT for a type of point (TWO/THREES)" << std::endl; 
    std::cout << "-----QUESTIONS? DON'T CONTACT AIDEN RAMSEY. I AM PROBABLY BUSY-----" <<std::endl; 
}


void printScore(std::pair<std::string, int> homeScore, std::pair<std::string, int> awayScore) {
    std::string scoreH = std::to_string(homeScore.second); 
    std::string scoreA = std::to_string(awayScore.second); 
    std::cout << homeScore.first + ": " + scoreH + " | " + awayScore.first + ": " + scoreA << std::endl; 
}   

void toCSV(std::string team, std::vector<player> stats) {
    std::string filename = team + ".csv";
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cout << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    file << "Player,Points,Rebounds,Assists,Fouls\n";
    
    for (const player& p : stats) {
        file << p.initials << ","
             << p.points << ","
             << p.rebounds << ","
             << p.assists << ","
             << p.fouls << "\n";
    }
    
    file.close();
    
    std::cout << "Successfully exported " << team << " stats to " << filename << std::endl;
}