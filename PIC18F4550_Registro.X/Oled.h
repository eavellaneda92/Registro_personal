/* 
 * File:   Caracteres.h
 * Author: EAVELLANEDA
 *
 * Created on 24 de enero de 2021, 05:24 PM
 */

#define NORMAL  0
#define SMALL   1
#define BIG     2

char FOUNT = 0;

const unsigned char SMALL_FONTS[];
const unsigned char TINY_FONTS[];
const unsigned char BIG_FONTS[];

#define LEFT                  0
#define RIGHT                 254
#define CENTER                255

#define BLACK                 0
#define WHITE                 1
#define INVERSE               2

#define TRUE              1u
#define FALSE             0u

//#define SSD1306_ADDR        0x3D
#define SSD1306_ADDR          0x3C

/* SSD1306 Display Type*/
#define SSD1306_128_64
// #define SSD1306_128_32
// #define SSD1306_96_16

#if defined SSD1306_128_64
  #define SSD1306_LCDWIDTH                  128
  #define SSD1306_LCDHEIGHT                 64
#endif
#if defined SSD1306_128_32
  #define SSD1306_LCDWIDTH                  128
  #define SSD1306_LCDHEIGHT                 32
#endif
#if defined SSD1306_96_16
  #define SSD1306_LCDWIDTH                  96
  #define SSD1306_LCDHEIGHT                 16
#endif

#define SSD1306_COMMAND                     0x00
#define SSD1306_DATA                        0xC0
#define SSD1306_DATA_CONTINUE               0x40

/* SSD1306 Command Set*/
// Fundamental Commands
#define SSD1306_SET_CONTRAST_CONTROL                    0x81
#define SSD1306_DISPLAY_ALL_ON_RESUME                   0xA4
#define SSD1306_DISPLAY_ALL_ON                          0xA5
#define SSD1306_NORMAL_DISPLAY                          0xA6
#define SSD1306_INVERT_DISPLAY                          0xA7
#define SSD1306_DISPLAY_OFF                             0xAE
#define SSD1306_DISPLAY_ON                              0xAF
#define SSD1306_NOP                                     0xE3
// Scrolling Commands
#define SSD1306_HORIZONTAL_SCROLL_RIGHT                 0x26
#define SSD1306_HORIZONTAL_SCROLL_LEFT                  0x27
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_RIGHT    0x29
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_LEFT     0x2A
#define SSD1306_DEACTIVATE_SCROLL                       0x2E
#define SSD1306_ACTIVATE_SCROLL                         0x2F
#define SSD1306_SET_VERTICAL_SCROLL_AREA                0xA3
// Addressing Setting Commands
#define SSD1306_SET_LOWER_COLUMN                        0x00
#define SSD1306_SET_HIGHER_COLUMN                       0x10
#define SSD1306_MEMORY_ADDR_MODE                        0x20
#define SSD1306_SET_COLUMN_ADDR                         0x21
#define SSD1306_SET_PAGE_ADDR                           0x22
// Hardware Configuration Commands
#define SSD1306_SET_START_LINE                          0x40
#define SSD1306_SET_SEGMENT_REMAP                       0xA0
#define SSD1306_SET_MULTIPLEX_RATIO                     0xA8
#define SSD1306_COM_SCAN_DIR_INC                        0xC0
#define SSD1306_COM_SCAN_DIR_DEC                        0xC8
#define SSD1306_SET_DISPLAY_OFFSET                      0xD3
#define SSD1306_SET_COM_PINS                            0xDA
#define SSD1306_CHARGE_PUMP                             0x8D
// Timing & Driving Scheme Setting Commands
#define SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO             0xD5
#define SSD1306_SET_PRECHARGE_PERIOD                    0xD9
#define SSD1306_SET_VCOM_DESELECT                       0xDB

// Constant Fonts
const unsigned char SMALL_FONTS[] ={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // sp
0x00, 0x00, 0x00, 0x2f, 0x00, 0x00,   // !
0x00, 0x00, 0x07, 0x00, 0x07, 0x00,   // "
0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14,   // #
0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12,   // $
0x00, 0x23, 0x13, 0x08, 0x64, 0x62,   // %
0x00, 0x36, 0x49, 0x55, 0x22, 0x50,   // &
0x00, 0x00, 0x05, 0x03, 0x00, 0x00,   // '
0x00, 0x00, 0x1c, 0x22, 0x41, 0x00,   // (
0x00, 0x00, 0x41, 0x22, 0x1c, 0x00,   // )
0x00, 0x14, 0x08, 0x3E, 0x08, 0x14,   // *
0x00, 0x08, 0x08, 0x3E, 0x08, 0x08,   // +
0x00, 0x00, 0x00, 0xA0, 0x60, 0x00,   // ,
0x00, 0x08, 0x08, 0x08, 0x08, 0x08,   // -
0x00, 0x00, 0x60, 0x60, 0x00, 0x00,   // .
0x00, 0x20, 0x10, 0x08, 0x04, 0x02,   // /

0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,   // 0
0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,   // 1
0x00, 0x42, 0x61, 0x51, 0x49, 0x46,   // 2
0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,   // 3
0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,   // 4
0x00, 0x27, 0x45, 0x45, 0x45, 0x39,   // 5
0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,   // 6
0x00, 0x01, 0x71, 0x09, 0x05, 0x03,   // 7
0x00, 0x36, 0x49, 0x49, 0x49, 0x36,   // 8
0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,   // 9
0x00, 0x00, 0x36, 0x36, 0x00, 0x00,   // :
0x00, 0x00, 0x56, 0x36, 0x00, 0x00,   // ;
0x00, 0x08, 0x14, 0x22, 0x41, 0x00,   // <
0x00, 0x14, 0x14, 0x14, 0x14, 0x14,   // =
0x00, 0x00, 0x41, 0x22, 0x14, 0x08,   // >
0x00, 0x02, 0x01, 0x51, 0x09, 0x06,   // ?

0x00, 0x32, 0x49, 0x59, 0x51, 0x3E,   // @
0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,   // A
0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,   // B
0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,   // C
0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C,   // D
0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,   // E
0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,   // F
0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,   // G
0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,   // H
0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,   // I
0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,   // J
0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,   // K
0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,   // L
0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,   // M
0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,   // N
0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,   // O

0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,   // P
0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,   // Q
0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,   // R
0x00, 0x46, 0x49, 0x49, 0x49, 0x31,   // S
0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,   // T
0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,   // U
0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,   // V
0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,   // W
0x00, 0x63, 0x14, 0x08, 0x14, 0x63,   // X
0x00, 0x07, 0x08, 0x70, 0x08, 0x07,   // Y
0x00, 0x61, 0x51, 0x49, 0x45, 0x43,   // Z
0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,   // [
0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55,   // Backslash (Checker pattern)
0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,   // ]
0x00, 0x04, 0x02, 0x01, 0x02, 0x04,   // ^
0x00, 0x40, 0x40, 0x40, 0x40, 0x40,   // _

0x00, 0x00, 0x03, 0x05, 0x00, 0x00,   // `
0x00, 0x20, 0x54, 0x54, 0x54, 0x78,   // a
0x00, 0x7F, 0x48, 0x44, 0x44, 0x38,   // b
0x00, 0x38, 0x44, 0x44, 0x44, 0x20,   // c
0x00, 0x38, 0x44, 0x44, 0x48, 0x7F,   // d
0x00, 0x38, 0x54, 0x54, 0x54, 0x18,   // e
0x00, 0x08, 0x7E, 0x09, 0x01, 0x02,   // f
0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,   // g
0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,   // h
0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,   // i
0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,   // j
0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,   // k
0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,   // l
0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,   // m
0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,   // n
0x00, 0x38, 0x44, 0x44, 0x44, 0x38,   // o

0x00, 0xFC, 0x24, 0x24, 0x24, 0x18,   // p
0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,   // q
0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,   // r
0x00, 0x48, 0x54, 0x54, 0x54, 0x20,   // s
0x00, 0x04, 0x3F, 0x44, 0x40, 0x20,   // t
0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,   // u
0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,   // v
0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,   // w
0x00, 0x44, 0x28, 0x10, 0x28, 0x44,   // x
0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C,   // y
0x00, 0x44, 0x64, 0x54, 0x4C, 0x44,   // z
0x00, 0x00, 0x10, 0x7C, 0x82, 0x00,   // {
0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,   // |
0x00, 0x00, 0x82, 0x7C, 0x10, 0x00,   // }
0x00, 0x00, 0x06, 0x09, 0x09, 0x06    // ~ (Degrees)
};

const unsigned char TINY_FONTS[] = //son 3 caracteres
{
0x00, 0x00, 0x00, 0x03, 0xa0, 0x00, 0xc0, 0x0c, 0x00, 0xf9, 0x4f, 0x80, 0x6b, 0xeb, 0x00, 0x98, 0x8c, 0x80, 0x52, 0xa5, 0x80, 0x03, 0x00, 0x00,  // Space, !"#$%&'
0x01, 0xc8, 0x80, 0x89, 0xc0, 0x00, 0x50, 0x85, 0x00, 0x21, 0xc2, 0x00, 0x08, 0x40, 0x00, 0x20, 0x82, 0x00, 0x00, 0x20, 0x00, 0x18, 0x8c, 0x00,  // ()*+,-./
0xfa, 0x2f, 0x80, 0x4b, 0xe0, 0x80, 0x5a, 0x66, 0x80, 0x8a, 0xa5, 0x00, 0xe0, 0x8f, 0x80, 0xea, 0xab, 0x00, 0x72, 0xa9, 0x00, 0x9a, 0x8c, 0x00,  // 01234567
0xfa, 0xaf, 0x80, 0x4a, 0xa7, 0x00, 0x01, 0x40, 0x00, 0x09, 0x40, 0x00, 0x21, 0x48, 0x80, 0x51, 0x45, 0x00, 0x89, 0x42, 0x00, 0x42, 0x66, 0x00,  // 89:;<=>?
0x72, 0xa6, 0x80, 0x7a, 0x87, 0x80, 0xfa, 0xa5, 0x00, 0x72, 0x25, 0x00, 0xfa, 0x27, 0x00, 0xfa, 0xa8, 0x80, 0xfa, 0x88, 0x00, 0x72, 0x2b, 0x00,  // @ABCDEFG
0xf8, 0x8f, 0x80, 0x8b, 0xe8, 0x80, 0x8b, 0xe8, 0x00, 0xf8, 0x8d, 0x80, 0xf8, 0x20, 0x80, 0xf9, 0x0f, 0x80, 0xf9, 0xcf, 0x80, 0x72, 0x27, 0x00,  // HIJKLMNO
0xfa, 0x84, 0x00, 0x72, 0x27, 0x40, 0xfa, 0x85, 0x80, 0x4a, 0xa9, 0x00, 0x83, 0xe8, 0x00, 0xf0, 0x2f, 0x00, 0xe0, 0x6e, 0x00, 0xf0, 0xef, 0x00,  // PQRSTUVW
0xd8, 0x8d, 0x80, 0xc0, 0xec, 0x00, 0x9a, 0xac, 0x80, 0x03, 0xe8, 0x80, 0xc0, 0x81, 0x80, 0x8b, 0xe0, 0x00, 0x42, 0x04, 0x00, 0x08, 0x20, 0x80,  // XYZ[\]^_
0x02, 0x04, 0x00, 0x31, 0x23, 0x80, 0xf9, 0x23, 0x00, 0x31, 0x24, 0x80, 0x31, 0x2f, 0x80, 0x31, 0x62, 0x80, 0x23, 0xea, 0x00, 0x25, 0x53, 0x80,  // `abcdefg
0xf9, 0x03, 0x80, 0x02, 0xe0, 0x00, 0x06, 0xe0, 0x00, 0xf8, 0x42, 0x80, 0x03, 0xe0, 0x00, 0x79, 0x87, 0x80, 0x39, 0x03, 0x80, 0x31, 0x23, 0x00,  // hijklmno
0x7d, 0x23, 0x00, 0x31, 0x27, 0xc0, 0x78, 0x84, 0x00, 0x29, 0x40, 0x00, 0x43, 0xe4, 0x00, 0x70, 0x27, 0x00, 0x60, 0x66, 0x00, 0x70, 0x67, 0x00,  // pqrstuvw
0x48, 0xc4, 0x80, 0x74, 0x57, 0x80, 0x59, 0xe6, 0x80, 0x23, 0xe8, 0x80, 0x03, 0x60, 0x00, 0x8b, 0xe2, 0x00, 0x61, 0x0c, 0x00                     // zyx{|}~
};

const unsigned char BIG_FONTS[] = {   // Size is 16x16 (3044 -- need to check)
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // <space>
0x00,0x00,0x00,0x00,0xF8,0xFC,0xFC,0xFC,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x73,0x73,0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // !
0x00,0x00,0x00,0x00,0x1E,0x3E,0x3E,0x00,0x00,0x00,0x3E,0x3E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // "
0x00,0x30,0x30,0x30,0xFE,0xFE,0x30,0x30,0x30,0x30,0xFE,0xFE,0x30,0x30,0x30,0x00,0x00,0x0C,0x0C,0x0C,0x7F,0x7F,0x0C,0x0C,0x0C,0x0C,0x7F,0x7F,0x0C,0x0C,0x0C,0x00,  // #
0x00,0x00,0x00,0xF0,0xF8,0x98,0xFE,0x98,0x98,0xFE,0x98,0x98,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x19,0x19,0x7F,0x19,0x19,0x7F,0x19,0x1F,0x0F,0x00,0x00,0x00,  // $
0x00,0x00,0x00,0x00,0x38,0x38,0x38,0x80,0xC0,0xE0,0x70,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x0E,0x07,0x03,0x01,0x1C,0x1C,0x1C,0x00,0x00,0x00,0x00,  // %
0x00,0x00,0x00,0x38,0xFC,0xC4,0xC4,0xFC,0x38,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3F,0x21,0x21,0x33,0x3F,0x1E,0x1E,0x37,0x23,0x00,0x00,0x00,  // &
0x00,0x00,0x00,0x00,0x20,0x3C,0x3C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // '
0x00,0x00,0x00,0x00,0xC0,0xE0,0xF0,0x38,0x1C,0x0C,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0F,0x1C,0x38,0x30,0x20,0x20,0x00,0x00,0x00,0x00,  // (
0x00,0x00,0x00,0x00,0x04,0x04,0x0C,0x1C,0x38,0xF0,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x30,0x38,0x1C,0x0F,0x07,0x03,0x00,0x00,0x00,0x00,  // )
0x00,0x00,0x80,0x88,0x90,0xE0,0xE0,0xFC,0xFC,0xE0,0xE0,0x90,0x88,0x80,0x00,0x00,0x00,0x00,0x01,0x11,0x09,0x07,0x07,0x3F,0x3F,0x07,0x07,0x09,0x11,0x01,0x00,0x00,  // *
0x00,0x00,0x00,0x00,0x80,0x80,0x80,0xF0,0xF0,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x0F,0x0F,0x01,0x01,0x01,0x00,0x00,0x00,0x00,  // +
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x78,0x78,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ,
0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,  // -
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // .
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,0x1C,0x00,0x00,0x00,0x00,0x20,0x30,0x38,0x1C,0x0E,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,  // /

0x00,0x00,0x00,0xF8,0xFC,0xFC,0x04,0x84,0xE4,0x74,0xFC,0xFC,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x3F,0x2E,0x27,0x21,0x20,0x3F,0x3F,0x1F,0x00,0x00,0x00,  // 0
0x00,0x00,0x00,0x60,0x60,0x60,0xF0,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x3F,0x3F,0x3F,0x20,0x20,0x20,0x00,0x00,0x00,0x00,  // 1
0x00,0x00,0x00,0x18,0x1C,0x1C,0x04,0x04,0x84,0xCC,0xFC,0x78,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x38,0x3C,0x2E,0x27,0x23,0x21,0x38,0x38,0x38,0x00,0x00,0x00,  // 2
0x00,0x00,0x00,0x18,0x1C,0x1C,0x84,0x84,0x84,0xCC,0x7C,0x78,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x38,0x38,0x21,0x21,0x21,0x33,0x3E,0x1E,0x0C,0x00,0x00,0x00,  // 3
0x00,0x00,0x00,0x80,0xC0,0x60,0x30,0x18,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x23,0x23,0x3F,0x3F,0x3F,0x23,0x23,0x00,0x00,0x00,  // 4
0x00,0x00,0x00,0xFC,0xFC,0xFC,0x84,0x84,0x84,0x84,0x84,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x19,0x39,0x39,0x21,0x21,0x21,0x33,0x3F,0x1F,0x0E,0x00,0x00,0x00,  // 5
0x00,0x00,0x00,0xE0,0xF0,0xF8,0x9C,0x8C,0x84,0x84,0x84,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x3F,0x21,0x21,0x21,0x21,0x3F,0x3F,0x1F,0x00,0x00,0x00,  // 6
0x00,0x00,0x00,0x3C,0x3C,0x3C,0x04,0x04,0x04,0x04,0x84,0xFC,0xFC,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x3C,0x3E,0x07,0x03,0x01,0x00,0x00,0x00,0x00,  // 7
0x00,0x00,0x00,0x78,0x7C,0xFC,0xC4,0xC4,0x84,0x84,0xFC,0x7C,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3E,0x3F,0x21,0x21,0x23,0x23,0x3F,0x3E,0x1E,0x00,0x00,0x00,  // 8
0x00,0x00,0x00,0xF8,0xFC,0xFC,0x84,0x84,0x84,0x84,0xFC,0xFC,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x21,0x21,0x21,0x31,0x39,0x1F,0x0F,0x07,0x00,0x00,0x00,  // 9
0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x0E,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // :
0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x1E,0x1E,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ;
0x00,0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,0x1C,0x0E,0x06,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0E,0x1C,0x38,0x70,0x60,0x40,0x00,0x00,0x00,0x00,  // <
0x00,0x00,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x00,0x00,0x00,0x00,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x00,0x00,  // =
0x00,0x00,0x00,0x02,0x06,0x0E,0x1C,0x38,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x60,0x70,0x38,0x1C,0x0E,0x07,0x03,0x01,0x00,0x00,0x00,0x00,  // >
0x00,0x00,0x00,0x18,0x1C,0x0C,0x0E,0x06,0x86,0xCE,0xFC,0x7C,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x73,0x73,0x73,0x00,0x00,0x00,0x00,0x00,0x00,  // ?

0x00,0x00,0x00,0xFC,0xFE,0xFE,0x02,0x02,0xC2,0xC2,0xC2,0xFE,0xFE,0xFC,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x7F,0x60,0x60,0x63,0x63,0x63,0x63,0x43,0x03,0x00,0x00,  // @
0x00,0x00,0x00,0xE0,0xF0,0xF8,0x1C,0x0C,0x0C,0x1C,0xF8,0xF0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x02,0x02,0x02,0x02,0x3F,0x3F,0x3F,0x00,0x00,0x00,  // A
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x84,0x84,0x84,0xFC,0xFC,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x21,0x21,0x21,0x3F,0x3F,0x1E,0x00,0x00,0x00,  // B
0x00,0x00,0x00,0xF0,0xF8,0xFC,0x0C,0x04,0x04,0x04,0x1C,0x1C,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x3F,0x30,0x20,0x20,0x20,0x38,0x38,0x18,0x00,0x00,0x00,  // C
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x04,0x04,0x0C,0xFC,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x20,0x20,0x30,0x3F,0x1F,0x0F,0x00,0x00,0x00,  // D
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x84,0x84,0x84,0xC4,0xCC,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x21,0x21,0x21,0x23,0x33,0x38,0x00,0x00,0x00,  // E
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x84,0x84,0x84,0xC4,0xCC,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x21,0x01,0x01,0x03,0x03,0x00,0x00,0x00,0x00,  // F
0x00,0x00,0x00,0xF0,0xF8,0xFC,0x0C,0x04,0x04,0x04,0x3C,0x3C,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x3F,0x30,0x20,0x22,0x22,0x3E,0x3E,0x3E,0x00,0x00,0x00,  // G
0x00,0x00,0x00,0xFC,0xFC,0xFC,0x80,0x80,0x80,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x01,0x01,0x01,0x3F,0x3F,0x3F,0x00,0x00,0x00,0x00,  // H
0x00,0x00,0x00,0x00,0x04,0x04,0xFC,0xFC,0xFC,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x3F,0x3F,0x20,0x20,0x00,0x00,0x00,0x00,0x00,  // I
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0xFC,0xFC,0xFC,0x04,0x04,0x00,0x00,0x00,0x00,0x1E,0x1E,0x3E,0x20,0x20,0x20,0x20,0x3F,0x3F,0x1F,0x00,0x00,0x00,0x00,  // J
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0xC0,0xE0,0x70,0x3C,0x1C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x03,0x07,0x0E,0x3C,0x38,0x30,0x00,0x00,0x00,  // K
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x20,0x20,0x20,0x30,0x38,0x3C,0x00,0x00,0x00,  // L
0x00,0x00,0x00,0xFC,0xFC,0xFC,0x78,0xF0,0xE0,0xF0,0x78,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x00,0x00,0x01,0x00,0x00,0x3F,0x3F,0x3F,0x00,0x00,  // M
0x00,0x00,0x00,0xFC,0xFC,0xFC,0x70,0xE0,0xC0,0x80,0x00,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x00,0x00,0x01,0x03,0x07,0x3F,0x3F,0x3F,0x00,0x00,  // N
0x00,0x00,0x00,0xE0,0xF0,0xF8,0x1C,0x0C,0x0C,0x0C,0x1C,0xF8,0xF0,0xE0,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x1F,0x38,0x30,0x30,0x30,0x38,0x1F,0x0F,0x07,0x00,0x00,  // O

0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x84,0x84,0x84,0xFC,0xFC,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x21,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,  // P
0x00,0x00,0x00,0xE0,0xF8,0xF8,0x1C,0x0C,0x04,0x0C,0x1C,0xF8,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x1F,0x18,0x18,0x5C,0x5E,0x7E,0x7F,0x7F,0x47,0x00,0x00,  // Q
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x84,0x84,0x84,0xFC,0xFC,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x01,0x01,0x03,0x3F,0x3F,0x3C,0x00,0x00,0x00,  // R
0x00,0x00,0x00,0x78,0xFC,0xFC,0x84,0x84,0x84,0x84,0xBC,0x3C,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x3C,0x3D,0x21,0x21,0x21,0x21,0x3F,0x3F,0x1E,0x00,0x00,0x00,  // S
0x00,0x00,0x00,0x1C,0x0C,0x04,0x04,0xFC,0xFC,0xFC,0x04,0x04,0x0C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x3F,0x3F,0x20,0x20,0x00,0x00,0x00,0x00,  // T
0x00,0x00,0x00,0xFC,0xFC,0xFC,0x00,0x00,0x00,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x3F,0x20,0x20,0x20,0x3F,0x3F,0x1F,0x00,0x00,0x00,0x00,  // U
0x00,0x00,0x00,0xFC,0xFC,0xFC,0x00,0x00,0x00,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x1F,0x38,0x30,0x38,0x1F,0x0F,0x07,0x00,0x00,0x00,0x00,  // V
0x00,0x00,0x00,0xFC,0xFC,0xFC,0x00,0x00,0x80,0x00,0x00,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x3F,0x3C,0x3C,0x0F,0x3C,0x3C,0x3F,0x0F,0x03,0x00,0x00,  // W
0x00,0x00,0x00,0x1C,0x3C,0x7C,0xE0,0xC0,0xE0,0x7C,0x3C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x3C,0x3E,0x07,0x03,0x07,0x3E,0x3C,0x38,0x00,0x00,0x00,0x00,  // X
0x00,0x00,0x00,0x7C,0xFC,0xFC,0x80,0x00,0x80,0xFC,0xFC,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x21,0x3F,0x3F,0x3F,0x21,0x20,0x00,0x00,0x00,0x00,0x00,  // Y
0x00,0x00,0x00,0x3C,0x1C,0x0C,0x04,0x84,0xC4,0xE4,0x7C,0x3C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x3C,0x3E,0x27,0x23,0x21,0x20,0x30,0x38,0x3C,0x00,0x00,0x00,  // Z
0x00,0x00,0x00,0x00,0x00,0xFC,0xFC,0xFC,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0x00,  // [
0x00,0x00,0x00,0x1C,0x38,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0E,0x1C,0x18,0x30,0x20,0x20,  // <backslash>
0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x04,0x04,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x20,0x3F,0x3F,0x3F,0x00,0x00,0x00,0x00,  // ]
0x00,0x00,0x00,0x20,0x30,0x38,0x1C,0x0E,0x0E,0x1C,0x38,0x30,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ^
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,  // _

0x00,0x00,0x00,0x0C,0x0C,0x3C,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // `
0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x3E,0x3E,0x22,0x22,0x22,0x3F,0x1F,0x3F,0x20,0x00,0x00,0x00,  // a
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x40,0x40,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x1F,0x3F,0x20,0x20,0x20,0x3F,0x3F,0x1F,0x00,0x00,0x00,  // b
0x00,0x00,0x00,0x80,0xC0,0xC0,0x40,0x40,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x3F,0x20,0x20,0x20,0x39,0x39,0x19,0x00,0x00,0x00,0x00,  // c
0x00,0x00,0x00,0x80,0xC0,0xC0,0x40,0x40,0x44,0xFC,0xFC,0xFC,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x3F,0x20,0x20,0x20,0x3F,0x1F,0x3F,0x20,0x00,0x00,0x00,  // d
0x00,0x00,0x00,0x80,0xC0,0xC0,0x40,0x40,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x3F,0x22,0x22,0x22,0x3B,0x3B,0x1B,0x00,0x00,0x00,0x00,  // e
0x00,0x00,0x00,0x80,0x80,0xF8,0xFC,0xFC,0x84,0x9C,0x9C,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0x21,0x3F,0x3F,0x3F,0x21,0x21,0x01,0x00,0x00,0x00,0x00,0x00,  // f
0x00,0x00,0x00,0x80,0xC0,0xC0,0x40,0x40,0x40,0xC0,0x80,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x47,0xCF,0xDF,0x98,0x98,0x98,0xFF,0xFF,0x7F,0x00,0x00,0x00,0x00,  // g
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x80,0x40,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x01,0x00,0x00,0x3F,0x3F,0x3F,0x00,0x00,0x00,  // h
0x00,0x00,0x00,0x00,0x40,0x40,0x40,0xDC,0xDC,0xDC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x3F,0x3F,0x3F,0x20,0x20,0x20,0x00,0x00,0x00,  // i
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0xDC,0xDC,0xDC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x60,0xE0,0x80,0x80,0xC0,0xFF,0xFF,0x7F,0x00,0x00,0x00,0x00,  // j
0x00,0x00,0x00,0x04,0xFC,0xFC,0xFC,0x00,0x00,0x80,0xC0,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x02,0x07,0x0F,0x3D,0x38,0x30,0x00,0x00,0x00,  // k
0x00,0x00,0x00,0x00,0x04,0x04,0x04,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x3F,0x3F,0x3F,0x20,0x20,0x20,0x00,0x00,0x00,  // l
0x00,0x00,0x00,0xC0,0xC0,0xC0,0x40,0x40,0xC0,0x40,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x00,0x00,0x3F,0x00,0x00,0x3F,0x3F,0x3F,0x00,0x00,  // m
0x00,0x00,0x00,0xC0,0xC0,0xC0,0x40,0x40,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x00,0x00,0x00,0x00,  // n
0x00,0x00,0x00,0x80,0xC0,0xC0,0x40,0x40,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x3F,0x20,0x20,0x20,0x3F,0x3F,0x1F,0x00,0x00,0x00,0x00,  // o

0x00,0x00,0x00,0x40,0xC0,0x80,0xC0,0x40,0x40,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0xFF,0xFF,0x90,0x10,0x10,0x1F,0x1F,0x0F,0x00,0x00,0x00,  // p
0x00,0x00,0x80,0xC0,0xC0,0x40,0x40,0x40,0xC0,0x80,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x1F,0x10,0x10,0x90,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,  // q
0x00,0x00,0x00,0x40,0xC0,0xC0,0xC0,0x80,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x3F,0x3F,0x21,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,  // r
0x00,0x00,0x00,0x80,0xC0,0xC0,0x40,0x40,0x40,0x40,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x19,0x3B,0x23,0x26,0x26,0x26,0x3C,0x3D,0x19,0x00,0x00,0x00,0x00,  // s
0x00,0x00,0x00,0x40,0x40,0xE0,0xF0,0xF8,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x3F,0x20,0x38,0x38,0x18,0x00,0x00,0x00,0x00,  // t
0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,0x3F,0x20,0x20,0x20,0x3F,0x1F,0x3F,0x20,0x00,0x00,0x00,  // u
0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x1F,0x38,0x30,0x38,0x1F,0x0F,0x07,0x00,0x00,0x00,0x00,  // v
0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x3F,0x38,0x38,0x0E,0x38,0x38,0x3F,0x0F,0x07,0x00,0x00,  // w
0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x39,0x3F,0x0F,0x0F,0x3F,0x39,0x30,0x00,0x00,0x00,0x00,0x00,  // x
0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x87,0x8F,0x9F,0xD8,0xF8,0x78,0x3F,0x0F,0x07,0x00,0x00,0x00,  // y
0x00,0x00,0x00,0xC0,0xC0,0x40,0x40,0x40,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x38,0x3C,0x2E,0x27,0x23,0x31,0x38,0x00,0x00,0x00,0x00,0x00,  // z
0x00,0x00,0x00,0x80,0x80,0xC0,0x78,0x7C,0x3C,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x1E,0x3E,0x3C,0x20,0x20,0x20,0x20,0x00,0x00,0x00,  // {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,  // |
0x00,0x00,0x00,0x04,0x04,0x04,0x04,0x3C,0x7C,0x78,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x20,0x3C,0x3E,0x1E,0x03,0x01,0x01,0x00,0x00,0x00,  // }
0x00,0x00,0x38,0x3C,0x3C,0x04,0x0C,0x1C,0x38,0x30,0x20,0x3C,0x3C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // ~
};


const unsigned char barras[8] = {
    0b11000000,0x00,0b11110000,0x00,0b11111100,0x00,0b11111111,0x00
};

#define COLUMNAS    0x21
#define PAGINAS     0x22

void OLED_Init(void);
void OLED_NPut(char buffer);
void OLED_NPuts(char *buffer);
void OLED_SPut(unsigned int x,unsigned int y,char buffer);
void OLED_SPuts(unsigned int x,unsigned int y,char *buffer);
void OLED_Write(char dato);
static void ssd1306_command(unsigned char command);
void OLEDsetCursor(unsigned int x,unsigned int y);
void OLEDClear(void);