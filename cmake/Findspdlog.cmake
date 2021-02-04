# Cmake script to detect spdlog

if(ENV{spdlog_ROOT} STREQUAL "")
	message(FATAL_ERROR "spdlog_ROOT is empty!")
endif()

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	set(DEBUG_SUFFIX "d")
endif()

find_path(spdlog_INCLUDE_DIR NAMES spdlog/spdlog.h HINTS ENV{spdlog_ROOT} PATH_SUFFIXES include)
find_library(spdlog_LIB NAMES spdlog${DEBUG_SUFFIX} HINTS ENV{spdlog_ROOT} PATH_SUFFIXES lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(spdlog DEFAULT_MSG spdlog_INCLUDE_DIR spdlog_LIB)
mark_as_advanced(spdlog_INCLUDE_DIR spdlog_LIB)

# Linking thirdparty libraries
if(spdlog_FOUND)
	target_include_directories(${PROJECT_NAME} PUBLIC ${spdlog_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} PUBLIC ${spdlog_LIB})
endif()
