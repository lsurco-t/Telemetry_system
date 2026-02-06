#include "TemperatureSensor.hpp"

double TemperatureSensor::read(){
	std::uniform_real_distribution<> temp(10.0, 40.0);
	return temp(_rng);
}