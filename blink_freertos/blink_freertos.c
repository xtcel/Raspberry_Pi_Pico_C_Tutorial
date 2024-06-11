#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "FreeRTOS.h"
#include "task.h"

void led_task(pvParameters)
{   
    // const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    // gpio_init(LED_PIN);
    // gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        // gpio_put(LED_PIN, 1);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        vTaskDelay(100);
        // gpio_put(LED_PIN, 0);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        vTaskDelay(100);
    }
}

void sayHelloWorld(pvParameters)
{
    while (true) {
        printf("Hello, world!\n");
        vTaskDelay(1000);
    }
}

int main()
{
    stdio_init_all();

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

		xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    xTaskCreate(sayHelloWorld, "Hello_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1){};
}