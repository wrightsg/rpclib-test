project(rpclib-test)
cmake_minimum_required(VERSION 3.10.2)

add_subdirectory(lib)

add_executable(server server.cpp)

target_compile_options(server PRIVATE -Wall -Wextra)

target_link_libraries(server rpc)

if(WIN32 AND MINGW)
    # TODO Why is this necessary? Might be fault in rpclic CMakeLists.
    target_link_libraries(server wsock32 ws2_32)
endif()
