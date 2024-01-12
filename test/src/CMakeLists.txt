
cmake_minimum_required(VERSION 3.0)
project(A)

# Set CMP0003 policy to suppress the warning
cmake_policy(SET CMP0003 NEW)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} )

# Create a library for object_counter
add_library(object_counter object_counter.cpp)

# Create a test executable for the object_counter class
add_executable(object_counter_test object_counter_test.cpp)

# Link the object_counter library and Google Test to the test executable
target_link_libraries(object_counter_test object_counter ${GTEST_LIBRARIES} pthread benchmark)

enable_testing()
add_test(NAME object_counter_test COMMAND object_counter_test)  # Reference the test target
