# 1. setting up cmake minimum version
cmake_minimum_required(VERSION 3.10)

# 2. set C++ language standard as c++11
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_11)

# 3. setting up project name and current version
#    NOTE: this will automatically define <Example>_VERION_MAJOR and <Example>_VERION_MINOR behind the scenes
project(Example VERSION 0.0)
# 3.1 define final executable
add_executable(Example "example/main.cpp")
# 3.2 set up include directory for example project and external libraries
target_include_directories(Example PUBLIC "example")

# 4. setting up external libraries
add_subdirectory("functions") # adding a library directory
# let "Example" use "functions" as one of its external libraries and use customized "compiler_flags" when compiling the "functions" library.
target_link_libraries(Example PUBLIC functions compiler_flags) 

# 5. after configuring is done we need to provide custom install operations for CMake
install(TARGETS Example DESTINATION "bin")
