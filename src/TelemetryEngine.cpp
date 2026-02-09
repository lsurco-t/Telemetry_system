#include "TelemetryEngine.hpp"

TelemetryEngine::TelemetryEngine(): _temp(), _alt(), _vel(), _running(false){
	 _packets.reserve(1000);
}

TelemetryEngine::~TelemetryEngine(){
	stop();
}

void TelemetryEngine::run(){
	while(_running){
		TelemetryPacket sample = getLatestPacket();
		{
			std::lock_guard<std::mutex> lock(_packetsMutex);
			if (_packets.size() >= 1000){
				_packets.erase(_packets.begin());
			}
			_packets.push_back(sample);
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void TelemetryEngine::start(){
	if (_running == true){
		return;
	}
	_running = true;
	_worker = std::thread(&TelemetryEngine::run, this);
}

void TelemetryEngine::stop(){
	_running = false;
	if (_worker.joinable()){
		_worker.join();
	}
}

TelemetryPacket TelemetryEngine::getLatestPacket(){
	TelemetryPacket packet;
	packet.temperature = _temp.read();
	packet.altitude = _alt.read();
	packet.velocity = _vel.read();
	auto now = std::chrono::system_clock::now();
	packet.timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
	return packet;
}

std::vector<TelemetryPacket> TelemetryEngine::getPackets() const {
	std::lock_guard<std::mutex> lock(_packetsMutex);
	return _packets;
}

size_t TelemetryEngine::getPacketsSize() const {
	std::lock_guard<std::mutex> lock(_packetsMutex);
	return _packets.size();
}

bool TelemetryEngine::isRunning(){
	return _running;
}

size_t TelemetryEngine::clearPacket(){
	std::lock_guard<std::mutex> lock(_packetsMutex);
	size_t nbrPackets = _packets.size();
	_packets.clear();
	return nbrPackets;
}

std::vector<TelemetryPacket> TelemetryEngine::drainPackets(){
	std::lock_guard<std::mutex> lock(_packetsMutex);
	std::vector<TelemetryPacket> oldData;
	oldData.swap(_packets);
	return oldData;
}
