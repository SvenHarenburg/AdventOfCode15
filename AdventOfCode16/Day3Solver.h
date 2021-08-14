#pragma once
#include <string>
#include <vector>

namespace day3 {
	struct House {
		int x{ 0 };
		int y{ 0 };
	};

	struct DeliveryGuy {
		int x{ 0 };
		int y{ 0 };
	};

	class Day3Solver {
	private:
		std::string input;

		void SolvePart1();
		void SolvePart2();
		std::string ReadInputFromFile(std::string filePath);
		void MoveDeliveryGuy(DeliveryGuy& deliveryGuy, char move);
		bool AlreadyVisited(std::vector<House>& housesVisited, int x, int y);
	public:
		void Solve();
	};
}