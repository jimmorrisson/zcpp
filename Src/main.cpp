#include "main.h"
#include "usb_host.h"
extern "C"
{
#include "init.h"
}
#include "HD44780Driver.hpp"

#include <string>

void MX_USB_HOST_Process(void);

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(int argc, char *argv[])
{
    init_system();
    bsp::HD44780Driver hd44780Driver;
    hd44780Driver.lcd_init();
    hd44780Driver.lcd_write_cmd(0x80);
    hd44780Driver.lcd_write_data(0x3E);
    hd44780Driver.lcd_locate(1, 0);
    hd44780Driver.lcd_write_str(std::string("sinus"));
    hd44780Driver.lcd_locate(1, 1);
    hd44780Driver.lcd_write_str(std::string("prostokat"));
    while (1)
    {
        MX_USB_HOST_Process();
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1)
        {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
        }
        else
        {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
        }
    }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */

    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
