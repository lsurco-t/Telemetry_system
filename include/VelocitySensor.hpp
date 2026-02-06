#pragma once
#include <random>
#include "Sensor.hpp"

class VelocitySensor : public Sensor {
	public:
		double read() override;
};