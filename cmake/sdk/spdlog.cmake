set(spdlog_CONFIG_PATH "C:/Projects/SDK/spdlog/lib/cmake/spdlog/spdlogConfig.cmake")
include(${spdlog_CONFIG_PATH})

target_include_directories(${PROJECT_NAME} PUBLIC ${spdlog_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${spdlog_LIB})
