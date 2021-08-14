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

		int totalRequiredWrappingPaper{ 0 };
		int totalRequiredRibbon{ 0 };
		for (size_t i = 0; i < boxes.size(); i++)
		{
			totalRequiredWrappingPaper += getRequiredWrappingPaper(boxes[i]);
			totalRequiredRibbon += getRequiredRibbon(boxes[i]);
		}

		std::cout << "Total wrapping paper needed: " << totalRequiredWrappingPaper << "\n";
		std::cout << "Total ribbon needed: " << totalRequiredRibbon << "\n";
		std::cout << "Day2 solved.\n";
	}

	int Day2Solver::getRequiredWrappingPaper(Box box) {
		int side1 = box.length * box.width;
		int side2 = box.width * box.height;
		int side3 = box.height * box.length;

		// Smallest side for the required overhead of wrapping paper:
		int smallestSide = std::min({ side1, side2, side3 });

		return (side1 * 2) + (side2 * 2) + (side3 * 2) + smallestSide;
	}

	int Day2Solver::getRequiredRibbon(Box box) {
		/*
			The ribbon required to wrap a present is the shortest distance around its sides, 
			or the smallest perimeter of any one face. Each present also requires a bow made out of 
			ribbon as well; the feet of ribbon required for the perfect bow is equal to the cubic feet 
			of volume of the present. Don't ask how they tie the bow, though; they'll never tell.
		*/

		// Put length, height and width into an array and sort it in ascending order:
		int arr[] = { box.length, box.height, box.width };
		std::sort(std::begin(arr), std::end(arr));

		// The first two numbers are now the smallest, take those and calculate the ribbon:
		int requiredRibbon = (arr[0] * 2) + (arr[1] * 2);

		// Calculate ribbon for the bow by calculating the volume:
		int volume = box.length * box.height * box.width;
		requiredRibbon += volume;

		return requiredRibbon;
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