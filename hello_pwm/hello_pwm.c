#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PIN_PWM0  ( 12 )

int main() {
    static pwm_config pwm0_slice_config;
    uint pwm0_slice_num;

    {   /* 将指定的 GPIO 引脚设置为 PWM 功能 */
        gpio_set_function( PIN_PWM0, GPIO_FUNC_PWM );
        pwm0_slice_num = pwm_gpio_to_slice_num( PIN_PWM0 );
    }

    {
        /* 获取 PWM 默认配置 */
        pwm0_slice_config = pwm_get_default_config();
    }

    {   
        pwm_init( pwm0_slice_num, &pwm0_slice_config, true );
        /* PWM计时器、计数器、电平值（占空比计数值）被清除0 */
    }

    {   /* 通过 pwm_set_gpio_level 函数实时调整 PWM 输出的占空比 */
        pwm_set_gpio_level( PIN_PWM0, ( pwm0_slice_config.top * 0.20 ) );
        /* 占空比20% */
    }
    
    while ( true )
    {

    }
}