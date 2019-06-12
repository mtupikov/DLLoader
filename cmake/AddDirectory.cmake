macro(add_subdir)

    set(process_variables source headers)

    foreach(var ${process_variables})
        set(modified_var_value)
        foreach(value ${${var}})
            list(APPEND modified_var_value "${CMAKE_CURRENT_SOURCE_DIR}/${value}")
        endforeach()
        list(APPEND application_${var} ${modified_var_value})
        set(application_${var} ${application_${var}} PARENT_SCOPE)
    endforeach()

endmacro()