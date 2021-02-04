#pragma once

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "LoggingCommon.h"
#include "LoggingOutputMode.h"
#include "LoggingSyncMode.h"

namespace StepNN::Logging {

class LoggingSettings
{
public:
	using LogInfo = std::tuple<std::string, LoggingOutputMode, LOG_LEVEL>;
	using LogInfos = std::vector<LogInfo>;

public:
	void SetLogInfos(const LogInfos& value) { m_logInfos = value; }
	void SetLogInfos(LogInfos&& value) { m_logInfos = std::move(value); }
	void SetLogDirectory(const std::string& value) { m_logDirectory = value; }
	void SetSyncMode(LoggingSyncMode value) { m_syncMode = value; }
	void SetBacktraceSize(int value) { m_backtraceSize = value; }

	const LogInfos& GetLogInfos() const noexcept { return m_logInfos; }
	const std::string& GetLogDirectory() const noexcept { return m_logDirectory; }
	LoggingSyncMode GetSyncMode() const noexcept { return m_syncMode; }
	int GetBacktraceSize() const noexcept { return m_backtraceSize; }

private:
	LogInfos m_logInfos;
	LoggingSyncMode m_syncMode;
	std::string m_logDirectory;
	Z<int, Defs::INVALID_VALUE_INT> m_backtraceSize;
};

}