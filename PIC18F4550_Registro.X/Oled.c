#include "Oled.h"
#include "i2c.h"

static void ssd1306_command(unsigned char command){
  unsigned char control = 0x00;  // Co=0, D/C=0
  I2C_Start();
  I2C_Send(SSD1306_ADDR << 1);
  I2C_Send(control);
  I2C_Send(command);
  I2C_Stop();
}

void OLED_Init(void){
    I2C_Init(I2C_STANDARD_SPEED);
    I2C_Stop();
    ssd1306_command( SSD1306_DISPLAY_OFF);
    ssd1306_command( SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO);
    ssd1306_command( 0x80);
    ssd1306_command( SSD1306_SET_MULTIPLEX_RATIO );
    ssd1306_command( SSD1306_LCDHEIGHT - 1 );
    ssd1306_command( SSD1306_SET_DISPLAY_OFFSET );
    ssd1306_command(0x00);
    ssd1306_command( SSD1306_SET_START_LINE|0x00);  // Line: 0
    ssd1306_command( SSD1306_CHARGE_PUMP );
    
    ssd1306_command(0x14);
    ssd1306_command( SSD1306_MEMORY_ADDR_MODE );
    ssd1306_command(0x00);  //Horizontal Addressing Mode is Used
    ssd1306_command( SSD1306_SET_SEGMENT_REMAP| 0x01);
    ssd1306_command( SSD1306_COM_SCAN_DIR_DEC );
    
#if defined SSD1306_128_32
  ssd1306_command( SSD1306_SET_COM_PINS );
  ssd1306_command( 0x02 );
  ssd1306_command( SSD1306_SET_CONTRAST_CONTROL );
  ssd1306_command(0x8F);

#elif defined SSD1306_128_64
  ssd1306_command( SSD1306_SET_COM_PINS );
  ssd1306_command( 0x12 );
  ssd1306_command( SSD1306_SET_CONTRAST_CONTROL );
  // ssd1306_command(0x9F);  Use with External VCC
  ssd1306_command(0xCF);
#endif
  
  ssd1306_command( SSD1306_SET_PRECHARGE_PERIOD );
  // ssd1306_command( 0x22 ); Use with External VCC
  ssd1306_command( 0xF1 );
  ssd1306_command( SSD1306_SET_VCOM_DESELECT );
  ssd1306_command( 0x40 );
  ssd1306_command( SSD1306_DISPLAY_ALL_ON_RESUME );
  ssd1306_command( SSD1306_NORMAL_DISPLAY );
  ssd1306_command( SSD1306_DEACTIVATE_SCROLL );
  ssd1306_command( SSD1306_DISPLAY_ON );
}

void OLEDsetCursor(unsigned int x,unsigned int y){
    ssd1306_command(COLUMNAS);
    ssd1306_command(x);
    ssd1306_command(0x7F);
    ssd1306_command(PAGINAS);
    ssd1306_command(y);
    ssd1306_command(0x07);
}

void OLED_Write(char dato){
    I2C_Start();
    I2C_Send(SSD1306_ADDR << 1);
    I2C_Send(0x40);
    I2C_Send(dato);
    I2C_Stop();
}

void OLED_NPuts(char *buffer){
    I2C_Start();
    I2C_Send(SSD1306_ADDR << 1);
    I2C_Send(0x40);
    while(*buffer){
        char c = *buffer;
        int x = c - 32;
        x=x*6;
        for(int i=0;i<6;i++){
            I2C_Send(SMALL_FONTS[x+i]);
        }
        buffer++;
    }   
    I2C_Stop();
}

void OLED_NPut(char buffer){
    int x = buffer - 32;
    x=x*6;
    I2C_Start();
    I2C_Send(SSD1306_ADDR << 1);
    I2C_Send(0x40);
    for(int i=0;i<6;i++){
        I2C_Send(SMALL_FONTS[x+i]);
    }
    I2C_Stop();
}

void OLED_SPuts(unsigned int x,unsigned int y,char *buffer){
    OLEDsetCursor(x,y);
    while(*buffer){
        for(int j=0;j<2;j++){
            OLEDsetCursor(x,y+j);
            I2C_Start();
            I2C_Send(SSD1306_ADDR << 1);
            I2C_Send(0x40);
            char c = *buffer;
            int xi = c - 32;
            xi=xi*32 + (16*j);
            for(int i=0;i<16;i++){
                I2C_Send(BIG_FONTS[xi+i]);
            }
            I2C_Stop();
        }
        x+=13;
        buffer++;
    }   
    
}

void OLED_SPut(unsigned int x,unsigned int y,char buffer){
    int xi = buffer - 32;
    xi=xi*3;
    I2C_Start();
    I2C_Send(SSD1306_ADDR << 1);
    I2C_Send(0x40);
    for(int i=0;i<3;i++){
        I2C_Send(TINY_FONTS[xi+i]);
    }
    I2C_Stop();
}

void OLEDClear(void){
    OLEDsetCursor(0,0);
    I2C_Start();
    I2C_Send(SSD1306_ADDR << 1);
    I2C_Send(0x40);
    for(int i = 0; i < 1024; i++){
        I2C_Send(0);
    }
    I2C_Stop();
}
