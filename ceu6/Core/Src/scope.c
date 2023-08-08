#include "main.h"
#include "scope.h"
#include "wave.h"
#include "stdint.h"
//HW handles

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim3;

uint16_t adcBuf[BUFFER_LEN];
volatile uint8_t finishedConversion = 0;

int atten = 1;
float vdiv =2 ; //volts per div

uint8_t trigged;       // whether or not we're triggered
int trigPoint;         // triggering point
float trigVoltage = 0; // Trigger level
uint8_t trig = RISING; // Trigger slope

float tdiv = 20;   // uS per division
uint32_t sampRate; // Sample rate
float sampPer;     // Sample period in uS (how long it takes to measure one sample)

float maxVoltage, minVoltage; // Voltage measurements
float measuredFreq, sigPer;   // Time measurements

float offsetVoltage = 1.6540283; // Reference voltage of the the analog frontend

extern UART_HandleTypeDef huart1;
uint8_t uartBuf[15];

void scopeInit() {

 //set sampling rate
	sampRate = (16000 * 1000) / tdiv;
	sampPer = tdiv / 16.0;
	setTimerFreq(sampRate);

//	Init the UART
	HAL_UART_Receive_IT(&huart1, uartBuf, 1);

}

void sample() {
	HAL_TIM_Base_Start(&htim3);
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *) adcBuf, BUFFER_LEN);
	while(!finishedConversion);
	HAL_TIM_Base_Stop(&htim3);
	finishedConversion = 0;
}

void scopeLoop() {
     sample();
}

void setTimerFreq(uint32_t freq) {

	uint16_t arr = (SYSCLK_FREQ/ ((CLOCKTIM_PRESC + 1) * freq)) - 1;

	htim3.Instance->ARR = arr;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	finishedConversion = 1;
}

void HAL_UART_RxCpltCallbac(UART_HandleTypeDef *huart) {
    extern uint8_t outputFlag, fast;

	if(uartBuf[0] == 's')
        outputFlag = 2;
	else if (uartBuf[0] == 'S') {
        outputFlag = 4;
		fast = 0;
    }
	 else if (uartBuf[0] == 'F') {
        outputFlag = 4;
        fast = 1;
    }
    HAL_UART_Receive_IT(&huart1, uartBuf, 1);
}