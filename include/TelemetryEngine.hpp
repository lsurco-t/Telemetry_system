#pragma once
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include "TelemetryPacket.hpp"
#include "TemperatureSensor.hpp"
#include "AltitudeSensor.hpp"
#include "VelocitySensor.hpp"

class TelemetryEngine {
	private:
		std::vector<TelemetryPacket> _packets;
		std::mutex _mtx;
		std::atomic<bool> _running;

	public:
		void start();
		void stop();
		void getLatestPacket();
};