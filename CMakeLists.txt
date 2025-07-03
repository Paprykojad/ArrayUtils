cmake_minimum_required(VERSION 3.10)
project(Utils)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_Release "-O3")
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

add_subdirectory(Main)
add_subdirectory(Tests)
add_subdirectory(StackArray)

target_include_directories(tests PRIVATE ${CMAKE_HOME_DIRECTORY})
target_link_directories( tests PRIVATE 
    ${CMAKE_HOME_DIRECTORY}/dependencies/static
    ${CMAKE_HOME_DIRECTORY}/dependencies/shared
)

target_include_directories(main PRIVATE ${CMAKE_HOME_DIRECTORY})
target_link_directories( main PRIVATE 
    ${CMAKE_HOME_DIRECTORY}/dependencies/static
    ${CMAKE_HOME_DIRECTORY}/dependencies/shared
)

# add_subdirectory(SwapbackArray)
# add_subdirectory(HeapArray)
# add_subdirectory(RingBuffer)
# add_subdirectory(Slice)
