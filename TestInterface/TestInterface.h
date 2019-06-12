#pragma once

class TestInterface {
public:
    virtual ~TestInterface() = default;
    virtual void function() = 0;

    typedef TestInterface* allocator_t();
    typedef void deleter_t(TestInterface*);
};
