#pragma once
#include <string>
#include <sstream>

struct TelemetryPacket {
	double 	temperature;
	double 	altitude;
	double 	velocity;
	long 	timestamp;
};