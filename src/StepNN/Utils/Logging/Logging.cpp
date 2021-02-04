#include <algorithm>

#include "LoggingFactory.h"
#include "Logging.h"

namespace {

std::string GetLogFilename(const std::string& logDir, LOG_LEVEL level)
{
	return logDir + "/" + spdlog::level::to_string_view(level).data() + ".txt";
}

}

namespace StepNN::Logging {

Logger& Logger::Instance()
{
	static Logger obj;
	return obj;
}

//.............................................................................

Logger::~Logger()
{
	if(m_traceLogger)
		m_traceLogger->dump_backtrace();
}

//.............................................................................

void Logger::SetLoggingSettings(LoggingSettings&& settings)
{
	Reset();

	const auto logDir = settings.GetLogDirectory();
	const auto syncMode = settings.GetSyncMode();

	// Create loggers for every mode
	for (const auto& logInfo : settings.GetLogInfos())
	{
		const auto& [name, outputMode, level] = logInfo;

		// LOGGING_FILE_TRACE_STR used only for trace logger
		assert(name != LOGGING_FILE_TRACE_STR);
		if (name == LOGGING_FILE_TRACE_STR)
			continue;

		switch (outputMode)
		{
		case LoggingOutputMode::Console:
			m_sinks.try_emplace(name, CreateSinkConsole(syncMode, level));
			break;
		case LoggingOutputMode::OSS:
			m_sinks.try_emplace(name, CreateSinkOSS(syncMode, level, m_oss));
			break;
		case LoggingOutputMode::File:
			m_sinks.try_emplace(name, CreateSinkFile(syncMode, level, GetLogFilename(logDir, level), true));
			break;
		default:
			break;
		}
	}

	std::vector<spdlog::sink_ptr> sinks;
	std::transform(std::cbegin(m_sinks), std::cend(m_sinks), std::back_inserter(sinks), [](const auto& item) { return item.second; });
	m_logger = std::make_shared<spdlog::logger>("StepNN_logger", std::begin(sinks), std::end(sinks));

	if (Defs::IsValid(settings.GetBacktraceSize()))
	{
		m_traceLogger = std::make_shared<spdlog::logger>("StepNN_trace_logger", CreateSinkFile(syncMode, L_TRACE, GetLogFilename(logDir, L_TRACE), true));
		m_traceLogger->enable_backtrace(settings.GetBacktraceSize());
	}

	m_isInitialized = true;
}

//.............................................................................

void Logger::SetLogLevel(const std::string& sinkName, LOG_LEVEL level)
{
	if (auto it = m_sinks.find(sinkName); it != m_sinks.cend())
		it->second->set_level(level);
}

//.............................................................................

void Logger::Reset()
{
	if (!m_isInitialized)
		return;

	spdlog::shutdown();
	m_sinks.clear();
	m_logger.reset();
	m_traceLogger.reset();

	m_isInitialized = false;
}

}