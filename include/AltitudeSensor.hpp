#pragma once
#include <random>
#include "Sensor.hpp"

class AltitudeSensor : public Sensor {
	public:
		double read() override;
};