function(CreateExportLibFile target definition_name output_file)
	set(TARGET ${target})
	set(DEFINITION_NAME ${definition_name})
	configure_file(${CMAKE_HELPERS_DIR}/ExportLib.h.in ${output_file} @ONLY)
endfunction()

#..............................................................................

macro(PrefixSuffix ListName Prefix Suffix)
	set(__tmp)
	foreach(val ${${ListName}})
		list(APPEND __tmp "${Prefix}${val}${Suffix}")
	endforeach()
	set(${ListName} ${__tmp})
endmacro()

#..............................................................................

function(AddTarget)
	set(__options
	)
	set(__oneVal
		NAME
		SOURCE_DIR
		TYPE # target type: exe/static_lib/shared_lib
	)
	set(__multiVal
		SRC
		INCLUDES
		DEFINES
		SUBDIRS
		DEPENDENCIES
	)
	cmake_parse_arguments(ARG "${__options}" "${__oneVal}" "${__multiVal}" ${ARGN})

	set(TARGET_NAME ${ARG_NAME})

	foreach(subDir ${ARG_SUBDIRS})
		foreach(mask ${ARG_SRC})
			list(APPEND sourceMasks ${subDir}/${mask})
		endforeach()
	endforeach()

	PrefixSuffix(sourceMasks "${ARG_SOURCE_DIR}" "")

	file(GLOB sources ${sourceMasks})

	if(${ARG_TYPE} STREQUAL "exe")
		add_executable(${TARGET_NAME} ${sources})
	elseif(${ARG_TYPE} STREQUAL "static_lib")
		add_library(${TARGET_NAME} STATIC ${sources})
	elseif(${ARG_TYPE} STREQUAL "shared_lib")
		string(TOUPPER "${ARG_NAME}" ProjNameUpperCase)
		CreateExportLibFile( ${ARG_NAME} ${ProjNameUpperCase}_API ${ARG_NAME}Lib.h )
		add_library(${TARGET_NAME} SHARED ${sources})
	else()
		message(FATAL_ERROR "AddTarget: Incorrect TYPE")
	endif()

	list(APPEND ARG_INCLUDES ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/${TARGET_NAME})
	target_include_directories(${TARGET_NAME} PUBLIC ${ARG_SOURCE_DIR})
	foreach (inc ${ARG_INCLUDES})
		target_include_directories(${TARGET_NAME} PRIVATE ${inc})
	endforeach()

	foreach (dep ${ARG_DEPENDENCIES})
		target_link_libraries(${TARGET_NAME} PRIVATE ${dep})
	endforeach()

	# if (${ARG_TYPE} STREQUAL "exe")
	# 	install(TARGETS ${TARGET_NAME} COMPONENT ${TARGET_NAME} RUNTIME DESTINATION ${TARGET_NAME})
	# 	# install(SCRIPT )
	# add_custom_target(${TARGET_NAME}_Install
	# 	${CMAKE_COMMAND} -DDEST_DIR=${CMAKE_BINARY_DIR}/install/ -DBUILD_TYPE=$<CONFIGURATION> -DCMAKE_INSTALL_COMPONENT=${TARGET_NAME} -P ${CMAKE_CURRENT_SOURCE_DIR}/Fixup.cmake
	# 		DEPENDS ${TARGET_NAME}
	# 		)
	# endif()
endfunction()
