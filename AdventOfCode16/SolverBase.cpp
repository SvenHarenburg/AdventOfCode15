#include <iostream>
#include <fstream>
#include <sstream>

#include "SolverBase.h"

namespace base {
	SolverBase::SolverBase(std::string solverName, bool withInputFile) {
		name = solverName;

		if (withInputFile) {
			input = ReadInputFromFile(name + ".txt");
		}
	}

	std::string SolverBase::ReadInputFromFile(std::string filePath) {
		std::ifstream stream(filePath);
		if (!stream.good()) {
			std::cout << "Could not find input file: " << filePath << "\n";
			// TODO: Figure out how exceptions work and throw.
		}
		std::stringstream buffer;
		buffer << stream.rdbuf();
		return buffer.str();
	}

	std::string SolverBase::GetName() {
		return name;
	}
}