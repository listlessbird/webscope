/*
 * wave.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Rilg
 */

#ifndef INC_WAVE_H_
#define INC_WAVE_H_

float adcToVoltage(uint16_t samp);
float frontendVoltage(uint16_t samp);
void traceScreen();
void findTrigger();

#endif /* INC_WAVE_H_ */
