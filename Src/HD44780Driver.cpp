//#include "HD44780Driver.hpp"
//
//constexpr void LCD_E_HIGH() {
//    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
//}
//constexpr void LCD_E_LOW() {
//    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
//}
//constexpr void LCD_RS_HIGH() {
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
//}
//constexpr LCD_RS_LOW() {
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
//}
//#define LCD_D4_PORT GPIOB
//#define LCD_D4_PIN GPIO_PIN_13
//#define LCD_D5_PORT GPIOD
//#define LCD_D5_PIN GPIO_PIN_2
//#define LCD_D6_PORT GPIOC
//#define LCD_D6_PIN GPIO_PIN_2
//#define LCD_D7_PORT GPIOC
//#define LCD_D7_PIN GPIO_PIN_3
//
//#define LCD_CLEAR					0x01
//#define LCD_HOME					0x02
//#define LCDC_ENTRY_MODE				0x04
//	#define LCD_EM_SHIFT_CURSOR		    0x00
//	#define LCD_EM_SHIFT_DISPLAY	 	0x01
//	#define LCD_EM_LEFT		   			0x00
//	#define LCD_EM_RIGHT				0x02
//#define LCD_ONOFF					0x08
//	#define LCD_DISP_ON				    0x04
//	#define LCD_CURSOR_ON				0x02
//	#define LCDC_CURSOR_OFF				0x00
//	#define LCDC_BLINK_ON				0x01
//	#define LCDC_BLINK_OFF				0x00
//#define LCD_SHIFT					0x10
//	#define LCDC_SHIFT_DISP				0x08
//	#define LCDC_SHIFT_CURSOR			0x00
//	#define LCDC_SHIFT_RIGHT			0x04
//	#define LCDC_SHIFT_LEFT				0x00
//#define LCD_FUNC					0x20
//	#define LCD_8_BIT					0x10
//	#define LCD_4_BIT					0x00
//	#define LCDC_TWO_LINE				0x08
//	#define LCDC_FONT_5x10				0x04
//	#define LCDC_FONT_5x7				0x00
//#define LCDC_SET_CGRAM				0x40
//#define LCDC_SET_DDRAM				0x80
//
//#define LCD_CLEAR					0x01
//#define LCD_HOME					0x02
//#define LCDC_ENTRY_MODE				0x04
//	#define LCD_EM_SHIFT_CURSOR		    0x00
//	#define LCD_EM_SHIFT_DISPLAY	 	0x01
//	#define LCD_EM_LEFT		   			0x00
//	#define LCD_EM_RIGHT				0x02
//#define LCD_ONOFF					0x08
//	#define LCD_DISP_ON				    0x04
//	#define LCD_CURSOR_ON				0x02
//	#define LCDC_CURSOR_OFF				0x00
//	#define LCDC_BLINK_ON				0x01
//	#define LCDC_BLINK_OFF				0x00
//#define LCD_SHIFT					0x10
//	#define LCDC_SHIFT_DISP				0x08
//	#define LCDC_SHIFT_CURSOR			0x00
//	#define LCDC_SHIFT_RIGHT			0x04
//	#define LCDC_SHIFT_LEFT				0x00
//#define LCD_FUNC					0x20
//	#define LCD_8_BIT					0x10
//	#define LCD_4_BIT					0x00
//	#define LCDC_TWO_LINE				0x08
//	#define LCDC_FONT_5x10				0x04
//	#define LCDC_FONT_5x7				0x00
//#define LCDC_SET_CGRAM				0x40
//#define LCDC_SET_DDRAM				0x80
//
//#define LCD_LINE1 		0x00
//#define LCD_LINE2 		0x40
//
//void HD44780Driver::lcd_send_byte(uint8_t data)
//{
//	lcd_send_half_byte(data >> 4);
//	lcd_send_half_byte(data);
//
//	HAL_Delay(20);
//}
//
//void HD44780Driver::lcd_send_half_byte(uint8_t data)
//{
//	LCD_E_HIGH();
//	HAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (data & 0x01));
//	HAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (data & 0x02));
//	HAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (data & 0x04));
//	HAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (data & 0x08));
//	LCD_E_LOW();
//}
//
//// static void HD44780Driver::lcd_init()
//// {
//// 	LCD_E_LOW();
//// 	LCD_RS_LOW();
//
//// 	lcd_send_half_byte(0x03);
//// 	HAL_Delay(4);
//// 	HAL_Delay(100);
//// 	lcd_send_half_byte(0x03);
//// 	HAL_Delay(100);
//// 	lcd_send_half_byte(0x03);
//// 	HAL_Delay(100);
//// 	lcd_send_half_byte(0x02);
//// 	HAL_Delay(100);
//
//// 	// Już jesteśmy w trybie 4-bitowym. Tutaj dokonujemy ustawień wyświetlacza:
//// 	lcd_write_cmd( LCD_FUNC | LCD_4_BIT | LCDC_TWO_LINE | LCDC_FONT_5x7);
//// 	lcd_write_cmd( LCD_ONOFF | LCD_DISP_ON );
//// 	lcd_write_cmd( LCD_CLEAR );
//// 	HAL_Delay(5);
//// 	lcd_write_cmd( LCDC_ENTRY_MODE | LCD_EM_SHIFT_CURSOR | LCD_EM_RIGHT );
//// }
//
//void HD44780Driver::lcd_write_cmd(uint8_t cmd)
//{
//	LCD_RS_LOW();
//	lcd_send_byte(cmd);
//}
//
//void HD44780Driver::lcd_write_data(uint8_t data)
//{
//	LCD_RS_HIGH();
//	lcd_send_byte(data);
//}
//
//void HD44780Driver::lcd_write_str(const char *text)
//{
//	while(*text != '\0')
//	{
//		lcd_write_data(*text++);
//	}
//}