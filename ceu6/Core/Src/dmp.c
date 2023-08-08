#include "main.h" 
#include "scope.h"
#include "wave.h"

extern uint16_t adcBuf[BUFFER_LEN];
extern int atten;
extern float vdiv;
extern float trigVoltage;
extern uint8_t trig;
extern uint8_t trigged;
extern int trigPoint;

extern float tdiv;
extern uint32_t sampRate;
extern float sampPer;

extern float maxVoltage, minVoltage;
extern float measuredFreq, sigPer;

volatile uint8_t outputFlag = 0;
extern UART_HandleTypeDef huart1;

uint8_t autocalFlag = 0;
extern float offsetVoltage;

uint8_t fast = 1;

void outputSerial(char s[], uint8_t o) {
	switch (o) {
	case 1:
		HAL_Delay(1);
		break;
	case 2:
		HAL_UART_Transmit(&huart1, s, strlen(s), HAL_MAX_DELAY);
		break;
	default:
		break;
	}
}

void outputCSV(uint8_t o) {
	char st[10];
	char s1[10];
	uint8_t buffer[30] = "";

	sprintf(buffer, "\033[2J\033[H\033[3J");
	outputSerial(buffer, o);

	sprintf(buffer, "Model,TekscopeSW\n\r");
	outputSerial(buffer, o);

	sprintf(buffer, "Label,CH1\n\r");
	outputSerial(buffer, o);

	sprintf(buffer, "Waveform Type,ANALOG\n\r");
	outputSerial(buffer, o);

	sprintf(buffer, "Horizontal Units,s\n\r");
	outputSerial(buffer, o);

	sprintf(buffer, "Sample Interval,%sE-06\n\r", st);
	outputSerial(buffer, o);

	sprintf(buffer, "Record Length,%d\n\r", BUFFER_LEN);
	outputSerial(buffer, o);

	sprintf(buffer, "Zero Index,%d\n\r", trigPoint);
	outputSerial(buffer, o);
	HAL_Delay(5);

	sprintf(buffer, "Vertical Units,V\n\r");
	outputSerial(buffer, o);

	sprintf(buffer, ",\n\rLabels,\n\r");
	outputSerial(buffer, o);

	sprintf(buffer, "TIME,CH1\n\r");
	outputSerial(buffer, o);

	for (int i = 0; i < BUFFER_LEN; i++) {
		float voltage = atten * frontendVoltage(adcBuf[i]);
		sprintf(buffer, "%sE-06,%s\n\r", s1, st);
		outputSerial(buffer, o);
	}
}

void outputTek(uint8_t o) {
	char st[10];
	uint8_t buffer[30] = "";

	// transmission begin marker
	sprintf(buffer, "BeginWave!\n\r");
	outputSerial(buffer, o);

	// sample period

	sprintf(buffer, "%s\n\r", st);
	outputSerial(buffer, o);

	// number of samples
	if (fast)
		sprintf(buffer, "%d\n\r", BUFFER_LEN / 2);
	else
		sprintf(buffer, "%d\n\r", BUFFER_LEN);
	outputSerial(buffer, o);

	// trigger point in buffer
	if (fast)
		sprintf(buffer, "%d\n\r", 0);
	else
		sprintf(buffer, "%d\n\r", trigPoint);
	outputSerial(buffer, o);

	// frontend offset voltage

	sprintf(buffer, "%s\n\r", st);
	outputSerial(buffer, o);

	// attenuation factor of the probe
	sprintf(buffer, "%d\n\r", atten);
	outputSerial(buffer, o);
	HAL_Delay(1);

	// ADC samples
	if (fast)
		for (int i = 0; i < BUFFER_LEN / 2; i++) {
			sprintf(buffer, "%d\n\r", adcBuf[i + trigPoint]);
			outputSerial(buffer, o);
		}
	else
		for (int i = 0; i < BUFFER_LEN; i++) {
			sprintf(buffer, "%d\n\r", adcBuf[i]);
			outputSerial(buffer, o);
		}
	// transmission end marker
	sprintf(buffer, "SendWaveComplete!\n\r");
	outputSerial(buffer, o);
	sprintf(buffer, "\n\r");
	outputSerial(buffer, o);
}
