cmake_minimum_required(VERSION 3.15)
project(RayTracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/Vec3.cpp
    src/Ray.cpp
    src/Sphere.cpp
    src/Camera.cpp
    src/Material.cpp
    src/Scene.cpp
    src/RayTracer.cpp
)

# Include directories
include_directories(include)

# Create executable
add_executable(raytracer ${SOURCES})

# Compiler flags for optimization
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()
