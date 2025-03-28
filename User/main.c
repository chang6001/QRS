#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"


void GPIO_config(void){
    // 1. ʱ�ӳ�ʼ��
    rcu_periph_clock_enable(RCU_GPIOB);
    // 2. ����GPIO �������ģʽ
    gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_2);
    // 3. ����GPIO ģʽ�Ĳ�����ʽ
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_2);
}

int main(void)
{
    GPIO_config();
    systick_config();
    
    while(1) {
        
        // ����PB2Ϊ�ߵ�ƽ
        gpio_bit_set(GPIOB, GPIO_PIN_2);
        delay_1ms(100);
        // ����PB2Ϊ�͵�ƽ
        gpio_bit_reset(GPIOB, GPIO_PIN_2);
        delay_1us(100000);
    }
}
