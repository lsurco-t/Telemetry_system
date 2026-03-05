#include "CLIController.hpp"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <csignal>

constexpr std::string_view yellow = "\033[33m";
constexpr std::string_view reset  = "\033[0m";

static volatile sig_atomic_t signalRunning = 1;

static void signalHandler (int sig){
	(void) sig;
	signalRunning = 0;
}

CLIController::CLIController(TelemetryEngine& Engine) 
	: _engine(Engine){
		signal(SIGINT, SIG_IGN);
		signal(SIGTERM, signalHandler);
}

void CLIController::runCLI(){
	std::string line;
	printHelp();
	while (std::cout << yellow << "Telemetry> " << reset, signalRunning && std::getline(std::cin, line)){
		utils::trim(line);
		if (line.empty()){
			continue;
		}
		auto [cmd, arg] = utils::getFirstToken(line);
		if (cmd == "start"){
			startTelemetry();
		} else if (cmd == "stop"){
			stopTelemetry();
		} else if (cmd == "status"){
			statusTelemetry();
		} else if (cmd == "latest"){
			latestPacket();
		} else if (cmd == "stats"){
			statsBuffer();
		} else if (cmd == "clear"){
			clearBuffer();
		} else if (cmd == "export"){
			exportFile(arg);
		} else if (cmd == "exit"){
			exitCLI();
			break;
		} else if (cmd == "help"){
			printHelp();
		}
	}
}

void CLIController::printHelp(){
	std::cout << "Telemetry CLI — commands:\n";
	std::cout << "  start          Start telemetry collection\n";
	std::cout << "  stop           Stop telemetry collection\n";
	std::cout << "  status         Show whether the engine is running and buffer size\n";
	std::cout << "  latest         Print the latest telemetry packet\n";
	std::cout << "  stats          Show basic statistics (avg/min/max) for sensors\n";
	std::cout << "  clear          Clear the stored packet buffer\n";
	std::cout << "  export <file>  Export packets to CSV file (optional filename)\n";
	std::cout << "  exit           Stop telemetry (if running) and exit CLI\n";
	std::cout << "  help           Show this help text\n";
	std::cout << std::endl;
}

void CLIController::startTelemetry() const {
	if (_engine.isRunning()){
		return;
	}
	_engine.start();
	std::cout << "Telemetry system started.\n";
}

void CLIController::stopTelemetry() const {
	if (!_engine.isRunning()){
		return;
	}
	_engine.stop();
	std::cout << "Telemetry system stopped.\n";
}

void CLIController::statusTelemetry() const {
	if (_engine.isRunning()){
		std::cout << "Running: yes\n";
		std::cout << "Buffer size: " << _engine.getPacketsSize() << "\n";
	} else {
		std::cout << "Running: no\n";
	}
}

void CLIController::latestPacket() const {
	if (_engine.getPacketsSize() == 0){
		return;
	}
	TelemetryPacket latestPacket = _engine.getLatestPacket();
	std::cout << "Time : " << latestPacket.timestamp << "\n";
	std::cout << "Temp : " << std::fixed << std::setprecision(2) << latestPacket.temperature << "\n";
	std::cout << "Alt : " << std::fixed << std::setprecision(2) << latestPacket.altitude << "\n";
	std::cout << "Vel : " << std::fixed << std::setprecision(2) << latestPacket.velocity << "\n";
}

void CLIController::statsBuffer() const {
	std::vector<TelemetryPacket> currentPackets = _engine.getPackets();
	size_t sizePackets = currentPackets.size();
	if (currentPackets.empty()){
		std::cout << "No packets available\n";
		return;
	}
	double sum = 0;
	double maxAlt = currentPackets[0].altitude;
	double minVel = currentPackets[0].velocity;
	for (const auto& packet : currentPackets){
		sum += packet.temperature;
		maxAlt = std::max(maxAlt, packet.altitude);
		minVel = std::min(minVel, packet.velocity);
	}
	double avgTemp = sum / sizePackets;
	std::cout << "Avg Temp: " << std::fixed << std::setprecision(2) << avgTemp << "\n";
	std::cout << "Max Alt: " << std::fixed << std::setprecision(2) << maxAlt << "\n";
	std::cout << "Min Vel: " << std::fixed << std::setprecision(2) << minVel << "\n";
	std::cout << "Packets: " << sizePackets << "\n";
}

void CLIController::clearBuffer() {
	size_t removed = _engine.clearPacket();
	std::cout << "Cleared " << removed << " packets.\n";
}

void CLIController::exportFile(const std::string& arg) {
	auto packets = _engine.getPackets();
	if (packets.empty()){
		std::cout << "No data to export.\n";
		return;
	}
	std::string filename = arg;
	if (filename.empty()){
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::stringstream ss;
		ss << "telemetry_" << std::put_time(std::localtime(&now), "%Y%m%d_%H%M%S") << ".csv";
		filename = ss.str();
	}
	std::ofstream out(filename);
	if (!out){
		std::cerr << "Error: Could not create file" << filename << ".\n";
		return;
	}
	out << "Temperature, Altitude, Velocity, Timestamp\n";
	for (const auto& data : packets){
		out << data.temperature << ","
			<< data.altitude << ","
			<< data.velocity << ","
			<< data.timestamp << "\n";
	}
	std::cout << "Data succesfully exported to: " << filename << ".\n";
}

void CLIController::exitCLI(){
	if (_engine.isRunning()){
		_engine.stop();
	}
	exportFile("");
	std::cout << "Closing program ...\n";
}

CLIController::~CLIController(){
	exitCLI();
}
