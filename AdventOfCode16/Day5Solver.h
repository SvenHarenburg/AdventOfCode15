#pragma once
#include "SolverBase.h"

namespace day5 {

	class Day5Solver :
		public base::SolverBase
	{
	private:
		std::vector<std::string> forbiddenCombinations;

	public:
		Day5Solver() : SolverBase("Day5", true) {};
		void Solve() override;

		// Pass theString by reference to save memory
		bool StringIsNice(std::string& theString);
		bool CharIsVowel(char& theChar);
		bool IsForbiddenCombination(char& char1, char& char2);
	};
}

