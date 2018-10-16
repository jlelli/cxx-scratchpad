cmake_minimum_required (VERSION 2.6)
project (Vector)
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 1)

configure_file (
	"${PROJECT_SOURCE_DIR}/VectorConfig.h.in"
	"${PROJECT_BINARY_DIR}/VectorConfig.h"
	)
include_directories ("${PROJECT_BINARY_DIR}")

include_directories ("${PROJECT_SOURCE_DIR}/Classes")
add_subdirectory (Classes)
set (EXTRA_LIBS ${EXTRA_LIBS} Classes)

add_executable (Vector main.cxx)
target_link_libraries (Vector ${EXTRA_LIBS})

#include(CTest)
#
##does the application run
#add_test (TutorialRuns Tutorial 25)
##does it sqrt of 25
#add_test (TutorialComp25 Tutorial 25)
#set_tests_properties (TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
