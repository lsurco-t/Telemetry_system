#include <iostream>
#include "CLIController.hpp"

int main (void){
	TelemetryEngine engine;
	Logger logger;
	CLIController cli(engine, logger);
	cli.runCLI();
	return 0;
}