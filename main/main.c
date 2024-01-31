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
        int count = 0;
        // lcd_test(&dev,1,1);
        while(1){
            // // Tính số chữ số của số nguyên
            // int digitCount = snprintf(NULL, 0, "%d", count);
            // // Chỉ định kích thước cần thiết cho mảng
            // char *charArray = malloc(digitCount + 1);   
            // sprintf(charArray, "%d", count);
            lcd_display(&dev,"Count:",2,0);
            lcd_display(&dev,intToString(count),2,7);
            count++;
            vTaskDelay(100); // Chờ 1000 miligiây (1 giây)
        }
        
    }
    else{
        printf("khong roi duoc");
    };
    
}
