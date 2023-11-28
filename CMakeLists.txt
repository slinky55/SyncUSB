cmake_minimum_required(VERSION 3.20)
project(SyncUSB)

set(CMAKE_CXX_STANDARD 17)

add_executable(SyncUSB main.cpp
        syncusb.h
        syncusb.cpp)

target_link_libraries(SyncUSB usb-1.0)
