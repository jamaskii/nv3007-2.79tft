#include "tft_nv3007.h"


void tft_send_cmd(tft_conf_t* tft, uint8_t cmd) {
    digitalWrite(tft->cs_pin, LOW);
    digitalWrite(tft->dc_pin, LOW);
    SPI.transfer(cmd);
    digitalWrite(tft->cs_pin, HIGH);
}

void tft_send_data(tft_conf_t* tft, uint8_t dat) {
    digitalWrite(tft->cs_pin, LOW);
    digitalWrite(tft->dc_pin, HIGH);
    SPI.transfer(dat);
    digitalWrite(tft->cs_pin, HIGH);
}

void tft_send_data16(tft_conf_t* tft, uint16_t dat) {
    digitalWrite(tft->cs_pin, LOW);
    digitalWrite(tft->dc_pin, HIGH);
    SPI.write16(dat);
    digitalWrite(tft->cs_pin, HIGH);
}


void tft_init(tft_conf_t* tft) {
    pinMode(tft->dc_pin, OUTPUT);
    pinMode(tft->cs_pin, OUTPUT);
    pinMode(tft->rst_pin, OUTPUT);
    pinMode(tft->bl_pin, OUTPUT);

    SPI.begin();

    digitalWrite(tft->bl_pin, HIGH);
    digitalWrite(tft->cs_pin, HIGH);

    // Hard reset
    digitalWrite(tft->rst_pin, LOW);
    delay(100);
    digitalWrite(tft->rst_pin, HIGH);
    delay(120);
    
    //NV3006A1N IVO2.6 
    SPI.beginTransaction(*(tft->spi_handle));
    tft_send_cmd(tft, 0xff);
    tft_send_data(tft, 0xa5);  
    tft_send_cmd(tft, 0x9a);
    tft_send_data(tft, 0x08);
    tft_send_cmd(tft, 0x9b);
    tft_send_data(tft, 0x08);  
    tft_send_cmd(tft, 0x9c);
    tft_send_data(tft, 0xb0);  
    tft_send_cmd(tft, 0x9d);
    tft_send_data(tft, 0x16);
    tft_send_cmd(tft, 0x9e);
    tft_send_data(tft, 0xc4);
    tft_send_cmd(tft, 0x8f);
    tft_send_data(tft, 0x55);
    tft_send_data(tft, 0x04);
    tft_send_cmd(tft, 0x84);
    tft_send_data(tft, 0x90);
    tft_send_cmd(tft, 0x83);
    tft_send_data(tft, 0x7b);
    tft_send_cmd(tft, 0x85);
    tft_send_data(tft, 0x33);
    tft_send_cmd(tft, 0x60);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0x70);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0x61);
    tft_send_data(tft, 0x02);
    tft_send_cmd(tft, 0x71);
    tft_send_data(tft, 0x02);
    tft_send_cmd(tft, 0x62);
    tft_send_data(tft, 0x04);
    tft_send_cmd(tft, 0x72);
    tft_send_data(tft, 0x04);
    tft_send_cmd(tft, 0x6c);
    tft_send_data(tft, 0x29);
    tft_send_cmd(tft, 0x7c);
    tft_send_data(tft, 0x29);
    tft_send_cmd(tft, 0x6d);
    tft_send_data(tft, 0x31);
    tft_send_cmd(tft, 0x7d);
    tft_send_data(tft, 0x31);
    tft_send_cmd(tft, 0x6e);
    tft_send_data(tft, 0x0f);
    tft_send_cmd(tft, 0x7e);
    tft_send_data(tft, 0x0f);
    tft_send_cmd(tft, 0x66);
    tft_send_data(tft, 0x21);
    tft_send_cmd(tft, 0x76);
    tft_send_data(tft, 0x21);
    tft_send_cmd(tft, 0x68);
    tft_send_data(tft, 0x3A);
    tft_send_cmd(tft, 0x78);
    tft_send_data(tft, 0x3A);
    tft_send_cmd(tft, 0x63);
    tft_send_data(tft, 0x07);
    tft_send_cmd(tft, 0x73);
    tft_send_data(tft, 0x07);
    tft_send_cmd(tft, 0x64);
    tft_send_data(tft, 0x05);
    tft_send_cmd(tft, 0x74);
    tft_send_data(tft, 0x05);
    tft_send_cmd(tft, 0x65);
    tft_send_data(tft, 0x02);
    tft_send_cmd(tft, 0x75);
    tft_send_data(tft, 0x02);
    tft_send_cmd(tft, 0x67);
    tft_send_data(tft, 0x23);
    tft_send_cmd(tft, 0x77);
    tft_send_data(tft, 0x23);
    tft_send_cmd(tft, 0x69);
    tft_send_data(tft, 0x08);
    tft_send_cmd(tft, 0x79);
    tft_send_data(tft, 0x08);
    tft_send_cmd(tft, 0x6a);
    tft_send_data(tft, 0x13);
    tft_send_cmd(tft, 0x7a);
    tft_send_data(tft, 0x13);
    tft_send_cmd(tft, 0x6b);
    tft_send_data(tft, 0x13);
    tft_send_cmd(tft, 0x7b);
    tft_send_data(tft, 0x13);
    tft_send_cmd(tft, 0x6f);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0x7f);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0x50);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0x52);
    tft_send_data(tft, 0xd6);
    tft_send_cmd(tft, 0x53);
    tft_send_data(tft, 0x08);
    tft_send_cmd(tft, 0x54);
    tft_send_data(tft, 0x08);
    tft_send_cmd(tft, 0x55);
    tft_send_data(tft, 0x1e);
    tft_send_cmd(tft, 0x56);
    tft_send_data(tft, 0x1c);
    //goa map_sel
    tft_send_cmd(tft, 0xa0);
    tft_send_data(tft, 0x2b);
    tft_send_data(tft, 0x24);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xa1);
    tft_send_data(tft, 0x87);
    tft_send_cmd(tft, 0xa2);
    tft_send_data(tft, 0x86);
    tft_send_cmd(tft, 0xa5);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xa6);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xa7);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xa8);
    tft_send_data(tft, 0x36);
    tft_send_cmd(tft, 0xa9);
    tft_send_data(tft, 0x7e);
    tft_send_cmd(tft, 0xaa);
    tft_send_data(tft, 0x7e);
    tft_send_cmd(tft, 0xB9);
    tft_send_data(tft, 0x85);
    tft_send_cmd(tft, 0xBA);
    tft_send_data(tft, 0x84);
    tft_send_cmd(tft, 0xBB);
    tft_send_data(tft, 0x83);
    tft_send_cmd(tft, 0xBC);
    tft_send_data(tft, 0x82);
    tft_send_cmd(tft, 0xBD);
    tft_send_data(tft, 0x81);
    tft_send_cmd(tft, 0xBE);
    tft_send_data(tft, 0x80);
    tft_send_cmd(tft, 0xBF);
    tft_send_data(tft, 0x01);
    tft_send_cmd(tft, 0xC0);
    tft_send_data(tft, 0x02);
    tft_send_cmd(tft, 0xc1);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xc2);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xc3);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xc4);
    tft_send_data(tft, 0x33);
    tft_send_cmd(tft, 0xc5);
    tft_send_data(tft, 0x7e);
    tft_send_cmd(tft, 0xc6);
    tft_send_data(tft, 0x7e);
    tft_send_cmd(tft, 0xC8);
    tft_send_data(tft, 0x33);
    tft_send_data(tft, 0x33);
    tft_send_cmd(tft, 0xC9);
    tft_send_data(tft, 0x68);
    tft_send_cmd(tft, 0xCA);
    tft_send_data(tft, 0x69);
    tft_send_cmd(tft, 0xCB);
    tft_send_data(tft, 0x6a);
    tft_send_cmd(tft, 0xCC);
    tft_send_data(tft, 0x6b);
    tft_send_cmd(tft, 0xCD);
    tft_send_data(tft, 0x33);
    tft_send_data(tft, 0x33); 
    tft_send_cmd(tft, 0xCE);
    tft_send_data(tft, 0x6c);
    tft_send_cmd(tft, 0xCF);
    tft_send_data(tft, 0x6d);
    tft_send_cmd(tft, 0xD0);
    tft_send_data(tft, 0x6e);
    tft_send_cmd(tft, 0xD1);
    tft_send_data(tft, 0x6f);
    tft_send_cmd(tft, 0xAB);
    tft_send_data(tft, 0x03);
    tft_send_data(tft, 0x67);
    tft_send_cmd(tft, 0xAC);
    tft_send_data(tft, 0x03);
    tft_send_data(tft, 0x6b);
    tft_send_cmd(tft, 0xAD);
    tft_send_data(tft, 0x03);
    tft_send_data(tft, 0x68);
    tft_send_cmd(tft, 0xAE);
    tft_send_data(tft, 0x03);
    tft_send_data(tft, 0x6c);
    tft_send_cmd(tft, 0xb3);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xb4);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xb5);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xB6);
    tft_send_data(tft, 0x32);
    tft_send_cmd(tft, 0xB7);
    tft_send_data(tft, 0x7e);
    tft_send_cmd(tft, 0xB8);
    tft_send_data(tft, 0x7e);
    tft_send_cmd(tft, 0xe0);
    tft_send_data(tft, 0x00);
    tft_send_cmd(tft, 0xe1);
    tft_send_data(tft, 0x03);
    tft_send_data(tft, 0x0f);
    tft_send_cmd(tft, 0xe2);
    tft_send_data(tft, 0x04);
    tft_send_cmd(tft, 0xe3);
    tft_send_data(tft, 0x01);
    tft_send_cmd(tft, 0xe4);
    tft_send_data(tft, 0x0e);
    tft_send_cmd(tft, 0xe5);
    tft_send_data(tft, 0x01);
    tft_send_cmd(tft, 0xe6);
    tft_send_data(tft, 0x19);
    tft_send_cmd(tft, 0xe7);
    tft_send_data(tft, 0x10);
    tft_send_cmd(tft, 0xe8);
    tft_send_data(tft, 0x10);
    tft_send_cmd(tft, 0xea);
    tft_send_data(tft, 0x12);
    tft_send_cmd(tft, 0xeb);
    tft_send_data(tft, 0xd0);
    tft_send_cmd(tft, 0xec);
    tft_send_data(tft, 0x04);
    tft_send_cmd(tft, 0xed);
    tft_send_data(tft, 0x07);
    tft_send_cmd(tft, 0xee);
    tft_send_data(tft, 0x07);
    tft_send_cmd(tft, 0xef);
    tft_send_data(tft, 0x09);
    tft_send_cmd(tft, 0xf0);
    tft_send_data(tft, 0xd0);
    tft_send_cmd(tft, 0xf1);
    tft_send_data(tft, 0x0e);
    tft_send_data(tft, 0x17); 
    tft_send_cmd(tft, 0xf2);
    tft_send_data(tft, 0x2c);
    tft_send_data(tft, 0x1b);
    tft_send_data(tft, 0x0b);
    tft_send_data(tft, 0x20);
    ////1 dot
    tft_send_cmd(tft, 0xe9);
    tft_send_data(tft, 0x29);
    tft_send_cmd(tft, 0xec);
    tft_send_data(tft, 0x04);
    //TE
    tft_send_cmd(tft, 0x35);
    tft_send_data(tft, 0x00); 
    tft_send_cmd(tft, 0x44);
    tft_send_data(tft, 0x00);
    tft_send_data(tft, 0x10); 
    tft_send_cmd(tft, 0x46);
    tft_send_data(tft, 0x10); 
    tft_send_cmd(tft, 0xff);
    tft_send_data(tft, 0x00); 
    tft_send_cmd(tft, 0x3a);
    tft_send_data(tft, 0x05); 
    tft_send_cmd(tft, 0x11); 
    delay(220); 
    tft_send_cmd(tft, 0x29); 
    delay(200);
    SPI.endTransaction();
}

void tft_set_addr(tft_conf_t* tft, uint16_t x, uint16_t y, uint16_t x_end, uint16_t y_end)
{
    x += tft->x_offset;
    x_end += tft->x_offset;

    y += tft->y_offset;
    y_end += tft->y_offset;

    tft_send_cmd(tft, 0x2A);
    tft_send_data16(tft, x);
    tft_send_data16(tft, x_end);
    
    tft_send_cmd(tft, 0x2B);
    tft_send_data16(tft, y);
    tft_send_data16(tft, y_end);
    
    tft_send_cmd(tft, 0x2C);
}


void tft_clear(tft_conf_t* tft, uint16_t color) {
    SPI.beginTransaction(*(tft->spi_handle));

    // Set target area
    tft_set_addr(tft,
                 0,                     // Start X
                 0,                     // Start Y
                 tft->x_pixels - 1,     // End X
                 tft->y_pixels - 1     // End Y
    );

    // Pull up DC pin means what's going to sent is data
    digitalWrite(tft->dc_pin, HIGH);
    
    // Pull down CS pin to select target device
    digitalWrite(tft->cs_pin, LOW);
    
    // Calculate sum of pixels
    uint32_t total_pixels = (uint32_t)tft->x_pixels * tft->y_pixels;
    
    // Send pixels
    for(uint32_t i = 0; i < total_pixels; i++)
    {
        SPI.write16(color);
        
        // Feed dog after sending each row
        if ((i % tft->x_pixels) == 0) {
            yield(); 
        }
    }
    
    // Release CS and end SPI
    digitalWrite(tft->cs_pin, HIGH);
    SPI.endTransaction();
}
