# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/ycc-yfb/pico/pico-sdk/tools/pioasm"
  "/Users/ycc-yfb/workspace/raspberrypi/Raspberry_Pi_Pico_C_Tutorial/blink_freertos/build/pioasm"
  "/Users/ycc-yfb/workspace/raspberrypi/Raspberry_Pi_Pico_C_Tutorial/blink_freertos/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm"
  "/Users/ycc-yfb/workspace/raspberrypi/Raspberry_Pi_Pico_C_Tutorial/blink_freertos/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/Users/ycc-yfb/workspace/raspberrypi/Raspberry_Pi_Pico_C_Tutorial/blink_freertos/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "/Users/ycc-yfb/workspace/raspberrypi/Raspberry_Pi_Pico_C_Tutorial/blink_freertos/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/Users/ycc-yfb/workspace/raspberrypi/Raspberry_Pi_Pico_C_Tutorial/blink_freertos/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/ycc-yfb/workspace/raspberrypi/Raspberry_Pi_Pico_C_Tutorial/blink_freertos/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/ycc-yfb/workspace/raspberrypi/Raspberry_Pi_Pico_C_Tutorial/blink_freertos/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
