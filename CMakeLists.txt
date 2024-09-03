# CMakeList.txt : CMake project for BurninG, include source and define
# project specific logic here.
#

#cmake -B [build directory] -S [source directory] -DCMAKE_TOOLCHAIN_FILE=D:/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake

cmake_minimum_required (VERSION 3.8)

project ("MPI-Test" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

# 设置运行时库选项
if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}/MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}/MD")
endif()

if(win32)
    find_package(MSMPI REQUIRED)
    set(MPI_LIBRARIES msmpi)
    set(MPI_INCLUDE_PATH $ENV{MSMPI_INC})
    set(MPI_LIBRARY_PATH $ENV{MSMPI_LIB64})
else()
    find_package(MPI REQUIRED)
endif()

# 显示 MPI 库和头文件信息
message(STATUS "MPI Include Path: ${MPI_INCLUDE_PATH}")
message(STATUS "MPI Libraries: ${MPI_LIBRARIES}")

# 添加 MPI 包含路径
include_directories(${MPI_INCLUDE_PATH})
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add your source files
set(SOURCES
    src/main.cpp
)
add_executable(MPI-Test ${SOURCES})

# 链接 MPI 库
target_link_libraries(MPI-Test ${MPI_LIBRARIES})

# Set Install
set(CMAKE_INSTALL_PREFIX "./bin")
install(TARGETS MPI-Test DESTINATION bin)
