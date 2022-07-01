zephyr_include_directories(Inc)

file(GLOB HAL_SRCS Src/*.cpp)

target_sources(app PRIVATE ${HAL_SRCS})
