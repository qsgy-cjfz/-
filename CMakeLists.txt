cmake_minimum_required(VERSION 3.5)
project(qsgy)

include (cmake/utils.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined")

include_directories(.)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_library(YAMLCPP libyaml-cpp.a)
message("***", ${YAMLCPP})

set(LIB_SRC
	qsgy/log.cc
	qsgy/util.cc
	qsgy/config.cc
	)

add_library(qsgy SHARED ${LIB_SRC})
force_redefine_file_macro_for_sources(qsgy) #__FILE__
#add_library(qsgy_static STATIC ${LIBSRC})
#SET_TARGET_PROPERTIES (qsgy_static PROPERTIES OUTPUT_NAME "qsgy")

add_executable(test tests/test.cc)
add_dependencies(test qsgy)
force_redefine_file_macro_for_sources(test) #__FILE__
target_link_libraries(test qsgy ${YAMLCPP})

add_executable(test_config tests/test_config.cc)
add_dependencies(test_config qsgy)
force_redefine_file_macro_for_sources(test_config) #__FILE__
target_link_libraries(test_config qsgy ${YAMLCPP})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
