/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : app_freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId myTask01Handle;
osThreadId myTask02Handle;
osMessageQId myQueue01Handle;
osSemaphoreId myBinarySem01Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartTask01(void const * argument);
void StartTask02(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of myBinarySem01 */
  osSemaphoreDef(myBinarySem01);
  myBinarySem01Handle = osSemaphoreCreate(osSemaphore(myBinarySem01), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of myQueue01 */
  osMessageQDef(myQueue01, 16, uint8_t);
  myQueue01Handle = osMessageCreate(osMessageQ(myQueue01), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of myTask01 */
  osThreadDef(myTask01, StartTask01, osPriorityNormal, 0, 128);
  myTask01Handle = osThreadCreate(osThread(myTask01), NULL);

  /* definition and creation of myTask02 */
  osThreadDef(myTask02, StartTask02, osPriorityNormal, 0, 128);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartTask01 */
/**
 * @brief Function implementing the myTask01 thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartTask01 */
void StartTask01(void const * argument)
{
  /* USER CODE BEGIN StartTask01 */
//	uint32_t wakeuptime;
	//osPriority priority;
	/* Infinite loop */
	for(;;)
	{
		osDelay(2000);
		printf("Task 1 Release semaphore \r\n");
		osSemaphoreRelease(myBinarySem01Handle);

//		printf("Task 1 \r\n");
//		HAL_Delay(50);
//		osMessagePut(myQueue01Handle, (uint8_t)0x32, 200);
//		printf("Task 1 delay \r\n");
//		HAL_Delay(80);
//		osDelay(1000);

//		printf("Create task 2 \r\n");
//		osThreadDef(myTask02, StartTask02, osPriorityNormal, 0, 128);
//		myTask02Handle = osThreadCreate(osThread(myTask02), NULL);
//		osDelay(1000);

//		wakeuptime = osKernelSysTick();
//		priority = osThreadGetPriority(myTask02Handle);
//		printf("My Task 1 \r\n");
//		osThreadSetPriority(myTask02Handle, priority + 1);
//		HAL_Delay(1000);
//		osDelayUntil(&wakeuptime, 2000);
	}
  /* USER CODE END StartTask01 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
 * @brief Function implementing the myTask02 thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
	//osPriority priority;
//	osEvent retvalue;

	/* Infinite loop */
	for(;;)
	{
		osSemaphoreWait(myBinarySem01Handle, 4000);
		printf("Task 2 Synchronized \r\n");

//		printf("Task 2 \r\n");
//		HAL_Delay(50);
//		retvalue = osMessageGet(myQueue01Handle, 4000);
//		printf("%c \r\n", (int)retvalue.value.v);
//		HAL_Delay(50);

//		printf("Delete task 2 \r\n");
//		osThreadTerminate(myTask02Handle);

		// Read priority off current task
//		priority = osThreadGetPriority(NULL);
//		printf("My Task 2 \r\n");
//		osThreadSetPriority(NULL, priority - 2);
	}
  /* USER CODE END StartTask02 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

