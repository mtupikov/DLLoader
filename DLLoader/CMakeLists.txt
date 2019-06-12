set(headers
    ${CMAKE_CURRENT_SOURCE_DIR}/IDLLoader.h
)

if(WIN32)
    list(APPEND headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Win/DLLoader.h
    )
endif()

if(UNIX)
    list(APPEND headers
        ${CMAKE_CURRENT_SOURCE_DIR}/Unix/DLLoader.h
    )
endif()

add_library(dlloader INTERFACE)

target_sources(dlloader INTERFACE ${headers})

target_include_directories(dlloader INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
