cmake_minimum_required(VERSION 3.14)

project(StepNN LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(StepNN_BUILD_SHARED "Build StepNN as shared library" true)
# Install StepNN or not
option(StepNN_INSTALL "Install StepNN" ON)

option(StepNN_USE_NEOML "Use ABBYY NeoML" ON)

set(REPO_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ROOT ${REPO_ROOT}/cmake)
set(CMAKE_HELPERS_DIR ${CMAKE_ROOT}/helpers)
set(SRC_ROOT ${REPO_ROOT}/src)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_ROOT})
list(APPEND CMAKE_MODULE_PATH ${SRC_ROOT})

include(Target)
include(StepNN)

# NeoML
if(StepNN_USE_NEOML)
	set(ENV{NeoML_ROOT} "C:/StepTech/SDK/NeoML") # Root for NeoML library
	find_package(NeoML REQUIRED)
endif()

# Install
include(Install)
