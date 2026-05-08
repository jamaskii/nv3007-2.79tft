#include <SPI.h>
#include "tft_nv3007.h"

#define TFT_DC_PIN          2   // D4
#define TFT_RST_PIN         0   // D3
#define TFT_CS_PIN          15  // D8
#define TFT_BL_PIN          16  // D0


// Will use default SPI pins: SCL→D5; SDA→D7
SPISettings spi_tft(40000000, MSBFIRST, SPI_MODE0);

// TFT screen device context
tft_conf_t tft;

void setup() {
    tft.x_pixels = 142;
    tft.y_pixels = 428;
    tft.x_offset = 12;
    tft.y_offset = 0;
    tft.cs_pin = 15;    // D8
    tft.dc_pin = 2;     // D4
    tft.rst_pin = 0;    // D3
    tft.bl_pin = 16;    // D0
    tft.spi_handle = &spi_tft;

    tft_init(&tft);
}

void loop() {
    tft_clear(&tft, RGB565_RED);
    delay(2000);
    tft_clear(&tft, RGB565_GREEN);
    delay(2000);
    tft_clear(&tft, RGB565_BLUE);
    delay(2000);
    tft_clear(&tft, RGB565_BLACK);
    delay(2000);
}
