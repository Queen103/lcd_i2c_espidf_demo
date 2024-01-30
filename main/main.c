#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/i2c.h>
#include "esp_log.h"
#include "i2cdev.h"
#include "lcd.h"

i2c_dev_t dev;

void app_main()
{
    if(lcd_init(&dev, I2C_NUM_0, GPIO_NUM_21, GPIO_NUM_22) == ESP_OK){
        printf("duoc roi\n");
        lcd_clear(&dev);
        lcd_display(&dev,"Duoc chua anh?",0,0);
        // lcd_test(&dev,1,1);
        // while(1){
        //     lcd_test_pixal(&dev);
        //     printf("lap\n");
        //     vTaskDelay(5); // Chờ 1000 miligiây (1 giây)
        // }
        
        printf("fail\n");
    }
    else{
        printf("khong roi duoc");
    };
    
}
