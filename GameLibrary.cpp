#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdlib.h>


#include "Library.h"

void clearScreen() {
	for (int i = 0; i < 100; i++) {
		std::cout << "\n";
	}
}
void printLine() {
	std::cout << std::setfill('=') << std::right << std::setw(50) << "=" << std::setfill(' ') << std::endl;
}
Words::Words() {
	std::string oneWord;
	std::ifstream fileData;
	fileData.open("words.txt");
	while (!fileData.eof()) {
		getline(fileData, oneWord, ',');
		wordList.push_back(oneWord);
	}
}
void Words::pushNewWord(std::string newWord) {
	wordList.push_back(newWord);
	system("cls");
	printLine();
	std::cout << "New Word Added!" << std::endl;
	printLine();
	return;
}
std::string Words::chooseOneWord() {
	oneWord = wordList[rand() % wordList.size() - 1 + 1];
	return oneWord;
}
void hangmanGame(const std::string luckyWord) {
    int misses = 0;
    int correctTries = 0;
    std::vector<char> missedLetters, usedLetters;
    char response;
    bool isValid = false;
    bool instanceFound = false;
    std::string textBar;
    std::string alphabet = "A, B, C, D, E, F, G, H, I, J, K, L, M, N \nO, P, Q, R, S, T, U, V, W, X, Y, Z";

    // ** End of Function Variable Declarations ** //
    
    gameDisplay(misses); // call the function for initial display
    std::cout << alphabet;

    for (std::string::size_type i = 0; i < luckyWord.length(); i++) {
        textBar += "_ ";
    }

    while (correctTries < luckyWord.length() && misses < 7) {
        std::cout << alphabet << std::endl;
        std::cout << "Wrong Letters: ";
        
        while(isValid == false) {
            std::cout << "Make your lucky guess: ";
            std::cin >> response;
            std::cin.ignore(250, '\n'); // ignore additional characters
            toupper(response);
            isValid = true;
            for (auto x : usedLetters) {
                if (x == response) {
                    std::cout << "You Have Already Used The Letter" << "'" << x << "'" << std::endl;
                    std::cin.clear();
                    isValid = false;
                    break;
                }
            }
        } // end of is valid loop

        usedLetters.push_back(response);

        for (int i = 0; i < usedLetters.size(); i++) { // traverse the alphabet to remove letter
            for (std::string::size_type j = 0; j < alphabet.length(); j += 4) {
                if (alphabet[j] == usedLetters[i]) alphabet[j] = ' ';
            }
        }

        instanceFound = false; // set to false initially 
        for (std::string::size_type i = 0; i < luckyWord.length(); i++) {
            if (luckyWord[i] == response) {
                correctTries++;
                textBar[i * 2] = response;
                instanceFound = true; // trigger true to skip the following if statement
            }
        }

        if (instanceFound == false) {
            missedLetters.push_back(response);
            misses++;
        }
    }
}

void gameDisplay(const int& misses) {
    // hangman will be on index 6
    std::string line1 = "___________\n"; // 11 underscores
    std::string line2 = "     |    |\n";  // index 5
    std::string line3 = "          |\n"; 
    std::string line4 = "          |\n";
    std::string line5 = "          |\n";
    std::string line6 = "          |\n";
    std::string line9 = "0123456789^1"; // this is for reference
    // multiple 9 to access the letter
    std::cout << misses << " / 7";
    switch(misses) {
        case(0):
        break;
        case(1):
        line3[5] = '0';
        break;
        case(2):
        line4[5] = '|';
        break;
        case(3):
        line4[4] = '/';
        break;
        case(4):
        line4[6] = '\\';
        break;
        case(5):
        line5[5] = '|';
        break;
        case(6):
        line6[4] = '/';
        break;
        case(7):
        line6[6] = '\\';
        break;
        default:
        break;
    }
    std::cout << line1 << line2 << line3 << line4 << line5 << line6; // no need to add endl 
}