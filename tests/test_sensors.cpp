#include <cassert>
#include <iostream>
#include "TemperatureSensor.hpp"
#include "AltitudeSensor.hpp"
#include "VelocitySensor.hpp"
#include "TelemetryEngine.hpp"

void test_temperature(){
	TemperatureSensor tempSensor;

	double value = tempSensor.read();
	assert(value >= 10.0 && value <= 40.0);
	std::cout << "✓ Test passed\n";
}

void test_altitude(){
	AltitudeSensor altSensor;

	double value = altSensor.read();
	assert(value >= 100.0 && value <= 500.0);
	std::cout << "✓ Test passed\n";
}

void test_velocity(){
	VelocitySensor velSensor;

	double value = velSensor.read();
	assert(value >= 7.0 && value <= 10.0);
	std::cout << "✓ Test passed\n";
}

int main(void){
	test_temperature();
	test_altitude();
	test_velocity();
	return 0;
}