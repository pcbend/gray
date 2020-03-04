
#lets match ROOT's minimum cmake version for "reasons"
cmake_minimum_required(VERSION 3.9 FATAL_ERROR)



if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR
    " \n"
    " GRay should be built out-of-sorce.\n"
    " This makes clean-up much easier.\n"
    " Try something like: gray-build/cmake -S ../gray -B .\n")
endif()

project(gray VERSION 0.00.01 DESCRIPTION "gamma-ray analysis via root" HOMEPAGE_URL "" LANGUAGES CXX)



#sets the paths to put various libraries, executables and headers....

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_INSTALL_INCLUDEDIR ${CMAKE_BINARY_DIR}/include)
set(CMAKE_INSTALL_LIBDIR ${CMAKE_BINARY_DIR}/lib)

#set(HEADER_OUTPUT_PATH ${CMAKE_BINARY_DIR}/include)

set(GRAYSYS ${CMAKE_BINARY_DIR})



list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

find_package(ROOT REQUIRED COMPONENTS RIO Net)

include(${ROOT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)








#if (NOT CMAKE_BUILD_TYPE) 
#	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
#	message(STATUS "Build type not specified: defaulting to ${CMAKE_BUILD_TYPE}")
#endif()

add_subdirectory(libraries)
add_subdirectory(src)


