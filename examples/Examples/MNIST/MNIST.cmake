AddTarget(NAME mnist
	TYPE
		exe
	SOURCE_DIR
		${EXAMPLES_ROOT}/Examples/
	SRC
		*.cpp
		*.h
	SUBDIRS
		MNIST
	DEPENDENCIES
		StepNN
		StepNN_Datasets
)