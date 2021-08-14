#pragma once
#include <vector>

namespace day2 {
	struct Box {
		int length{ 0 };
		int width{ 0 };
		int height{ 0 };
	};

	class Day2Solver {
	private:
		std::vector<Box> ReadInputFromFile(std::string filePath);
		int getRequiredWrappingPaper(Box box);
		int getRequiredRibbon(Box box);

	public:
		void Solve();
	};
}