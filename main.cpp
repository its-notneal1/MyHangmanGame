#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>


#include "Library.h"



int main() {
	Words words;
	printLine();
	std::cout << std::right << std::setw(28) << "Hangman By: Neal" << std::endl;
	printLine();


	short int choice;
	std::string newWord;
	
	while (1) {
		std::cout << "[1.] Play Game" << std::endl;
		std::cout << "[2.] Add Words" << std::endl;
		std::cout << "[3.] Exit Application" << std::endl;
		std::cout << "Enter Option: ";
		ASKRESPONSE: std::cin >> choice;
		switch (choice) {
		case(1):
			system("cls");
			std::cout << "Starting Game" << std::endl;
			beginGame(words.chooseOneWord());
			break;
		case(2):
			std::cout << "Add Word Into List: ";
			std::cin >> newWord;
			words.pushNewWord(newWord);
			break;
		case(3):
			return 0;
		default:
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid Option. Enter Again: ";
			goto ASKRESPONSE;
		}
	}

	return 0;
}