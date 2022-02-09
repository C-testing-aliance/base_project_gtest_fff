###############################################################################
# Minimal CMake version that is needed to process current project
cmake_minimum_required(VERSION 3.6)
###############################################################################
# Languages that are used in the project
enable_language(C)
###############################################################################
# Main project name
project(cred_storage)
###############################################################################
add_library(${PROJECT_NAME} EXCLUDE_FROM_ALL)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/cred_storage.c)
target_link_libraries(${PROJECT_NAME} PRIVATE fs)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
###############################################################################
add_executable(${PROJECT_NAME}_test)
target_sources(${PROJECT_NAME}_test PRIVATE 
	${PROJECT_SOURCE_DIR}/test/cred_storage_test.cpp
)
target_link_libraries(${PROJECT_NAME}_test PRIVATE gtest)
target_include_directories(${PROJECT_NAME}_test PRIVATE 
	${PROJECT_SOURCE_DIR}/inc
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/test
)
gtest_discover_tests(${PROJECT_NAME}_test)