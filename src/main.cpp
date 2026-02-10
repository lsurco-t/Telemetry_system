#include <iostream>
#include "CLIController.hpp"

int main (void){
	TelemetryEngine engine;
	CLIController cli(engine);
	cli.runCLI();
	return 0;
}