#include <iostream>
#include <fstream>
#include <sstream>

#include "Day2.h"

namespace day2 {
	const std::string inputFileName{ "Day2Input.txt" };
	std::string input{};

	void readInputFromFile();

	void solve() {
		std::cout << "Starting to solve Day2\n";

		readInputFromFile();

		

		std::cout << "Day2 solved\n";
	}

	void readInputFromFile() {
		std::cout << "Reading input file...";
		std::ifstream t(inputFileName);
		std::stringstream buffer;
		buffer << t.rdbuf();
		std::string input = buffer.str();
		std::cout << "  Done.\n";
	}


}