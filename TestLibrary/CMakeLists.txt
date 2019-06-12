add_library(testLibrary SHARED TestLibrary.h TestLibrary.cpp)

target_link_libraries(testLibrary testInterface)

target_include_directories(testLibrary INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
