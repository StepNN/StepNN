# Cmake script to detect fmtlib

if(ENV{fmt_ROOT} STREQUAL "")
	message(FATAL_ERROR "fmt_ROOT is empty!")
endif()

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
	set(DEBUG_SUFFIX "d")
endif()

find_path(fmt_INCLUDE_DIR NAMES fmt/format.h HINTS ENV{fmt_ROOT} PATH_SUFFIXES include)
find_library(fmt_LIB NAMES fmt${DEBUG_SUFFIX} HINTS ENV{fmt_ROOT} PATH_SUFFIXES lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(fmt DEFAULT_MSG fmt_INCLUDE_DIR fmt_LIB)
mark_as_advanced(fmt_INCLUDE_DIR fmt_LIB)

# Linking thirdparty libraries
if(fmt_FOUND)
	target_include_directories(${PROJECT_NAME} PUBLIC ${fmt_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} PUBLIC ${fmt_LIB})
endif()