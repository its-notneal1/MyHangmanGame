//
//  GameLibrary.h
//  HangmanProj
//
//  Created by Neal Archival on 1/20/21.
//

#ifndef GameLibrary_h
#define GameLibrary_h

#include <string>
#include <vector>
#include <fstream>

class Words {
public:
    std::vector<std::string> wordList;
    
    Words();
    void viewAllWords();
    void addNewWord();
    void removeWord();
    std::string selectWord();
};

void viewEditMenu(Words&);

void clearScreen();
void gameDisplay(const int, const std::string, const std::string);


void hangmanGame(const std::string);


#endif /* GameLibrary_h */
