# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(raytracer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
set(SOURCES
    Math/Vector3D.cpp
    Math/Point3D.cpp
    RayTracer/Rectangle.cpp
    RayTracer/Sphere.cpp
    RayTracer/Camera.cpp
    main.cpp
)

# Create executable
add_executable(raytracer ${SOURCES})

# Include directories
target_include_directories(raytracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
