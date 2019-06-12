#include "TestLibrary.h"

#include <iostream>

#if defined(__linux__) || defined(__APPLE__)
extern "C" {

TestLibrary* allocator() {
    return new TestLibrary();
}

void deleter(TestLibrary* ptr) {
    delete ptr;
}

}
#endif

#ifdef WIN32
extern "C" {

__declspec(dllexport) TestLibrary* allocator() {
    return new TestLibrary();
}

__declspec(dllexport) void deleter(TestLibrary* ptr) {
    delete ptr;
}

}
#endif

void TestLibrary::function() {
    std::cout << "Called TestLibrary::function()" << std::endl;
}
