#include "utils.hpp"

namespace utils {
	std::string trim(const std::string& line){
		size_t start = line.find_first_not_of(" \n\t\r");
		size_t end = line.find_last_not_of(" \n\t\r");
		if (start == std::string::npos){
			return "";
		}
		return line.substr(start, end - start + 1);
	}

	std::pair<std::string, std::string> getFirstToken(const std::string& line){
		std::pair<std::string, std::string> tokens;
		std::string trimmedLine = trim(line);
		size_t spacePos = trimmedLine.find(' ');
		if (spacePos == std::string::npos){
			tokens.first = trimmedLine;
			tokens.second = "";
		} else {
			tokens.first = trimmedLine.substr(0, spacePos);
			tokens.second = trimmedLine.substr( spacePos + 1);
		}
		return tokens;
	}
}