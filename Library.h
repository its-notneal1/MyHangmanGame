#pragma once
#include <fstream>
#include <vector>
#include <string>


class Words {
public:
	Words();
	std::string chooseOneWord();
	void pushNewWord(std::string);
private:
	std::string oneWord;
	std::vector<std::string> wordList;
};

void gameDisplay(int&);
void printLine();

void beginGame(std::string);
