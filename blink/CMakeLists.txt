# 设置Cmake 最小依赖版本
cmake_minimum_required(VERSION 3.17)
# 设置c/c++ 编译版本
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 导入 pico sdk cmake
include(pico_sdk_import.cmake)

# ====================================================================================
# 设置开发板为 pico w （如果你的开发板是 pico 可以注释这行)
set(PICO_BOARD pico_w CACHE STRING "Board type")

# 设置项目名
project(blink C CXX ASM)
# 初始化sdk
pico_sdk_init()

# 添加执行文件
add_executable(blink 
blink.c
)

# 设置项目名称字符串
pico_set_program_name(blink "blink")
# 设置项目版本号
pico_set_program_version(blink "0.1")

# Modify the below lines to enable/disable output over UART/USB
# 是否打开 UART 串口
pico_enable_stdio_uart(blink 0)
# 是否打开USB 串口
pico_enable_stdio_usb(blink 1)


# 添加依赖库 (pico w 必须加入 pico_cyw43_arch_none ）
target_link_libraries(blink
        pico_stdlib              # for core functionality
        pico_cyw43_arch_none     # we need Wifi to access the GPIO, but we don't need anything else
        )
# 设置输出文件
pico_add_extra_outputs(blink)

