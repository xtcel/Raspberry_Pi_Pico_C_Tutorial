# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/ycc-yfb/pico/pico-sdk/tools/pioasm"
  "/Volumes/A/workspace/raspberrypi/hello_pwm/build/pioasm"
  "/Volumes/A/workspace/raspberrypi/hello_pwm/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm"
  "/Volumes/A/workspace/raspberrypi/hello_pwm/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/Volumes/A/workspace/raspberrypi/hello_pwm/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "/Volumes/A/workspace/raspberrypi/hello_pwm/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/Volumes/A/workspace/raspberrypi/hello_pwm/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Volumes/A/workspace/raspberrypi/hello_pwm/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Volumes/A/workspace/raspberrypi/hello_pwm/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
