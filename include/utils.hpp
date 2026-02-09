#pragma once
#include <string>
#include <utility>
#include <algorithm>

namespace utils {
	std::string trim(const std::string& line);
	std::pair<std::string, std::string> getFirstToken(const std::string& line);
}