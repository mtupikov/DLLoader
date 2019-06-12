#pragma once

#include "IDLLoader.h"

#include <Windows.h>
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
    };

    bool openLibrary() override {
        m_handle = LoadLibrary(this->m_libraryPath.c_str());

        return m_handle != nullptr;
    }

    bool closeLibrary() override {
        return FreeLibrary(m_handle);
    }

    template <typename... Args>
    std::shared_ptr<T> getInstance(Args... args) {
        using Alloc = T* (*)();
        using Delete = void(*)(T *);

        auto allocFunction = reinterpret_cast<Alloc>(GetProcAddress(m_handle, this->m_allocSymbol.c_str()));
        auto deleteFunction = reinterpret_cast<Delete>(GetProcAddress(m_handle, this->m_deleteSymbol.c_str()));

        if (!allocFunction || !deleteFunction) {
            closeLibrary();
            std::cerr << "Cannot find alloc and/or delete function(s) in " << this->m_libraryPath << " library." << std::endl;
            return nullptr;
        }

        return std::shared_ptr<T>(allocFunction(args...), [deleteFunction](T* p) {
            deleteFunction(p);
        });
    }

private:
    HMODULE m_handle{ nullptr };
};

} // end namespace dlloader
