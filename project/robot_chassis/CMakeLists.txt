# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(BOARD stm32_f429ve)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(robot_chassis)

add_subdirectory(HAL)
include_directories(HAL/Inc)

file(GLOB application_sources Application/Src/*.cpp)
target_sources(app PRIVATE ${application_sources})
