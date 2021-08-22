#include <stdio.h>
#include <string.h>
#include <iostream>
#include <format>

#include <openssl/md5.h>
#include "Day4Solver.h"

// https://stackoverflow.com/questions/32156336/how-to-include-openssl-in-visual-studio
// https://biicode-docs.readthedocs.io/c++/examples/openssl.html
namespace day4 {
	void Day4Solver::Solve() {
		std::cout << "Solving Day4\n";
		
		unsigned char digest[MD5_DIGEST_LENGTH]{};

		int currentNumber{};		
		bool part1Solved{ false };
		bool part2Solved{ false };
		int part1Result{};
		int part2Result{};

		while (!part1Solved || !part2Solved) {
			std::string input = "ckczppom" + std::to_string(currentNumber);
			MD5((unsigned char*)input.c_str(), input.length(), (unsigned char*)&digest);

			// I don't know why but making this array 45 items long will cause a runtime error #2.
			char mdString[46]{};

			for (int i = 0; i < 16; i++) {
				sprintf_s(&mdString[i * 2], sizeof(&mdString[i * 2]) * 2, "%02x", (unsigned int)digest[i]);
			}

			if (mdString[0] == '0'
				&& mdString[1] == '0'
				&& mdString[2] == '0'
				&& mdString[3] == '0'
				&& mdString[4] == '0') {
				if (!part1Solved) {
					part1Result = currentNumber;
					part1Solved = true;
				}

				if (mdString[5] == '0') {
					part2Result = currentNumber;
					part2Solved = true;
					break;
				}				
			}
			++currentNumber;
		}

		std::cout << "Part1: " << part1Result << "\n";
		std::cout << "Part2: " << part2Result << "\n";
		std::cout << "Day4 solved.";
	}
}