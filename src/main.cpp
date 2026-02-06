#include <iostream>
#include <chrono>
#include "TelemetryPacket.hpp"

int main (void){
	long timestamp = std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1);

	return 0;
}