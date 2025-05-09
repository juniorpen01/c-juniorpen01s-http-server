add_executable(${EXE_NAME} /${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
target_link_libraries(${EXE_NAME} PRIVATE core::core)
