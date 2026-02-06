#include "AltitudeSensor.hpp"

double AltitudeSensor::read(){
	std::uniform_real_distribution<> temp(100.0, 500.0);
	return temp(_rng);
}