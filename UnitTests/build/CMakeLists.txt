cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_C_STANDARD 11)
project (EquinoxC-Logger)
include_directories(../UnityTestFramework/Unity/src)
link_directories(../UnityTestFramework/Unity)

add_executable(UnitTestsOfEquinoxC-Logger.x86 ../Main-Tests-Run.c)

target_link_libraries(UnitTestsOfEquinoxC-Logger.x86 libunity.a)