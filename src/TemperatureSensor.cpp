#include "TemperatureSensor.hpp"

double TemperatureSensor::read(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> temp(10.0, 40.0);

	return temp(gen);
}