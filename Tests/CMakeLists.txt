cmake_minimum_required(VERSION 3.10)
project(Tests)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_Release "-O3")
set(CMAKE_BUILD_TYPE Debug)

add_executable(tests tests.c)

target_link_libraries(tests PRIVATE 
    cmocka
    # StackArray
    # SwapbackArray
    # HeapArray
    # RingBuffer
    # Slice
)


