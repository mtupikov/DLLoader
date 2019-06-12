cmake_minimum_required(VERSION 3.12)

project(test LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} dlloader testInterface)
