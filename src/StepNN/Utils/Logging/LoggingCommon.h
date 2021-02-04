#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include "spdlog/spdlog.h"

// support for loading levels from the environment variable
#include "spdlog/cfg/env.h" 

//async
#include "spdlog/async.h"

// sinks
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/ostream_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"

// fmt
#include "spdlog/fmt/ostr.h" // must be included

namespace StepNN::Logging {

#define LOG_LEVEL	spdlog::level::level_enum
#define L_TRACE		spdlog::level::trace
#define L_DEBUG		spdlog::level::debug
#define L_INFO		spdlog::level::info
#define L_WARN		spdlog::level::warn
#define L_ERROR		spdlog::level::err
#define L_CRITICAL	spdlog::level::critical
#define L_OFF		spdlog::level::off

using LoggerSP = std::shared_ptr<spdlog::logger>;


/*
* Default names for creating logging sinks
* LOGGING_FILE_TRACE_STR is used for dumping backtrace - do not use it
*/
constexpr const char* const LOGGING_CONSOLE_STR		= "logging_console";
constexpr const char* const LOGGING_OSS_STR			= "logging_oss";
constexpr const char* const LOGGING_FILE_INFO_STR	= "logging_file_info";
constexpr const char* const LOGGING_FILE_WARN_STR	= "logging_file_warn";
constexpr const char* const LOGGING_FILE_ERROR_STR	= "logging_file_error";
constexpr const char* const LOGGING_FILE_TRACE_STR	= "logging_file_trace";

}