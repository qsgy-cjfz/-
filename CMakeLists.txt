cmake_minimum_required(VERSION 3.5)
project(qsgy)

include (cmake/utils.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined")

include_directories(.)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(LIB_SRC
	qsgy/log.cc
	qsgy/util.cc
	qsgy/config.cc
	qsgy/thread.cc
	)

add_library(qsgy SHARED ${LIB_SRC})
force_redefine_file_macro_for_sources(qsgy) #__FILE__
#add_library(qsgy_static STATIC ${LIBSRC})
#SET_TARGET_PROPERTIES (qsgy_static PROPERTIES OUTPUT_NAME "qsgy")

find_library(YAMLCPP yaml-cpp)
find_library(PTHREAD pthread)
#set(LIBS ${LIBS} qsgy)
#set(LIBS ${LIBS} ${YAMLCPP})
#set(LIBS ${LIBS} ${PTHREAD})

set(LIBS
		qsgy
		pthread
		yaml-cpp)

message("***", ${LIBS})

add_executable(test tests/test.cc)
add_dependencies(test qsgy)
force_redefine_file_macro_for_sources(test) #__FILE__
target_link_libraries(test qsgy ${LIBS})

add_executable(test_config tests/test_config.cc)
add_dependencies(test_config qsgy)
force_redefine_file_macro_for_sources(test_config) #__FILE__
target_link_libraries(test_config qsgy ${LIBS})

add_executable(test_thread tests/test_thread.cc)
add_dependencies(test_thread qsgy)
force_redefine_file_macro_for_sources(test_thread) #__FILE__
target_link_libraries(test_thread qsgy ${LIBS})


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
