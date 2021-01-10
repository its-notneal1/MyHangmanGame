#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdlib.h>


#include "Library.h"

void printLine() {
	std::cout << std::setfill('=') << std::right << std::setw(50) << "=" << std::setfill(' ') << std::endl;
}

Words::Words() { // Words class constructor 
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



void gameDisplay(int& tries) {
	system("cls");
	switch (tries) {
	case(0):
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "|                   ______           |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                                    |" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 / 7 tries" << std::endl;
		break;
	case(1):
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "|                   ______           |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  O       |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                                    |" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << tries << " / 7 tries " << std::endl;
		break;
	case(2):
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "|                   ______           |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  O       |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                                    |" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << tries << " / 7 tries " << std::endl;
		break;
	case(3):
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "|                   ______           |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  O       |         |" << std::endl;
		std::cout << "|                 /|       |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                                    |" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << tries << " / 7 tries " << std::endl;
		break;
	case(4):
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "|                   ______           |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  O       |         |" << std::endl;
		std::cout << "|                 /|\\      |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                                    |" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << tries << " / 7 tries " << std::endl;
		break;
	case(5):
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "|                   ______           |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  O       |         |" << std::endl;
		std::cout << "|                 /|\\      |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                                    |" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << tries << " / 7 tries " << std::endl;
		break;
	case(6):
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "|                   ______           |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  O       |         |" << std::endl;
		std::cout << "|                 /|\\      |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                 / \\      |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                                    |" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << tries << " / 7 tries " << std::endl;
		break;
	case(7):
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "|                   ______           |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                  O       |         |" << std::endl;
		std::cout << "|                 /|\\      |         |" << std::endl;
		std::cout << "|                  |       |         |" << std::endl;
		std::cout << "|                 / \\      |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                          |         |" << std::endl;
		std::cout << "|                                    |" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << tries << " / 7 tries " << std::endl;
		std::cout << "Game Over" << std::endl;
		break;
	}
	return;
}

void beginGame(std::string correctWord) {
	char userInput;
	std::vector<char> previousInput_misses, previousInput;
	int misses = 0;
	int correctGuess = 0;
	int wordSize = correctWord.length();
	std::string textBar;
	int instanceFound = 0; // used as a guide
	
	gameDisplay(misses); // pass to get the first display

	for (std::string::size_type i = 0; i < correctWord.length(); i++) {
		textBar += "_ ";
	}

	std::cout << textBar << std::endl; // the text bar display for found letters

	do {
		TOP: // jump statement if the user enters a repeated input
		instanceFound = 0; // used as a guide to check if a string contains the entered character
		std::cout << "Enter a letter: ";
		std::cin >> userInput;
		std::cin.ignore(100, '\n'); // ignore additional characters
		for (auto k : previousInput) {
			if (k == userInput) { // chec if the user has already entered
				std::cout << "You Have Already Entered The Letter: " << k << std::endl;
				goto TOP;
			}
		}
		previousInput.push_back(userInput);
		for (std::string::size_type i = 0; i < correctWord.length(); i++) {	
			if (userInput == correctWord[i]) {
				correctGuess++;
				instanceFound++; // resets to zero
				textBar[i * 2] = userInput; // print to the corresponding underscore
			}
		}
		if (instanceFound == 0) {
			misses++; 
			previousInput_misses.push_back(userInput);
			gameDisplay(misses);
		}
		else {
			gameDisplay(misses); // reprint the right visual
			printLine();
			std::cout << "You Guessed Right! " << std::endl;
			printLine();
		}
		std::cout << "Misses: ";
		for (auto x : previousInput_misses) {
			std::cout << x << ", ";
		}

		std::cout << std::endl << "The Word: " << textBar << std::endl;

	} while (correctGuess < wordSize && misses < 7); // end of while loop for game

	if (correctGuess > misses) {
		printLine();
		std::cout << "You Win!" << std::endl;
		std::cout << "The Lucky Word Was: " << correctWord << std::endl;
		printLine();
	}
	else {
		printLine();
		std::cout << "Game Over" << std::endl;
		std::cout << "The Lucky Word Was: " << correctWord << std::endl;
		printLine();
	}
	return;
}
