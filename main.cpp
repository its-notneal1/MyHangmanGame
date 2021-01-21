#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "GameLibrary.h"

int main() {
    Words wordsClass;
    char response;
    
    while(1) {
        std::cout << "------------------------------" << std::endl;
        std::cout << "|     Neal's Hangman Game    |" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "| [A.] Play Game             |" << std::endl;
        std::cout << "| [B.] View / Edit Word List |" << std::endl;
        std::cout << "| [C.] Exit Application      |" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "Selection Options A to C: ";
        std::cin >> response;
        
        switch(response) {
            case('A'):
            case('a'):
                hangmanGame(wordsClass.selectWord());
                break;
            case('B'):
            case('b'):
                wordsClass.viewAllWords();
                clearScreen();
                viewEditMenu(wordsClass);
                break;
            case('C'):
            case('c'):
                std::cout << "See You Later!" << std::endl;
                return 1;
                break;
            default:
                std::cin.clear();
                clearScreen();
                std::cout << "That Option Does Not Exist. Try again!" << std::endl;
                break;
        }
        
    }
    
}
