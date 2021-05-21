cmake_minimum_required(VERSION 3.17)
project(money-tdd)
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(CMAKE_CXX_STANDARD 14)
# Prevent overriding the parent project's compiler/linker
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#添加头文件搜索路径
include_directories(/usr/local/include)
#添加库文件搜索路径
link_directories(/usr/local/lib)
# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)
add_library(cny src/CNY.cpp)
add_library(money src/Money.cpp)
add_library(usd src/USD.cpp)
add_executable(moneyTest test/MoneyTest.cpp)
target_link_libraries(moneyTest gtest_main cny money usd)
enable_testing()
add_test(NAME moneyTest COMMAND moneyTest)