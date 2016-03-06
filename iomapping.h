
#ifndef IOMAPPING_H_
#define IOMAPPING_H_
//#define RST 8
//#define CHP 9
//#define LED 13
//#define SENSOR 0
/*
#define OUT0 8
#define OUT1 9
#define OUT2 10*/
#define OUT3 11
#define RST 12
#define CHP 13
#define SENSOR A3//A3 = 17;
#define LCD_SCL A5
#define LCD_SDA A4
const int KBD_DATA = 4; //DataPin
const int KBD_CLOCK = 3; //IRQpin
//#define M_RESET_PIN   10
//#define M_FLASH_PIN   11
#define CONSOLE Serial
#define CONSOLE_PARSER
#endif /* IOMAPPING_H_ */
