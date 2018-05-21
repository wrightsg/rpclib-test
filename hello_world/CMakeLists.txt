foreach(exe "server" "client")
    add_executable(${exe} ${exe}.cpp)

    target_compile_options(${exe} PRIVATE -Wall)

    target_link_libraries(${exe} rpc)

    if(WIN32 AND MINGW)
        # TODO This probably should be done in the CMakeLists of rpclib
        target_link_libraries(${exe} wsock32 ws2_32)
    endif()
endforeach()
