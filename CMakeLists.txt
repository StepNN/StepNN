cmake_minimum_required(VERSION 3.14)

project(StepNN LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(StepNN_BUILD_SHARED "Build StepNN as shared library" true)
option(StepNN_BUILD_DATASETS "Build StepNN datasets module" true)
option(StepNN_BUILD_EXAMPLES "Build StepNN examples module" true)
# Install StepNN or not
option(StepNN_INSTALL "Install StepNN" ON)

option(StepNN_USE_NEOML "Use ABBYY NeoML" ON)

set(REPO_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ROOT ${REPO_ROOT}/cmake)
set(CMAKE_HELPERS_DIR ${CMAKE_ROOT}/helpers)
set(SRC_ROOT ${REPO_ROOT}/src)
set(DATASETS_ROOT ${REPO_ROOT}/datasets)
set(EXAMPLES_ROOT ${REPO_ROOT}/examples)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_ROOT})
list(APPEND CMAKE_MODULE_PATH ${SRC_ROOT})
list(APPEND CMAKE_MODULE_PATH ${DATASETS_ROOT})
list(APPEND CMAKE_MODULE_PATH ${EXAMPLES_ROOT})

set(STEPNN_LIB_TYPE shared_lib)
if(NOT StepNN_BUILD_SHARED)
	set(STEPNN_LIB_TYPE static_lib)
endif()

include(Target)
include(StepNN)
include(Datasets)
include(Examples)

# NeoML
if(StepNN_USE_NEOML)
	set(ENV{NeoML_ROOT} "C:/StepTech/SDK/NeoML") # Root for NeoML library
	find_package(NeoML REQUIRED)
endif()

# Install
include(Install)
