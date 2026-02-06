#include "VelocitySensor.hpp"

double VelocitySensor::read(){
	std::uniform_real_distribution<> veloc(7.0, 10.0);
	return veloc(_rng);
}