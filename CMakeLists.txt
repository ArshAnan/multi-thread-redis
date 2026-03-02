# This is always the first line in the CMakeLists.txt file, and it tells CMake the minimum version of CMake that is required to build the project.
cmake_minimum_required(VERSION 3.20)

# project() declares the project name, version, and language. Here, CXX means C++.
project(multiThreadRedis VERSION 1.0.0 LANGUAGES CXX)

# add_executable() creates an executable target named "multiThreadRedis" that builds the "src/main.cpp" file.
add_executable(multiThreadRedis src/main.cpp)

# set_target_properties() sets the properties of the target.
set_target_properties(multiThreadRedis PROPERTIES
                        CXX_STANDARD 17 # Sets the C++ standard to 17.
                        CXX_STANDARD_REQUIRED ON # If the compiler does not support C++17, fail loudly instead of silently downgrading.
                        CXX_EXTENSIONS OFF) # Disables GNU-specific extensions (like gnu++17). Without this, GCC defaults to gnu++17 instead of pure c++17, which can hide portability bugs that would break on MSVC or Clang.

target_compile_options(multiThreadRedis PRIVATE 
                                            -Wall # Adds the -Wall flag to the compiler. This is a good practice to catch common mistakes and improve code quality.
                                            -Wextra # Adds the -Wextra flag to the compiler. This is a good practice to catch common mistakes and improve code quality.
                                            $<$<CONFIG:Debug>:-g -O0 -fsanitize=address> # Adds the -g -O0 -fsanitize=address flags to the compiler when the build type is Debug.
                                            $<$<CONFIG:Release>:-O2>) # Adds the -O2 flags to the compiler when the build type is Release.

target_link_options(multiThreadRedis PRIVATE 
                                            $<$<CONFIG:Debug>:-fsanitize=address>) # Adds the -fsanitize=address flag to the linker when the build type is Debug.