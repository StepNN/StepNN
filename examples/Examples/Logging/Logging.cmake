AddTarget(NAME LoggingExample
	TYPE
		exe
	SOURCE_DIR
		${EXAMPLES_ROOT}/Examples/
	SRC
		*.cpp
		*.h
	SUBDIRS
		Logging
	DEPENDENCIES
		StepNN
)