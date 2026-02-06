#include "AltitudeSensor.hpp"

double AltitudeSensor::read(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> temp(100.0, 500.0);
	
	return temp(gen);
}