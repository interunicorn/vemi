cmake_minimum_required(VERSION 3.20)

project(vemi VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(vemi STATIC
    src/vemi.c
)

option(VEMI_ENABLE_ASAN "Enable AddressSanitizer" ON)

if(VEMI_ENABLE_ASAN)
    add_compile_options(-fsanitize=address -g)
    add_link_options(-fsanitize=address)
endif()

add_subdirectory(tests)

target_include_directories(vemi PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(vemi PUBLIC c_std_11)

target_compile_options(vemi PRIVATE
    -Wall
    -Wextra
    -g
    -O0
    -fsanitize=address
    -fno-omit-frame-pointer
)

target_link_options(vemi PRIVATE
    -fsanitize=address
)
