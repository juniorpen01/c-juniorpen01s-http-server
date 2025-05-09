add_library(core STATIC /${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
target_compile_options(core PUBLIC -Weverything -Werror)
target_include_directories(core PUBLIC /${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(core::core ALIAS core)
