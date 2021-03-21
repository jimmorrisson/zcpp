//#include "main.h"
//#include <math.h>
//
//extern "C"
//{
//#include "init.h"
//#include "CS43L22.h"
//}
//#include "HD44780Driver.hpp"
//#include "Button.hpp"
//#include "SystemManager.hpp"
//#define PI 3.14159f
//
////Sample rate and Output freq
//#define F_SAMPLE		48000.0f
//#define F_OUT				1500.0f
///* USER CODE END PV */
//float mySinVal;
//float sample_dt;
//uint16_t sample_N;
//uint16_t i_t;
//
//uint32_t myDacVal;
//
//int16_t dataI2S[100];
//void MX_USB_HOST_Process(void);
//
///**
//  * @brief  The application entry point.
//  * @retval int
//  */
//int main([[maybe_unused]]int argc, [[maybe_unused]]char *argv[])
//{
//    init_system();
//    CS43_Init(hi2c1, MODE_I2S);
//	CS43_SetVolume(40); //0 - 100,, 40
//	CS43_Enable_RightLeft(CS43_RIGHT_LEFT);
//	CS43_Start();
//
//	//Build Sine wave
//	for(uint16_t i=0; i<sample_N; i++)
//	{
//		mySinVal = sinf(i*2*PI*sample_dt);
//		dataI2S[i*2] = (mySinVal )*8000;    //Right data (0 2 4 6 8 10 12)
//		dataI2S[i*2 + 1] =(mySinVal )*8000; //Left data  (1 3 5 7 9 11 13)
//	}
//
//	HAL_I2S_Transmit_DMA(&hi2s3, (uint16_t *)dataI2S, sample_N*2);
//
//    SystemManager systemManager;
//    bsp::HD44780Driver hd44780Driver{systemManager};
//    hd44780Driver.lcd_init();
//    hd44780Driver.lcd_write_cmd(0x80);
//    hd44780Driver.lcd_write_data(0x3E);
//    bsp::Button button;
//    while (1)
//    {
//        const auto btnState = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
//        button.setState(btnState);
//        const auto btnSignal = button.getSingal();
//        const auto state = SystemManager::translateButtonState(btnSignal);
//        systemManager.handleSignalChanged(state);
//    }
//}
//
///**
//  * @brief  This function is executed in case of error occurrence.
//  * @retval None
//  */
//void Error_Handler(void)
//{
//    /* USER CODE BEGIN Error_Handler_Debug */
//    /* User can add his own implementation to report the HAL error return state */
//
//    /* USER CODE END Error_Handler_Debug */
//}
//
//#ifdef USE_FULL_ASSERT
///**
//  * @brief  Reports the name of the source file and the source line number
//  *         where the assert_param error has occurred.
//  * @param  file: pointer to the source file name
//  * @param  line: assert_param error line source number
//  * @retval None
//  */
//void assert_failed(uint8_t *file, uint32_t line)
//{
//    /* USER CODE BEGIN 6 */
//    /* User can add his own implementation to report the file name and line number,
//     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//    /* USER CODE END 6 */
//}
//#endif /* USE_FULL_ASSERT */
