#pragma once

#include <map>
#include <sstream>

#include "LoggingCommon.h"

#include "LoggingSettings.h"

#include "StepNNLib.h"

namespace StepNN::Logging {

class STEPNN_API Logger
{
public:
	static Logger& Instance();

	template<typename FormatString, typename... Args>
	void Log(LOG_LEVEL level, const FormatString& str, Args&&...args)
	{
		if (m_isInitialized)
		{
			m_logger->log(level, str, std::forward<Args>(args)...);
			//m_traceLogger->log(level, str, std::forward<Args>(args)...);
		}
	}

	void SetLoggingSettings(LoggingSettings&& settings);
	void SetLogLevel(const std::string& sinkName, LOG_LEVEL);
	void Reset();

private:
	Logger() = default;
	~Logger();
	Logger(const Logger&) = delete;
	Logger(Logger&&) = delete;
	Logger& operator=(const Logger&) = delete;
	Logger& operator=(Logger&&) = delete;

private:
	LoggerSP m_logger, m_traceLogger;
	std::map<std::string, spdlog::sink_ptr> m_sinks;
	std::ostringstream m_oss;

	bool m_isInitialized { false };
};

}

#define LOGGER StepNN::Logging::Logger::Instance()
#define LOG StepNN::Logging::Logger::Instance().Log
