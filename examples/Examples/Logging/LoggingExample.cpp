#include <random>

#include "StepNN/Utils/Logging/Logging.h"

using namespace StepNN;

void ErrorFunction()
{
	int* ptr = nullptr;
	int i = *ptr;
}

//.............................................................................

void ConfigureLogger()
{
	Logging::LoggingSettings logSettings;
	Logging::LoggingSettings::LogInfos logInfos = {
		{ Logging::LOGGING_CONSOLE_STR		, Logging::LoggingOutputMode::Console	, L_TRACE	},
		{ Logging::LOGGING_FILE_INFO_STR	, Logging::LoggingOutputMode::File		, L_INFO	},
		{ Logging::LOGGING_FILE_WARN_STR	, Logging::LoggingOutputMode::File		, L_WARN	},
		{ Logging::LOGGING_FILE_ERROR_STR	, Logging::LoggingOutputMode::File		, L_ERROR	},
	};
	logSettings.SetLogInfos(std::move(logInfos));
	logSettings.SetSyncMode(Logging::LoggingSyncMode::Async);
	logSettings.SetLogDirectory("C:/Projects/StepNN/StepNN/out/StepNN_Logs");
	logSettings.SetBacktraceSize(10);

	LOGGER.SetLoggingSettings(std::move(logSettings));
}

//.............................................................................

void GenerateMessages()
{
	std::random_device device;
	std::default_random_engine engine(device());
	std::uniform_int_distribution dist(10, 20);
	int errorPoint = dist(engine);

	LOG(L_INFO, "Error point at {}", errorPoint);

	for (int i = 0; i < errorPoint + 1; ++i)
	{
		LOG(L_INFO, "Info {}", i);
		LOG(L_DEBUG, "Debug {}", i);
		LOG(L_TRACE, "Trace {}", i);
		if (i == errorPoint)
			ErrorFunction();
	}
}

//.............................................................................

int main(int argc, char* argv[])
{
	ConfigureLogger();
	GenerateMessages();

	return 0;
}