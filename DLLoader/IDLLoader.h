#pragma once

#include <memory>
#include <string>

namespace dlloader {

template <class T>
class IDLLoader {
public:
    IDLLoader(const std::string& libraryPath, const std::string& allocSymbol, const std::string& deleteSymbol) :
        m_libraryPath(libraryPath),
        m_allocSymbol(allocSymbol),
        m_deleteSymbol(deleteSymbol)
    {
    }

    virtual ~IDLLoader() = default;

    virtual bool openLibrary() = 0;
    virtual bool closeLibrary() = 0;

protected:
    std::string m_libraryPath;
    std::string m_allocSymbol;
    std::string m_deleteSymbol;
};

} // end namespace dlloader
