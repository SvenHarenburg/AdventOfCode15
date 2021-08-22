#pragma once
#include <string>
#include <vector>

#include "SolverBase.h"

namespace day3 {
	struct House {
		int x{ 0 };
		int y{ 0 };
	};

	struct DeliveryGuy {
		int x{ 0 };
		int y{ 0 };
	};

	class Day3Solver : public base::SolverBase {
	private:
		void SolvePart1();
		void SolvePart2();
		void MoveDeliveryGuy(DeliveryGuy& deliveryGuy, char move);
		bool AlreadyVisited(std::vector<House>& housesVisited, int x, int y);

	public:
		Day3Solver() : SolverBase("Day3", true) {};
		void Solve() override;

	};
}