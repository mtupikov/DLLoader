#pragma once

#include "IDLLoader.h"

#include <dlfcn.h>
#include <iostream>
#include <assert.h>

namespace dlloader {

template <class T>
class DLLoader : public IDLLoader<T> {
public:
    explicit DLLoader(const std::string& libraryPath, const std::string& allocSymbol = "allocator", const std::string& deleteSymbol = "deleter") :
        IDLLoader<T>(libraryPath, allocSymbol, deleteSymbol)
    {
    }

    ~DLLoader() override {
        closeLibrary();
    }

    bool openLibrary() override {
        m_handle = dlopen(this->m_libraryPath.c_str(), RTLD_NOW | RTLD_LAZY);

        return m_handle != nullptr;
    }

    bool closeLibrary() override {
        return dlclose(m_handle);
    }

    template <typename... Args>
    std::shared_ptr<T> getInstance(Args... args) {
        using Alloc = typename T::allocator_t*;
        using Delete = typename T::deleter_t*;

        auto allocFunction = reinterpret_cast<Alloc>(dlsym(m_handle, this->m_allocSymbol.c_str()));
        auto deleteFunction = reinterpret_cast<Delete>(dlsym(m_handle, this->m_deleteSymbol.c_str()));

        if (!allocFunction || !deleteFunction) {
            closeLibrary();
            std::cerr << dlerror() << std::endl;
        }

        return std::shared_ptr<T>(allocFunction(args...), [deleteFunction](T* p) {
            deleteFunction(p);
        });
    }

private:
    void* m_handle;
};

} // end namespace dlloader
