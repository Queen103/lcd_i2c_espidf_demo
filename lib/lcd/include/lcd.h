#include <time.h>
#include <stdbool.h>
#include "driver/i2c.h"

#include "i2cdev.h"

#define LCD_ADDR 0x3F //i2c address 

#define LCD_ADDR_STATUS1 0x00 // 00
#define LCD_ADDR_STATUS2 0x40 // 01
#define LCD_ADDR_STATUS3 0x80 // 10
#define LCD_ADDR_STATUS4 0xC0 // 11



esp_err_t lcd_init(i2c_dev_t *dev, i2c_port_t port, gpio_num_t sda_gpio, gpio_num_t scl_gpio);
esp_err_t write_cmd(i2c_dev_t *dev, uint8_t lcd_res_address, uint8_t lcd_cmd);
esp_err_t turn_all_pixel(i2c_dev_t *dev);
void cursor_dev(i2c_dev_t *dev,uint8_t x,uint8_t y);
void lcd_test_pixal(i2c_dev_t *dev);
void lcd_test(i2c_dev_t *dev);
void lcd_clear(i2c_dev_t *dev);

