#include "LoggingFactory.h"

namespace StepNN::Logging {

spdlog::sink_ptr CreateSinkConsole(LoggingSyncMode syncMode, LOG_LEVEL level)
{
	spdlog::sink_ptr sink;
	if(syncMode == LoggingSyncMode::Sync)
		sink = std::make_shared<spdlog::sinks::stdout_color_sink_st>();
	else
		sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	sink->set_level(level);

	return sink;
}

//.............................................................................

spdlog::sink_ptr CreateSinkFile(LoggingSyncMode syncMode, LOG_LEVEL level, const std::string& filename, bool truncate/* = false*/)
{
	spdlog::sink_ptr sink;
	if (syncMode == LoggingSyncMode::Sync)
		sink = std::make_shared<spdlog::sinks::basic_file_sink_st>(filename, truncate);
	else
		sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename, truncate);
	sink->set_level(level);

	return sink;
}

//.............................................................................

spdlog::sink_ptr CreateSinkOSS(LoggingSyncMode syncMode, LOG_LEVEL level, std::ostream& oss)
{
	spdlog::sink_ptr sink;
	if (syncMode == LoggingSyncMode::Sync)
		sink = std::make_shared<spdlog::sinks::ostream_sink_st>(oss);
	else
		sink = std::make_shared<spdlog::sinks::ostream_sink_mt>(oss);
	sink->set_level(level);

	return sink;
}

}