cmake_minimum_required(VERSION 3.16)
project(lencey C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 让可执行文件统一输出到 bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(lencey
    src/main.c
    src/utils/utils.c
    src/net/net.c
)
target_include_directories(lencey PRIVATE src include)   # ← 加上 src
target_compile_options(lencey PRIVATE -Wall -Wextra -g -O0)

# 单元测试
enable_testing()
add_executable(test_utils test/test_utils.c src/utils/utils.c)
target_include_directories(test_utils PRIVATE src include)   # ← 同样加 src
add_test(NAME test_utils COMMAND test_utils)

# Debug 构建挂 sanitizer：抓越界、悬空指针、整数溢出、UB
foreach(tgt lencey test_utils)
    target_compile_options(${tgt} PRIVATE
        -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(${tgt} PRIVATE -fsanitize=address,undefined)
endforeach()

set_target_properties(test_utils PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test_bin)
