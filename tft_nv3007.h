#ifndef _TFT_NV3007_H
#define _TFT_NV3007_H

#include <SPI.h>


#define RGB565_RED      0XF800
#define RGB565_GREEN    0X07E0
#define RGB565_BLUE     0X001F
#define RGB565_WHITE    0XFFFF
#define RGB565_BLACK    0X0000


// Context of a TFT screen device
struct tft_conf_t{
    uint8_t dc_pin;
    uint8_t rst_pin;
    uint8_t cs_pin;
    uint8_t bl_pin;
    uint16_t x_pixels;
    uint16_t y_pixels;
    uint16_t x_offset;
    uint16_t y_offset;
    SPISettings* spi_handle;
};

// Initialize a TFT screen device
void tft_init(tft_conf_t* tft);

// Send 8-bit command to a TFT screen device
void tft_send_cmd(tft_conf_t* tft, uint8_t cmd);

// Send 8-bit data to a TFT screen device
void tft_send_data(tft_conf_t* tft, uint8_t dat);

// Send 16-bit data to a TFT screen device
void tft_send_data16(tft_conf_t* tft, uint16_t dat);

// Send target area to a TFT screen device
void tft_set_addr(tft_conf_t* tft, uint16_t x, uint16_t y, uint16_t x_end, uint16_t y_end);

// Clear TFT screen with specified color
void tft_clear(tft_conf_t* tft, uint16_t color);

#endif
