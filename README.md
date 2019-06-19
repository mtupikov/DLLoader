## Description
Simple multiplatform (Windows, MacOs, Linux) dll loader.

## Usage
Copy **DLLoader** directory somewhere in your project. Make sure that your `CMakeLists.txt` contains `add_subdirectory("DLLoader")` and you link your library/executable using `target_link_libraries(<your_lib> dlloader)`.

For successful usage you must provide interface with these two `typedefs`:
```
typedef <InterfaceName>* allocator_t();
typedef void deleter_t(<InterfaceName>*);
```
DLL must provide two functions with default (`allocator` and `deleter`) or specified by you names (see [TestLibrary.cpp](/TestLibrary/TestLibrary.cpp) for details). In case if you want to change names of these functions don't forget to specify them in `DLLoader` constructor (`m_allocSymbol` and `m_deleteSymbol`, see [IDLLoader.h](DLLoader/IDLLoader.h) for details).
