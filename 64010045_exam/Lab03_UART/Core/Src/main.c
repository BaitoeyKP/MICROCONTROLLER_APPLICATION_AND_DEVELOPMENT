/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//1
//char str[] = "Hello, World!!\n\r";

//2
//char ch1 = 'A';

//3
//char str[] = "\r\nInput => ";
//char ch1;
//char quit[] = "\r\nQUIT";

//4
char ch1;
char instruction[] = "Display Blinking LED PRESS (1, 2)\n\rDisplay Group Members PRESS m\n\rQuit PRESS q";
char str[] = "\r\n\tInput => ";
char name[] = "\r\n64010045\n\rKanyarat Phookosot\n\r64010248\n\rNattapon Boondang\n\r64010635\n\rPhaithun Thomisrisuk";
char quit[] = "\r\nQUIT";
char unknown[] = "\r\nUnknown Command";
uint8_t i;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
//  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
//  HAL_UART_Transmit(&huart3, (uint8_t*) instruction, strlen(instruction),1000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
//	  1
//	  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
//	  HAL_UART_Transmit(&huart3, (uint8_t*) str, strlen(str),1000);
//	  HAL_Delay(300);

	  //2
//	  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
//	  HAL_UART_Transmit(&huart3, (uint8_t*) &ch1, 1,1000);
//	  HAL_Delay(300);

	  //3
//	  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
//	  HAL_UART_Transmit(&huart3, (uint8_t*) str, strlen(str),1000);
//	  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_RXNE)== RESET){}
//	  HAL_UART_Receive(&huart3, (uint8_t*) &ch1, 1, 1000);
//	  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
//	  HAL_UART_Transmit(&huart3, (uint8_t*) &ch1, 1,1000);
//	  if (ch1 == 'q'){
//		  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
//		  HAL_UART_Transmit(&huart3, (uint8_t*) quit, strlen(quit),1000);
//		  break;
//	  }
//	  HAL_Delay(300);

	  //4
	  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
	  HAL_UART_Transmit(&huart3, (uint8_t*) str, strlen(str),1000);
	  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_RXNE)== RESET){}
	  HAL_UART_Receive(&huart3, (uint8_t*) &ch1, 1, 1000);
	  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
	  HAL_UART_Transmit(&huart3, (uint8_t*) &ch1, 1,1000);
	  if (ch1 == '1'){
		  for (i = 0; i < 3; i++){
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			  HAL_Delay(300);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
			  HAL_Delay(300);
		  }
	  }
	  else if(ch1 == '2'){
		  for (i = 0; i < 3; i++){
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
			  HAL_Delay(300);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
			  HAL_Delay(300);
		  }
	  }
	  else if(ch1 == 'm'){
		  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
		  HAL_UART_Transmit(&huart3, (uint8_t*) name, strlen(name),1000);
	  }
	  else if(ch1 == 'q'){
		  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
		  HAL_UART_Transmit(&huart3, (uint8_t*) quit, strlen(quit),1000);
		  break;
	  }
	  else{
		  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
		  HAL_UART_Transmit(&huart3, (uint8_t*) unknown, strlen(unknown),1000);
	  }
	  HAL_Delay(300);


    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
