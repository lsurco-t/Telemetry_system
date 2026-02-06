#include <cassert>
#include <iostream>
#include "TemperatureSensor.hpp"
#include "AltitudeSensor.hpp"
#include "VelocitySensor.hpp"
#include "TelemetryEngine.hpp"

void test_temperature(){
	TemperatureSensor tempSensor;

	double value = tempSensor.read();
	std::cout << "Value: " << value << "\n";
	assert(value >= 10.0 && value <= 40.0);
	std::cout << "✓ Test passed\n";
}

void test_altitude(){
	AltitudeSensor altSensor;

	double value = altSensor.read();
	std::cout << "Value: " << value << "\n";
	assert(value >= 100.0 && value <= 500.0);
	std::cout << "✓ Test passed\n";
}

void test_velocity(){
	VelocitySensor velSensor;

	double value = velSensor.read();
	std::cout << "Value: " << value << "\n";
	assert(value >= 7.0 && value <= 10.0);
	std::cout << "✓ Test passed\n";
}

int main(void){
	std::cout << "Temperature values: \n";
	for (int i = 0; i < 10; i++){
		test_temperature();
	}
	std::cout << "Altitude values: \n";
	for (int i = 0; i < 10; i++){
		test_altitude();
	}
	std::cout << "Velocity values: \n";
	for (int i = 0; i < 10; i++){
		test_velocity();
	}	
	return 0;
}