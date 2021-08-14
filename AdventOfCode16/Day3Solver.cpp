#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Day3Solver.h"

namespace day3 {
	const std::string inputFileName{ "Day3Input.txt" };

	struct House {
		int x{ 0 };
		int y{ 0 };
	};

	void Day3Solver::Solve() {
		std::cout << "Starting to solve Day3\n";
		auto input = ReadInputFromFile(inputFileName);

		// Starting house is added by default with x=0;y=0
		std::vector<House> housesVisited{ House{} };
		int currentX{ 0 };
		int currentY{ 0 };

		// Loop through the input character for character:
		for (std::string::size_type i = 0; i < input.size(); ++i) {
			char &c{ input[i] };

		// Determine direction and update currentX or currentY accordingly
			switch (c) {
			case '>': 
				++currentX;
				break;

			case 'v':
				--currentY;
				break;

			case '<':
				--currentX;
				break;

			case '^':
				++currentY;
				break;
			}

			// Check if the current coordinates have been visited already:
			bool alreadyVisited{ false };
			for (size_t i = 0; i < housesVisited.size(); i++)
			{
				House &currentHouse = housesVisited[i];
				if (currentHouse.x == currentX && currentHouse.y == currentY) {
					alreadyVisited = true;
					break;
				}
			}

			if (!alreadyVisited) {
				housesVisited.push_back(House{ currentX,currentY });
			}
		}

		std::cout << "Houses visited at least once: " << housesVisited.size() << "\n";
		std::cout << "Day3 solved.\n";

	}

	std::string Day3Solver::ReadInputFromFile(std::string filePath) {
		std::ifstream stream(filePath);
		std::stringstream buffer;
		buffer << stream.rdbuf();
		return buffer.str();
	}
}