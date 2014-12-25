CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
SET(CMAKE_CXX_FLAGS "-std=c++0x")

PROJECT(leetcode_oj)

SET(CMAKE_BUILD_TYPE Release)

set(Sources
	add_binary.cpp
)

add_executable(add_binary ${Sources})

