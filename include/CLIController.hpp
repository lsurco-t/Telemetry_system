#pragma once
#include "TelemetryEngine.hpp"
#include "utils.hpp"
#include <string>
#include <chrono>

class CLIController {
	private:
		TelemetryEngine& _engine;
		
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
		CLIController(TelemetryEngine& Engine);
		CLIController(const CLIController& other) = delete;
		CLIController& operator=(const CLIController& other) = delete;
		~CLIController();
		void runCLI();	
};	