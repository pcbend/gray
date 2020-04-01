
cmake_minimum_required(VERSION 3.5)
project(gray CXX)
set(CMAKE_CXX_STANDARD 11)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
	message(STATUS "Build type not specified: defaulting to ${CMAKE_BUILD_TYPE}")
endif()

add_subdirectory(Gint)


