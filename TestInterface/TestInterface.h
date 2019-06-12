#pragma once

class TestInterface {
public:
    virtual ~TestInterface() = default;
    virtual void function() = 0;
};
