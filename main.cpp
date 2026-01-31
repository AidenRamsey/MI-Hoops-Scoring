//includes and such here 
#include <tuple> 
#include <iostream> 
#include "print.h"
#include "util.h"
#include "player.h"
#include <sstream> 




int main() {
    //GLOBAL VARIABLES

    std::pair<std::string, int> homeScore; 
    std::pair<std::string, int> awayScore; 

    // player, score, reboud, assist, fouls? 
    std::vector<player> homeStats; 
    std::vector<player> awayStats; 

    //
    //FOR FG PERCENTS. 3 is for 3s and 2 is for 2s, obviously. 
    //inner std::pair is made / attempted. First is home, second is away. 
    std::pair<std::pair<int, int>, std::pair<int, int>> twos; 
    std::pair<std::pair<int, int>, std::pair<int, int>> threes; 
    

    //
    std::string homeTeam; 
    std::string awayTeam; 
    instructions(); 
    std::cout << "----------------------------" << std::endl; 
    std::cout << "HOME" << std::endl; 
    std::cin >> homeTeam; 
    std::cout << "AWAY" << std::endl; 
    std::cin >> awayTeam; 
    homeScore.first = homeTeam; 
    awayScore.first = awayTeam; 

    std::cout << "start inputing home player initials. " << std::endl; 
    std::string players;
    std::cin >> players; 
    while (players != "END") {

        
        player init = {players, 0, 0, 0, 0}; 
        homeStats.push_back(init); 
        std::cin >> players; 
    }

    std::cout << "starting inputing away players (optional- type SKIP to skip. )" << std::endl; 
    std::string input; 
    std::cin >> input; 
    while (input != "END") {
        if (input == "SKIP") {
            break; 
        }
        player init = {input, 0, 0, 0, 0}; 
        awayStats.push_back(init); 
        std::cin >> input; 
    }
    std::cout << "---------------------" << std::endl; 
    //ok so by this point, every player should be initialized and the team scores should be init. this will be to 
    


    
    std::cout << "START NORMAL LOOP " << std::endl; 
    std::cout << "---------------------" << std::endl; 
    std::cout << "Input SCORE, END, NEWPLAYER, STATS, UPDATE, MISSED for those commands or ATTEMPT" << std::endl; 
    std::cout << "to see this again, type COMMAND" << std::endl; 
    while (true) { 
        
        std::string input; 
        std::cin >> input; 
        if (input == "COMMAND") {
            std::cout << "Input SCORE, END, NEWPLAYER, STATS, UPDATE, MISSED for those commands or ATTEMPT" << std::endl; 
            std::cout << "to see this again, type COMMAND" << std::endl; 
            continue; 
        } else if (input == "SCORE") {
            printScore(homeScore, awayScore);
            continue; 
        } else if (input == "END") {
            toCSV(homeTeam, homeStats); 
            toCSV(awayTeam, awayStats); 
            break; 
        } else if (input == "NEWPLAYER") {
            std::cout << "HOME OR AWAY, space, INITIALS:" << std::endl;

            std::cin.ignore();                
            std::string line;
            std::getline(std::cin, line);     
        
            char team = line.at(0);
            std::string play = line.substr(2); 
        
            if (team == 'H') {
                homeStats.push_back({play, 0, 0, 0, 0});
            } else if (team == 'A') {
                awayStats.push_back({play, 0, 0, 0, 0});
            }
            std::cout << "-------SUCCESS---------" << std::endl;
            continue; 
        } else if (input == "STATS") {
            std::string whichTeam;
            std::string whichPlayer;  
            std::cout << "Home or Away" << std::endl; 
            std::cin >> whichTeam;
            std::cout << "Player initials" << std::endl; 
            std::cin >> whichPlayer; 

            if (whichTeam == "H") {
                int index = indexOfPlayer(homeStats, whichPlayer); 
                if (index == -1) {
                    std::cout << "Initials do not exist. Try again. -------------" << std::endl; 
                } else {
                    player stat = homeStats[index];
                    std::cout << " ----------------------------- " << std::endl; 
                    std::cout << "Player: " << stat.initials << std::endl; 
                    std::cout << "Points: " << stat.points << std::endl; 
                    std::cout << "Rebounds: " << stat.rebounds << std::endl; 
                    std::cout << "Assists: " << stat.assists << std::endl; 
                    std::cout << "Fouls: " << stat.fouls << std::endl; 
                    std::cout << " ----------------------------- " << std::endl; 
                }
               

            } else if (whichTeam == "A") {
                int index = indexOfPlayer(awayStats, whichPlayer); 
                if (index == -1) {
                    std::cout << "Initials do not exist. Try again. -------------" << std::endl; 
                    
                } else {
                    player stat = awayStats[index];
                std::cout << " ----------------------------- " << std::endl; 
                std::cout << "Player: " << stat.initials << std::endl; 
                std::cout << "Points:" << stat.points << std::endl; 
                std::cout << "Rebounds: " << stat.rebounds << std::endl; 
                std::cout << "Assists: " << stat.assists << std::endl; 
                std::cout << "Fouls: " << stat.fouls << std::endl; 
                std::cout << " ----------------------------- " << std::endl;
                }
                
            } 
            continue; 
        } else if (input == "ATTEMPT") {
            std::cin.ignore(); 
            std::string line;
            std::cout << "H/A TWOS/THREES" << std::endl;
            std::getline(std::cin, line);  
            
            if (line.length() < 3) {
                std::cout << "Invalid input" << std::endl;
                continue;
            }
            
            std::string team = line.substr(0, 1);
            std::string type = line.substr(2); 
        
            if (type == "TWOS") {
                if (team == "H") twoPercent("H", twos);
                else twoPercent("A", twos);
            } else if (type == "THREES") {
                if (team == "H") threePercent("H", threes);
                else threePercent("A", threes);
            } else {
                std::cout << "-----ERROR-----" << std::endl; 
            }
            continue; 
        } else if (input == "UPDATE") {
            //updating scores, players, assists, 
            //rebound = RE;  
            //Points = PO; 
            //Foul = FO; 
            //Assists: AS
            // input HOME/AWAY PLAYERINIT 
            std::cout << "H/A PI RE/PO/FO/AS __NUMBER_TO_INCREMENT_BY__" << std::endl;
            std::string team;
           std::string playerInit;
         std::string stat;
         int numberToIncrement;
         if (!(std::cin >> team >> playerInit >> stat >> numberToIncrement)) {
            std::cout << "-----ERROR: Invalid input format-----" << std::endl;
            std::cin.clear(); // Clear error flags
            std::cin.ignore(10000, '\n'); // Discard the rest of the line
            continue;
        }
            if (team == "H") {
                int index = indexOfPlayer(homeStats, playerInit);
                player& metrics = homeStats[index]; 
                
                if (stat == "PO") {
                    //increment personal stat, plus if it is a two that team's stats and attempted
                    metrics.points += numberToIncrement; 
                    //increment total points and attempts for that team; 
                    //this is home team 
                    if (numberToIncrement == 2) {
                         std::pair<int, int>& homeRef = twos.first; 
                         homeRef.first++;
                         homeRef.second++;
                        homeScore.second += 2; 
                    } else if (numberToIncrement == 3) {
                        std::pair<int, int>& homeRef = threes.first; 
                        homeRef.first++; 
                        homeRef.second++; 
                        homeScore.second += 3; 

                    }
                    std::cout << "-----SUCESS-----" << std::endl; 
                } else if (stat == "RE") {
                    //incremenet that player's rebund
                    metrics.rebounds += numberToIncrement; 
                    std::cout << "-----SUCCESS-----" << std::endl; 

                } else if (stat == "AS") {
                    //increment that player's assists
                    metrics.assists += numberToIncrement; 
                    std::cout << "-----SUCCESS-----" << std::endl; 

                } else if (stat == "FO") {
                    //increment that player's fouls
                    metrics.fouls += numberToIncrement; 
                    std::cout << "-----SUCCESS-----" << std::endl; 

                }

            } else {
                int index = indexOfPlayer(awayStats, playerInit);
                
                player& metrics = awayStats[index]; 
                
                if (stat == "PO") {
                    //increment personal stat, plus if it is a two that team's stats and attempted
                    metrics.points += numberToIncrement; 
                    //increment total points and attempts for that team; 
                    if (numberToIncrement == 2) {
                        std::pair<int, int>& awayRef = twos.second; 
                        awayRef.first++;
                        awayRef.second++;
                        awayScore.second += 2; 
                   } else if (numberToIncrement == 3) {
                       std::pair<int, int>& awayRef = threes.second; 
                       awayRef.first++; 
                       awayRef.second++; 
                       awayScore.second += 3; 
                   }
                   std::cout << "-----SUCCESS-----" << std::endl; 

                } else if (stat == "RE") {
                    //incremenet that player's rebound
                    metrics.rebounds += numberToIncrement; 
                    std::cout << "-----SUCCESS-----" << std::endl; 

                } else if (stat == "AS") {
                    //increment that player's assists
                    metrics.assists += numberToIncrement; 
                    std::cout << "-----SUCCESS-----" << std::endl; 

                } else if (stat == "FO") {
                    //increment that player's fouls
                    metrics.fouls += numberToIncrement; 
                    std::cout << "-----SUCCESS-----" << std::endl; 

                }
            }
            continue; 
        } else if (input == "MISSED") {
            std::cout << "What team? " << std::endl; 
            std::string team; 
            std::cin >> team; 
            std::string score; 
            std::cout << "What type? (TWO or THREE)" << std::endl; 
            std::cin >> score; 
            if (team == "H") {
                if (score == "TWO") {
                    std::pair<int, int>& homeRef = twos.first; 
                    homeRef.second++;

                } else {
                    std::pair<int, int>& homeRef = threes.first; 
                    homeRef.second++;

                }
            } else {
                if (score == "THREE") {
                    std::pair<int, int>& awayRef = twos.second; 
                    awayRef.second++;

                } else {
                    std::pair<int, int>& awayRef = threes.second; 
                    awayRef.second++; 

                }
            }
        }
    }
    return 0; 
}