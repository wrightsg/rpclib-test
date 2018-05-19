project(rpclib-test)
cmake_minimum_required(VERSION 3.10.2)

add_subdirectory(lib)

foreach(exe "server" "client")
    add_executable(${exe} ${exe}.cpp)

    target_compile_options(${exe} PRIVATE -Wall -Wextra)

    target_link_libraries(${exe} rpc)

    if(WIN32 AND MINGW)
        # TODO This probably should be done in the CMakeLists of rpclib
        target_link_libraries(${exe} wsock32 ws2_32)
    endif()
endforeach()
