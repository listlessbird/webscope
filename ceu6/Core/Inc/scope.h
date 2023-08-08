/*
 * scope.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Rilg
 */

#ifndef INC_SCOPE_H_
#define INC_SCOPE_H_

#define PIXDIV 16
#define XDIV 8
#define YDIV 6

#define CLOCKTIM_PRESC 0
#define SYSCLK_FREQ 100000000
#define BUFFER_LEN (2 * PIXDIV * XDIV)

#define UPPER_VOLTAGE (atten * 3.3)
#define LOWER_VOLTAGE (atten * -3.3)

#define RISING 1
#define FALLING 0

void scopeInit();
void scopeLoop();
void sample();



#endif /* INC_SCOPE_H_ */
