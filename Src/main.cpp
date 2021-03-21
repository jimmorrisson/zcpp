#include "main.h"
#include "usb_host.h"
extern "C"
{
#include "init.h"
}
#include "HD44780Driver.hpp"
#include "Button.hpp"
#include <string>
// #include "SystemManager.hpp"

void MX_USB_HOST_Process(void);

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(int argc, char *argv[])
{
    init_system();
    // SystemManager systemManager;
    bsp::HD44780Driver hd44780Driver;
    hd44780Driver.lcd_init();
    hd44780Driver.lcd_write_cmd(0x80);
    hd44780Driver.lcd_write_data(0x3E);
    hd44780Driver.lcd_locate(1, 0);
    hd44780Driver.lcd_write_str(std::string("sinus"));
    hd44780Driver.lcd_locate(1, 1);
    hd44780Driver.lcd_write_str(std::string("prostokat"));
    // bsp::Button button{systemManager};
    while (1)
    {
        hd44780Driver.lcd_clear();
        MX_USB_HOST_Process();
        const auto btnState = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
        // button.setState(btnState);
        // auto [first, second] = button.getSingal();
        hd44780Driver.lcd_locate(1, 0);
        // hd44780Driver.lcd_write_str(std::move(first));
        hd44780Driver.lcd_locate(1, 1);
        // hd44780Driver.lcd_write_str(std::move(second));
        // systemManager.handleSignalChanged(1);


        //        if ( == 1 && previousState == 0)
        //        {
        //            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, set ?GPIO_PIN_SET : GPIO_PIN_RESET);
        //            set = !set;
        //            previousState = 1;
        //        }
        //        else
        //        {
        //            previousState = 0;
        //        }
        HAL_Delay(1000);
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
