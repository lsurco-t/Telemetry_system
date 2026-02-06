#include "VelocitySensor.hpp"

double read(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> veloc(7.0, 10.0);

	return veloc(gen);
}