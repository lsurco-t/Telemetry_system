#include <iostream>
#include <chrono>

int main (void){
	auto now = std::chrono::system_clock::now();
	long timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();

	return 0;
}