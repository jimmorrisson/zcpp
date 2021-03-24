#include "main.h"

extern "C"
{
#include "init.h"
#include "CS43L22.h"
}
#include "AudioPlayer.hpp"
#include "Button.hpp"
#include "Display.hpp"
#include "SystemManager.hpp"

I2C_HandleTypeDef hi2c1;
I2S_HandleTypeDef hi2s3;
DMA_HandleTypeDef hdma_spi3_tx;

int main([[maybe_unused]]int argc, [[maybe_unused]]char* argv[])
{
  init_system();
  sys::SystemManager systemManager;
  Display display{systemManager};
  constexpr std::size_t size = 100;
  audio::AudioPlayer<size> audioPlayer{systemManager};
  bsp::Button button;
  while (1)
  {
    const auto btnState = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
    button.setState(btnState);
    const auto btnSignal = button.getSingal();
    const auto state = sys::SystemManager::translateButtonState(btnSignal);
    systemManager.handleSignalChanged(state);
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
