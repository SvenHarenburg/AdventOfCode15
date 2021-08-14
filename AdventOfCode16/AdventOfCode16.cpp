// AdventOfCode16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Day1Solver.h"
#include "Day2Solver.h"
#include "Day3Solver.h"

#include <chrono>

int main()
{	
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	/*day1::Day1Solver day1Solver;
	day1Solver.Solve();	*/

	/*day2::Day2Solver day2Solver;
	day2Solver.Solve();*/

	day3::Day3Solver day3Solver;
	day3Solver.Solve();


	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}


