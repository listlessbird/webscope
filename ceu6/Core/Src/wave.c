#include "main.h"
#include "scope.h"
#include "wave.h"
#include "stdint.h"


extern uint16_t adcBuf[BUFFER_LEN];
extern int atten;
extern float vdiv;
extern float trigVoltage;
extern uint8_t trig, trigged;
extern int trigPoint;

extern float tdiv;
extern uint32_t sampRate;
extern float sampPer;

extern float maxVoltage, minVoltage;
extern float measuredFreq, sigPer;

extern float offsetVoltage;

uint8_t topClip, bottomClip;

float adcToVoltage(uint16_t samp) {
    return (samp * 3.3) / 4096.0 ;
}