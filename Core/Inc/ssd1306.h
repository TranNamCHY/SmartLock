#ifndef SSD1306_H
#define SSD1306_H 100

/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

#include "fonts.h"
#include "stm32f1xx_hal.h"
#include "stdlib.h"
#include "string.h"


/* I2C address */
#ifndef SSD1306_I2C_ADDR
#define SSD1306_I2C_ADDR         0x78
//#define SSD1306_I2C_ADDR       0x7A
#endif

/* SSD1306 settings */
/* SSD1306 width in pixels */
#ifndef SSD1306_WIDTH
#define SSD1306_WIDTH            128
#endif
/* SSD1306 LCD height in pixels */
#ifndef SSD1306_HEIGHT
#define SSD1306_HEIGHT           64
#endif

/**
 * @brief  SSD1306 color enumeration
 */
typedef enum {
	SSD1306_COLOR_BLACK = 0x00, /*!< Black color, no pixel */
	SSD1306_COLOR_WHITE = 0x01  /*!< Pixel is set. Color depends on LCD */
} SSD1306_COLOR_t;

uint8_t SSD1306_Init(void);

void SSD1306_UpdateScreen(void);

void SSD1306_Fill(SSD1306_COLOR_t Color);

void SSD1306_DrawPixel(uint16_t x, uint16_t y, SSD1306_COLOR_t color);

void SSD1306_GotoXY(uint16_t x, uint16_t y);

char SSD1306_Putc(char ch, FontDef_t* Font, SSD1306_COLOR_t color);

char SSD1306_Puts(char* str, FontDef_t* Font, SSD1306_COLOR_t color);

#ifndef ssd1306_I2C_TIMEOUT
#define ssd1306_I2C_TIMEOUT					20000
#endif

void ssd1306_I2C_Init();

void ssd1306_I2C_Write(uint8_t address, uint8_t reg, uint8_t data);

void ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t *data, uint16_t count);

void SSD1306_DrawBitmap(int16_t x, int16_t y, const unsigned char* bitmap, int16_t w, int16_t h, uint16_t color);

// clear the display

void SSD1306_Clear (void);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif