foreach(exe "server" "client")
    set(target ${exe}-add)

    add_executable(${target} ${exe}.cpp)

    set_target_properties(${target} PROPERTIES OUTPUT_NAME ${exe})

    target_compile_options(${target} PRIVATE -Wall)

    target_link_libraries(${target} rpc)

    if(WIN32 AND MINGW)
        # TODO This probably should be done in the CMakeLists of rpclib
        target_link_libraries(${target} wsock32 ws2_32)
    endif()
endforeach()
