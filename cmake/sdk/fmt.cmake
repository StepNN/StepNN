set(fmt_DIR "C:/Projects/SDK/fmt/lib/cmake/fmt") # need for spdlog
set(fmt_CONFIG_PATH "${fmt_DIR}/fmt-config.cmake")

include(${fmt_CONFIG_PATH})

target_include_directories(${PROJECT_NAME} PUBLIC ${fmt_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${fmt_LIB})
