#include <iostream>

#include "Day1.h"

namespace day1 {

	int solve(std::string input)
	{
		std::cout << "Starting to solve Day1\n";		
		int floor{ 0 };

		for (char& c : input) {
			if (c == '(') {
				floor++;
			}
			else if (c == ')') {
				floor--;
			}
			else {
				std::cout << "Invalid character: " << c;
			}
		}



		return floor;
	}
}
