#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Day3Solver.h"

namespace day3 {
	void Day3Solver::Solve() {		
		SolvePart1();
		SolvePart2();
	}

	void Day3Solver::SolvePart1() {
		std::cout << "Starting to solve Day3 Part1\n";

		// Starting house is added by default with x=0;y=0
		std::vector<House> housesVisited{ House{} };
		DeliveryGuy santa;

		// Loop through the input character for character:
		for (std::string::size_type i = 0; i < input.size(); ++i) {
			char& c{ input[i] };

			MoveDeliveryGuy(santa, c);

			// If the house hasn't been visited yet, add it to the vector:
			if (!AlreadyVisited(housesVisited, santa.x, santa.y)) {
				housesVisited.push_back(House{ santa.x,santa.y });
			}
		}

		std::cout << "Houses visited at least once: " << housesVisited.size() << "\n";
		std::cout << "Day3 Part1 solved.\n";
	}

	void Day3Solver::SolvePart2() {
		std::cout << "Starting to solve Day3 Part2\n";

		// Starting house is added by default with x=0;y=0
		std::vector<House> housesVisited{ House{} };
		DeliveryGuy santa{};
		DeliveryGuy roboSanta{};

		// Loop through the input character for character:
		for (std::string::size_type i = 0; i < input.size(); ++i) {
			char& c{ input[i] };

			DeliveryGuy* currentSanta{};
			// Alternate between santa and roboSanta. 0 OR even = santa, uneven = robo
			if (i == 0 || (i % 2) == 0) {
				currentSanta = &santa;
			}
			else {
				currentSanta = &roboSanta;
			}

			MoveDeliveryGuy(*currentSanta, c);

			// If the house hasn't been visited yet, add it to the vector:
			if (!AlreadyVisited(housesVisited, currentSanta->x, currentSanta->y)) {
				housesVisited.push_back(House{ currentSanta->x,currentSanta->y });
			}
		}

		std::cout << "Houses visited at least once: " << housesVisited.size() << "\n";
		std::cout << "Day3 Part2 solved.\n";

	}

	void Day3Solver::MoveDeliveryGuy(DeliveryGuy& deliveryGuy, char move) {
		switch (move) {
		case '>':
			deliveryGuy.x += 1;
			break;

		case 'v':
			deliveryGuy.y -= 1;
			break;

		case '<':
			deliveryGuy.x -= 1;
			break;

		case '^':
			deliveryGuy.y += 1;
			break;
		}
	}

	bool Day3Solver::AlreadyVisited(std::vector<House>& housesVisited, int x, int y) {
		bool alreadyVisited{ false };
		for (size_t i = 0; i < housesVisited.size(); i++)
		{
			House& currentHouse = housesVisited[i];
			if (currentHouse.x == x && currentHouse.y == y) {
				alreadyVisited = true;
				break;
			}
		}
		return alreadyVisited;
	}
}