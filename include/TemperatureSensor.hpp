#pragma once
#include "random"
#include "Sensor.hpp"

class TemperatureSensor : public Sensor {
	public:
		double read() override;
};