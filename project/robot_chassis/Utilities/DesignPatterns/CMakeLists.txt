zephyr_include_directories(Inc)

file(GLOB DESIGN_PATTERNS_SRCS Src/*.cpp)

target_sources(app PRIVATE ${HAL_SRCS})
