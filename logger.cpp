#include "logger.h"
#include <iostream>

int Logger::ctr = 0;
Logger* Logger::loggerInstance = nullptr;
std::mutex Logger::mtx;
Logger::Logger() {
	ctr++;
	std::cout << "number of instances of ctr is: " << ctr << std::endl;
}
void Logger::Log(std::string message) {
	std::cout << message << std::endl;
}
Logger* Logger::getLogger() {
	// double check logging
	if (loggerInstance == nullptr) {
		mtx.lock();
		if (loggerInstance == nullptr) {
			loggerInstance = new Logger();
		}
		mtx.unlock();
	}
	return loggerInstance;
}