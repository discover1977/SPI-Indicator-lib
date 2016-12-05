/*
 * SPI_Indicator.h
 *
 *  Created on: 4 дек. 2016 г.
 *      Author: gavrilov.iv
 */

#ifndef SPI_INDICATOR_H_
#define SPI_INDICATOR_H_

#include <avr/io.h>
#include "compilers_4.h"
#include <stdlib.h>
#include <stdint.h>

#define IND_AMOUNT		5

/* настройки SPI порта*/
#define SPI_PORT			PORTB
#define SPI_DDR				DDRB
#define SPI_MOSI			3
#define SPI_MISO			4
#define SPI_SCK				5
#define SPI_CS				2

#define SEG_A 	6
#define SEG_B 	7
#define SEG_C 	1
#define SEG_D 	2
#define SEG_E 	3
#define SEG_F 	5
#define SEG_G 	4
#define SEG_H 	0

#define SYMBOL_BLANK	0x00
#define EMPTY_NUM 		10

void IND_Init();
void IND_OutSym(char *str, int8_t pos);
void IND_OutInt(int16_t value, uint8_t comma, uint8_t position, uint8_t amount);
void IND_Clear();

// Битовые макросы
#define SUFIX	UL
#define Bit(bit)  (1<<(bit))

#define ClearBit(reg, bit)       reg &= (~(1UL<<(bit)))
//пример: ClearBit(PORTB, 1); //сбросить 1-й бит PORTB

#define SetBit(reg, bit)          reg |= (1UL<<(bit))
//пример: SetBit(PORTB, 3); //установить 3-й бит PORTB

#define SetBitVal(reg, bit, val) do{if ((val&1)==0) reg &= (~(1<<(bit)));\
                                  else reg |= (1<<(bit));}while(0)
//пример: SetBitVal(PORTB, 3, 1); //установить 3-й бит PORTB
//	  SetBitVal(PORTB, 2, 0); //сбросить 2-й бит PORTB

#define BitIsClear(reg, bit)    ((reg & (1<<(bit))) == 0)
//пример: if (BitIsClear(PORTB,1)) {...} //если бит очищен

#define BitIsSet(reg, bit)       ((reg & (1<<(bit))) != 0)
//пример: if(BitIsSet(PORTB,2)) {...} //если бит установлен

#define InvBit(reg, bit)	  reg ^= (1<<(bit))
//пример: InvBit(PORTB, 1); //инвертировать 1-й бит PORTB

#endif /* SPI_INDICATOR_H_ */
