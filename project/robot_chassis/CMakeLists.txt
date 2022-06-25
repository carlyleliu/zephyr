# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(BOARD stm32_f429ve)

#set(CONF_FILE prj.conf)
# list(APPEND CONF_FILE "platform.conf")

# set(OVERLAY_CONFIG stm32_f429ve.overlay)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(robot_chassis)

target_sources(app PRIVATE src/main.c)
