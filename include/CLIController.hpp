#pragma once
#include "TelemetryEngine.hpp"
#include "Logger.hpp"
#include "utils.hpp"
#include <string>
#include <chrono>

class CLIController {
	private:
		TelemetryEngine& _engine;
		Logger& _logger;
		
		void startTelemetry() const;
		void stopTelemetry() const;
		void statusTelemetry() const;
		void latestPacket() const;
		void statsBuffer() const;
		void clearBuffer();
		void exportFile(const std::string& arg);
		void exitCLI();

		void printHelp();
		
	public:
		CLIController(TelemetryEngine& Engine, Logger& logger);
		CLIController(const CLIController& other) = delete;
		CLIController& operator=(const CLIController& other) = delete;
		void runCLI();	
};	