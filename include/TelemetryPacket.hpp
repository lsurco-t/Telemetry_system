#pragma once
#include <string>
#include <sstream>

struct TelemetryPacket {
	double 	temperature;
	double 	altitude;
	double 	velocity;
	long 	timestamp;

	std::string writeCSV () const {
		std::ostringstream out;
		out << timestamp << "," << temperature << "," << altitude << "," << velocity;
		return out.str();
	}
};