cmake_minimum_required(VERSION 3.28) # Specify CMake version.
project(HW_2_AERSP424) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.

include(CTest)
enable_testing()

# Dependencies
find_package(OpenGL REQUIRED)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

FetchContent_Declare(
        glew
        GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
)
FetchContent_MakeAvailable(glew)
# Our Project
set(SOURCE_FILES
    main4.cpp)

add_executable(Problem4 ${SOURCE_FILES})
target_link_libraries(Problem4 OpenGL::GL glfw libglew_static)

set(CPACK_PROJECT_NAME Problem4})
set(CPACK_PROJECT_VERSION Problem4)
include(CPack)


add_executable(Problem1 main1.cpp Sensor.cpp)
add_executable(Problem2 main2.cpp Robot.cpp)
add_executable(Problem3 main3.cpp Airport.cpp)
