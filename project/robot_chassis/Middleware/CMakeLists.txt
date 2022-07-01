
zephyr_library()

aux_source_directory(Motor/Src MOTOR_SRCS)

zephyr_include_directories(Motor/Inc)

zephyr_library_sources(${MOTOR_SRCS})

