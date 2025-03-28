#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"


void GPIO_config(void){
    // 1. 时钟初始化
    rcu_periph_clock_enable(RCU_GPIOB);
    // 2. 配置GPIO 输入输出模式
    gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_2);
    // 3. 配置GPIO 模式的操作方式
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_2);
}

int main(void)
{
    GPIO_config();
    systick_config();
    
    while(1) {
        
        // 设置PB2为高电平
        gpio_bit_set(GPIOB, GPIO_PIN_2);
        delay_1ms(100);
        // 设置PB2为低电平
        gpio_bit_reset(GPIOB, GPIO_PIN_2);
        delay_1us(100000);
    }
}
