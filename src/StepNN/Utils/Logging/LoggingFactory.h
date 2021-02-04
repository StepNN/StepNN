#pragma once

#include "LoggingCommon.h"
#include "LoggingSyncMode.h"

namespace StepNN::Logging {

spdlog::sink_ptr CreateSinkConsole(LoggingSyncMode, LOG_LEVEL);
spdlog::sink_ptr CreateSinkFile(LoggingSyncMode, LOG_LEVEL, const std::string& filename, bool truncate = false);
spdlog::sink_ptr CreateSinkOSS(LoggingSyncMode, LOG_LEVEL, std::ostream& oss);

}