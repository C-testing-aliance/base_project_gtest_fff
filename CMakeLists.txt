###############################################################################
# Minimal CMake version that is needed to process current project
cmake_minimum_required(VERSION 3.6)
###############################################################################
# Languages that are used in the project
enable_language(C)
###############################################################################
# Main project name
project(base_project)
###############################################################################
include(GoogleTest)
enable_testing()
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/thirdparty/googletest)
add_subdirectory(${PROJECT_SOURCE_DIR}/modules/cred_storage)
add_subdirectory(${PROJECT_SOURCE_DIR}/modules/fs)
###############################################################################
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE cred_storage)
###############################################################################
