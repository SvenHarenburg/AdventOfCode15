#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Day2Solver.h"

namespace day2 {
	const std::string inputFileName{ "Day2Input.txt" };

	void Day2Solver::Solve() {
		std::cout << "Starting to solve Day2\n";
		std::vector<Box> boxes{ ReadInputFromFile(inputFileName) };

		int totalWrappingPaperNeeded{ 0 };
		for (size_t i = 0; i < boxes.size(); i++)
		{
			totalWrappingPaperNeeded += getRequiredWrappingPaper(boxes[i]);
		}

		std::cout << "Total wrapping paper needed: " << totalWrappingPaperNeeded << "\n";
		std::cout << "Day2 solved.\n";
	}

	int Day2Solver::getRequiredWrappingPaper(Box box) {
		int side1 = box.length * box.width;
		int side2 = box.width * box.height;
		int side3 = box.height * box.length;
		int smallestSide = std::min({ side1, side2, side3 });

		return (side1 * 2) + (side2 * 2) + (side3 * 2) + smallestSide;
	}

	std::vector<Box> Day2Solver::ReadInputFromFile(std::string filePath) {
		std::cout << "Reading input file...";		
		std::ifstream file(inputFileName);
		std::string line;
		std::vector<Box> boxes{};
		while (std::getline(file, line)) {
			Box box;

			int pos = line.find("x");
			box.length = std::stoi(line.substr(0, pos));
			line = line.substr(pos + 1, line.length() - pos);

			pos = line.find("x");
			box.width = std::stoi(line.substr(0, pos));
			line = line.substr(pos + 1, line.length() - pos);

			// no x left, remaining characters are the height
			box.height = std::stoi(line);
			boxes.push_back(box);
		}

		return boxes;
	}
}