#include "user.h"
#include "logger.h"
#include <iostream>

#include <thread>

void user1Logs() {
	Logger* logger1 = Logger::getLogger();
	logger1->Log("this is from user1");
}

void user2Logs() {
	Logger* logger2 = Logger::getLogger();
	logger2->Log("this is from user2");
}
int main() {
	

	std::thread t1(user1Logs);
	std::thread t2(user2Logs);

	t1.join();
	t2.join();

	return 0;
}