#pragma once
#include <string>

namespace base {
	class SolverBase {
	private:
		std::string ReadInputFromFile(std::string filePath);
		std::string name{};

	protected:
		std::string input{};
		
	public:
		SolverBase(std::string solverName, bool withInputFile);
		virtual void Solve() {};
		std::string GetName();

	};
}