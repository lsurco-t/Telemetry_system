#include <cassert>
#include <iostream>
#include "TemperatureSensor.hpp"
#include "AltitudeSensor.hpp"
#include "VelocitySensor.hpp"
#include "TelemetryEngine.hpp"


void test_engine(){
	TelemetryEngine engine;
	
	engine.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(2500));
	engine.stop();
	size_t count = engine.getPacketsSize();
	assert(count >= 2 && count <= 3);
	std::cout << count << " packets returned\n";
}

int main(void){
	std::cout << "Engine test values: \n";
	test_engine();
	return 0;
}