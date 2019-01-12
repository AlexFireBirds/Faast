#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "LcdDriver.h"

// Define some device parameters
#define I2C_ADDR   0x27 // I2C device address

// Define some device constants
#define LCD_CHR  1 // Mode - Sending data
#define LCD_CMD  0 // Mode - Sending command

#define LINE1  0x80 // 1st line
#define LINE2  0xC0 // 2nd line

#define LCD_BACKLIGHT   0x08  // On
// LCD_BACKLIGHT = 0x00  # Off

#define ENABLE  0b00000100 // Enable bit

void lcd_init(void);
void lcd_byte(int bits, int mode);
void lcd_toggle_enable(int bits);

// added by Lewis
void typeInt(int i);
void lcdLoc(int line); //move cursor
void typeln(const char *s);
void typeChar(char val);
int _fd;  // seen by all subroutines


static void SetCursorToRow(int row)
{
	lcd_byte(row, LCD_CMD);
}

void LcdDriver_Initialize(void)
{
	bool successful = true;

	_fd = wiringPiI2CSetup(I2C_ADDR);

	delay(500);

	lcd_init();

	if(successful)
	{
		puts("LcdDriver_Initialize successful\n");
	}
	else
	{
		puts("LcdDriver_Initialize failed\n");
	}
}

int LcdDriver_Test(void)
{
  char array1[] = "Hello world!";

  while (1)
  {

    lcdLoc(LINE1);
    typeln("Using wiringPi");
    lcdLoc(LINE2);
    typeln("Geany editor.");

    delay(2000);
    LcdDriver_Clear();
    lcdLoc(LINE1);
    typeln("I2c  Programmed");
    lcdLoc(LINE2);
    typeln("in C not Python.");

    delay(2000);
    LcdDriver_Clear();
    lcdLoc(LINE1);
    typeln("Arduino like");
    lcdLoc(LINE2);
    typeln("fast and easy.");

    delay(2000);
    LcdDriver_Clear();
    lcdLoc(LINE1);
    typeln(array1);

    delay(2000);
    LcdDriver_Clear(); // defaults LINE1
    typeln("Int  ");
    int value = 20125;
    typeInt(value);

    delay(2000);
  }

  return 0;

}

// int to string
void typeInt(int i)   {
  char array1[20];
  sprintf(array1, "%d",  i);
  typeln(array1);
}

// Clear lcd and set cursor to home position
void LcdDriver_Clear(void)
{
  lcd_byte(0x01, LCD_CMD);
  lcd_byte(0x02, LCD_CMD);
}

// go to location on LCD
void lcdLoc(int line)   {
  lcd_byte(line, LCD_CMD);
}

// out char to LCD at current position
void typeChar(char val)   {

  lcd_byte(val, LCD_CHR);
}


// this allows use of any size string
void typeln(const char *s)   {

  while ( *s ) lcd_byte(*(s++), LCD_CHR);

}

void LcdDriver_Write(const char *s)
{
	int stringSize = 0;
	int numberOfCharactersWrote = 0;

	LcdDriver_Clear();

	stringSize = sizeof(*s)/sizeof(char);

	SetCursorToRow(LINE1);


	while ( *s )
	{
		lcd_byte(*(s++), LCD_CHR);
		numberOfCharactersWrote++;

		if(numberOfCharactersWrote == 16)
		{
			break;
		}

	}

    SetCursorToRow(LINE2);
	while ( *s )
	{
		lcd_byte(*(s++), LCD_CHR);
	}

}

void lcd_byte(int bits, int mode)   {

  //Send byte to data pins
  // bits = the data
  // mode = 1 for data, 0 for command
  int bits_high;
  int bits_low;
  // uses the two half byte writes to LCD
  bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT ;
  bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT ;

  // High bits
  wiringPiI2CReadReg8(_fd, bits_high);
  lcd_toggle_enable(bits_high);

  // Low bits
  wiringPiI2CReadReg8(_fd, bits_low);
  lcd_toggle_enable(bits_low);
}

void lcd_toggle_enable(int bits)   {
  // Toggle enable pin on LCD display
  delayMicroseconds(500);
  wiringPiI2CReadReg8(_fd, (bits | ENABLE));
  delayMicroseconds(500);
  wiringPiI2CReadReg8(_fd, (bits & ~ENABLE));
  delayMicroseconds(500);
}


void lcd_init()   {
  // Initialise display
  lcd_byte(0x33, LCD_CMD); // Initialise
  lcd_byte(0x32, LCD_CMD); // Initialise
  lcd_byte(0x06, LCD_CMD); // Cursor move direction
  lcd_byte(0x0C, LCD_CMD); // 0x0F On, Blink Off
  lcd_byte(0x28, LCD_CMD); // Data length, number of lines, font size
  lcd_byte(0x01, LCD_CMD); // Clear display
  delayMicroseconds(500);
}
