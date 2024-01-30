#include <string.h>
#include <time.h>
#include "esp_log.h"

#include "lcd.h"

#define TAG "LCD"

esp_err_t write_cmd(i2c_dev_t *dev, uint8_t lcd_res_address, uint8_t lcd_cmd){
    // CHECK_ARG(dev);

	uint8_t data[1];
    data[0] = lcd_cmd;

	return i2c_dev_write_reg(dev, lcd_res_address, data, 1);
}

esp_err_t lcd_init(i2c_dev_t *dev, i2c_port_t port, gpio_num_t sda_gpio, gpio_num_t scl_gpio)
{
    // CHECK_ARG(dev);
    dev->port = port;
    dev->addr = LCD_ADDR;
    dev->sda_io_num = sda_gpio;
    dev->scl_io_num = scl_gpio;
    dev->clk_speed = I2C_FREQ_HZ;
    dev->lcd_column = 0;
    dev->lcd_row = 0;
    i2c_master_init(port, sda_gpio, scl_gpio);
    //reset 
    write_cmd(dev,LCD_ADDR_STATUS1,0xE2);
    vTaskDelay(5);
    // normal screen 
    write_cmd(dev,LCD_ADDR_STATUS1,0xA0);
    write_cmd(dev,LCD_ADDR_STATUS1,0xC8);
    // display brightness
    write_cmd(dev,LCD_ADDR_STATUS1,0x25);
    write_cmd(dev,LCD_ADDR_STATUS1,0x81);
    write_cmd(dev,LCD_ADDR_STATUS1,0x20);

    //internal power supply control mode
    write_cmd(dev,LCD_ADDR_STATUS1,0x2C);
    write_cmd(dev,LCD_ADDR_STATUS1,0x2E);
    write_cmd(dev,LCD_ADDR_STATUS1,0x2F);

    write_cmd(dev,LCD_ADDR_STATUS1,0xAF);
    write_cmd(dev,LCD_ADDR_STATUS1,0x40);

    return ESP_OK;
}

void cursor_dev(i2c_dev_t *dev,uint8_t x,uint8_t y){
    dev->lcd_column = x;
    dev->lcd_row = y;
}

esp_err_t lcd_display(i2c_dev_t *dev , char *str){
    int len = 0;
    len = strlen(str);
    return ESP_OK;
}

void lcd_test_pixal(i2c_dev_t *dev){
    printf("ok\n");
    for(int x = 0 ; x<8 ;x++){
        write_cmd(dev,LCD_ADDR_STATUS1,0xb0 + x);

        write_cmd(dev,LCD_ADDR_STATUS1,0x10);
        write_cmd(dev,LCD_ADDR_STATUS1,0x00);
        for (int i = 0 ; i<128 ; i++){
            write_cmd(dev,LCD_ADDR_STATUS2,0xff);
            vTaskDelay(5); // Chờ 1000 miligiây (1 giây)
        }
    }

    for(int x = 0; x<8 ;x++){
        write_cmd(dev,LCD_ADDR_STATUS1,0xb0 + x);

        write_cmd(dev,LCD_ADDR_STATUS1,0x00);
        write_cmd(dev,LCD_ADDR_STATUS1,0x10);
        for(int i = 0; i<128 ; i++){
            write_cmd(dev,LCD_ADDR_STATUS2,0x00);
            vTaskDelay(5); // Chờ 1000 miligiây (1 giây)
        }
    }
}

void lcd_clear(i2c_dev_t *dev){
    for(int x = 0; x<8 ;x++){
        write_cmd(dev,LCD_ADDR_STATUS1,0xb0 + x);

        write_cmd(dev,LCD_ADDR_STATUS1,0x00);
        write_cmd(dev,LCD_ADDR_STATUS1,0x10);
        for(int i = 0; i<128 ; i++){
            write_cmd(dev,LCD_ADDR_STATUS2,0x00);
        }
    }
}

void lcd_test(i2c_dev_t *dev){
    write_cmd(dev,LCD_ADDR_STATUS3,0x01);
    write_cmd(dev,LCD_ADDR_STATUS1,0x20);
    // write_cmd(dev,LCD_ADDR_STATUS1,0x10+3);
    // write_cmd(dev,LCD_ADDR_STATUS2,0x00);
    // write_cmd(dev,LCD_ADDR_STATUS2,0x26);
    // write_cmd(dev,LCD_ADDR_STATUS2,0x49);
    // write_cmd(dev,LCD_ADDR_STATUS2,0x49);
    // write_cmd(dev,LCD_ADDR_STATUS2,0x49);
    // write_cmd(dev,LCD_ADDR_STATUS2,0x32);
    // write_cmd(dev,LCD_ADDR_STATUS2,0x00);
    // write_cmd(dev,LCD_ADDR_STATUS2,0xAF);
}
