cmake_minimum_required(VERSION 3.5.1)
project(cpp_workspace)


set( CMAKE_CXX_STANDARD_REQUIRED -std=gnu++14)
set(SOURCE deadPresidents.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})