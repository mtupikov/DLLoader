add_library(testInterface INTERFACE)

target_sources(testInterface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/TestInterface.h)

target_include_directories(testInterface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})