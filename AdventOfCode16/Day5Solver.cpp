#include <iostream>
#include <sstream>
#include <vector>

#include "Day5Solver.h"

namespace day5 {
	void Day5Solver::Solve() {
		std::cout << "Starting to solve Day5...\n";

		// Could std::vector<char[2]> save memory here?
		forbiddenCombinations = std::vector<std::string>{ "ab","cd","pq","xy" };

		int amountOfNiceStrings{ 0 };
		std::istringstream inputStream(input);
		std::string currentString{};
		while (std::getline(inputStream, currentString)) {
			if (StringIsNice(currentString)) {
				++amountOfNiceStrings;
			}
		}

		std::cout << "Day5 Part1 result: " << amountOfNiceStrings << "\n";
		std::cout << "Day5 solved.\n";
	}

	// Thoughts:
	// Could save cpu power by not checking for vowels after 3 have been found and 
	// not checking for letters twice in a row once they have been found.
	// On the other hand that would produce more code and make it more difficult to understand.
	bool Day5Solver::StringIsNice(std::string& theString) {
		int amountOfVowels{ 0 };
		bool hasLetterTwiceInARow{ false };

		char lastChar{};
		char currentChar{};
		for (std::string::size_type i = 0; i < theString.size(); i++) {
			currentChar = theString[i];

			if (CharIsVowel(currentChar)) {
				++amountOfVowels;
			}

			// Continue here on first iteration. Following evaluations need two characters.
			if (i == 0) {
				lastChar = currentChar;
				continue;
			}

			if (IsForbiddenCombination(lastChar, currentChar)) {
				// Return on forbidden combination, no need to do any further evaluation:
				return false;
			}

			if (lastChar == currentChar) {
				hasLetterTwiceInARow = true;
			}

			lastChar = currentChar;
		}

		return amountOfVowels >= 3 && hasLetterTwiceInARow;
	}

	bool Day5Solver::CharIsVowel(char& theChar) {
		return theChar == 'a'
			|| theChar == 'e'
			|| theChar == 'i'
			|| theChar == 'o'
			|| theChar == 'u';
	}

	bool Day5Solver::IsForbiddenCombination(char& char1, char& char2) {
		for (size_t i = 0; i < forbiddenCombinations.size(); i++) {
			if (forbiddenCombinations[i][0] == char1
				&& forbiddenCombinations[i][1] == char2) {				
				return true;
			}
		}
		return false;
	}
}