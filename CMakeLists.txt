CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
SET(CMAKE_CXX_FLAGS "-std=c++0x")

PROJECT(leetcode_oj)

#SET(CMAKE_BUILD_TYPE Release)

add_executable(add_binary add_binary.cpp)
add_executable(zigzzag_conversion zigzag_conversion.cpp)
add_executable(single_number single_number.cpp)
add_executable(merge_k_sorted_lists merge_k_sorted_lists.cpp)

