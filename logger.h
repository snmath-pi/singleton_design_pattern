#pragma once

#include <string>
#include <mutex>
class Logger
{
	static int ctr;
	static Logger* loggerInstance;
	static std::mutex mtx;
	Logger();
	Logger(const Logger&);
	Logger operator=(const Logger&);
public:
	static Logger* getLogger();
	void Log(std::string msg);
};
