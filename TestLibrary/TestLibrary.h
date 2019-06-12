#pragma once

#include "TestInterface.h"

class TestLibrary : public TestInterface {
public:
    TestLibrary() = default;
    ~TestLibrary() override = default;

    void function() override;
};
