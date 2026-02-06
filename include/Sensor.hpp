#pragma once
#include <random>

class Sensor {
	protected:
		std::mt19937 _rng;

	public:
		Sensor(): _rng(std::random_device{}()){};
		virtual ~Sensor() = default;
		virtual double read() = 0;
};