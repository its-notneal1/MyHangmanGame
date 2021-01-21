//
//  Game.cpp
//  HangmanProj
//
//  Created by Neal Archival on 1/20/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cctype>
#include <stdio.h>



#include "GameLibrary.h"

Words::Words() {
    wordList = { "APPLE", "WINDOWS", "LINUX", "PYTHON", "JAVA" };
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Words::viewAllWords() {
    std::cout << "Words: " << std::endl;
    for (auto x : wordList) {
        std::cout << x << std::endl;
    }
}

void Words::addNewWord() {
    std::cout << "Enter Custom Word: ";
    std::string newWord;
    std::cin >> newWord;
    for (std::string::size_type i = 0; i < newWord.length(); i++) newWord[i] = std::toupper(newWord[i]);
    wordList.push_back(newWord);
}

void Words::removeWord() {
    std::string wordInput;
    std::cout << "Enter word to be removed" << std::endl;
    std::cin >> wordInput;
    for (std::string::size_type i = 0; i < wordInput.size(); i++) wordInput[i] = std::toupper(wordInput[i]);
    std::cout << wordInput << std::endl;
    for (int i = 0; i < wordList.size(); i++) {
        if (wordList[i] == wordInput) wordList.erase(wordList.begin() + i);
    }
}

void viewEditMenu(Words& wordsClass) {
    char menuResponse;
    while (1) {
        std::cout << "[A.] Add Word To List " << std::endl;
        std::cout << "[B.] Remove Word From List" << std::endl;
        std::cout << "[C.] Return To Main Menu " << std::endl;
        std::cin >> menuResponse;
        std::cin.ignore(250, '\n');

        switch (menuResponse) {
        case('A'):
        case('a'):
            wordsClass.addNewWord();
            break;
        case('B'):
        case('b'):
            wordsClass.removeWord();
            break;
        case('C'):
        case('c'):
            return;
        default:
            std::cout << "Woah That Does Not Exist! Try Again!" << std::endl;
            std::cin.clear();
            break;
        }
    }
}


std::string Words::selectWord() {
    std::string oneWord = wordList[rand() % wordList.size() - 1 + 1]; // -1 from the size to access proper index
    return oneWord;
}

void gameDisplay(const int tries, const std::string alphabet, const std::string textBar) {
    std::string line1 = "_______________________\n";
    std::string line2 = "|          |          |\n";
    std::string line3 = "|                     |\n";
    std::string line4 = "|                     |\n";
    std::string line5 = "|                     |\n";
    std::string line6 = "|                     |\n";

    switch (tries) {
    case(7):
        line6[12] = '\\';
    case(6):
        line6[10] = '/';
    case(5):
        line5[11] = '|';
    case(4):
        line4[12] = '\\';
    case(3):
        line4[10] = '/';
    case(2):
        line4[11] = '|';
    case(1):
        line3[11] = '0';
    }
    std::cout << line1 << line2 << line3 << line4 << line5 << line6 << line1 << alphabet << std::endl << textBar << std::endl;
    std::cout << tries << " Tries: / 7" << std::endl;
}
void hangmanGame(const std::string luckyWord) {
    std::vector<char> usedChars = { '~' };
    char userGuess;
    bool isValidInput, instanceFound;
    int tries = 0;
    int correctGuesses = 0;

    std::string textBar;
    std::string alphabet = "A, B, C, D, E, F, G, H, I, J, K, L\nM, N, O, P, Q, R, S, T, U, V, W, X, Y, Z";


    for (int i = 0; i < luckyWord.size(); i++) {
        textBar += "_ ";
    }
    while (tries < 7 && correctGuesses < luckyWord.length()) {
        gameDisplay(tries, alphabet, textBar);
        do {
            std::cout << tries << std::endl;
            isValidInput = false;
            instanceFound = false;
            std::cout << "Make Your Guess!: ";
            std::cin >> userGuess;
            std::cin.ignore(250, '\n');
            userGuess = std::toupper(userGuess);
            for (auto x : usedChars) {
                if (x == userGuess) {
                    std::cout << "You've Already Entered This! Try Again!" << std::endl;
                }
                else {
                    isValidInput = true;
                    usedChars.push_back(userGuess);
                }
            }
        } while (isValidInput == false);
        for (std::string::size_type i = 0; i < alphabet.length(); i++) {
            if (userGuess == alphabet[i]) {
                alphabet[i] = ' ';
                if (alphabet[i + 1] == ',') {
                    alphabet[i + 1] = ' ';
                }
            }
        }
        for (std::string::size_type i = 0; i < luckyWord.length(); i++) {
            if (luckyWord[i] == userGuess) {
                std::cout << "Great Guess! " << std::endl;
                textBar[i * 2] = userGuess;
                instanceFound = true;
                correctGuesses++;
            }
        }
        // end of letters update
        if (instanceFound == false) {
            tries++;
            std::cout << "That Guess Is Incorrect" << std::endl;
        }
        clearScreen();
        std::cin.clear();
    } // end of main while loop

    clearScreen();
    if (correctGuesses > tries) {
        std::cout << "You Won!" << std::endl;
    }
    else {
        std::cout << "Oh No You've Used All Your Tries! Try Again" << std::endl;
        std::cout << "The Lucky Word Was: " << luckyWord << std::endl;
    }
}
