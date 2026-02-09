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
		TemperatureSensor _temp;
		AltitudeSensor _alt;
		VelocitySensor _vel;

		std::vector<TelemetryPacket> _packets;
		mutable std::mutex _packetsMutex;
		std::thread _worker;
		std::atomic<bool> _running;

		void run();

	public:
		TelemetryEngine();
		~TelemetryEngine();
		void start();
		void stop();
		std::vector<TelemetryPacket> getPackets() const;
		size_t getPacketsSize() const;
		TelemetryPacket getLatestPacket();
		bool isRunning();
};