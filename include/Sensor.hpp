#pragma once

class Sensor {
	public:
		virtual ~Sensor() = default;
		virtual double read() = 0;
};