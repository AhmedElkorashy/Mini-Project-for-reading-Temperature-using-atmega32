/*
 * main.c
 *
 *  Created on: Mar 26, 2024
 *      Author: User
 */

#include "STD_TYPES.h"
#include "LCD_Interface.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "EXTI_Interface.h"
#include "DCMOTOR_Interface.h"
#include <util/delay.h>
#include "GIE_Interface.h"
#include "LM35_Interface.h"


void ROOM_1()
{
	u8 Local_u8TempValue;
	LCD_voidClearScreen();
	LCD_voidSendString((u8*)"Welcome to Room1");
	LCD_voidSetPosition(1,0);
	LCD_voidSendString((u8*)"Temperature: ");
	Local_u8TempValue =LM35_u16GetTempReading(CHANNEL0);
	if(Local_u8TempValue<10)
	{
		LCD_voidSetPosition(1,12);
		LCD_voidSendString((u8*)" ");
		LCD_voidSendNumber(Local_u8TempValue);
		_delay_ms(3000);

	}
	else
	{
		LCD_voidSetPosition(1,12);
		LCD_voidSendNumber(Local_u8TempValue);
		_delay_ms(3000);
	}
}
void ROOM_2()
{
	GIE_voidEnable();
	u8 Local_u8TempValue;
	LCD_voidClearScreen();
	LCD_voidSendString((u8*)"Welcome to Room2");
	LCD_voidSetPosition(1,0);
	LCD_voidSendString((u8*)"Temperature: ");
	Local_u8TempValue =LM35_u16GetTempReading(CHANNEL4);
	if(Local_u8TempValue<10)
	{
		LCD_voidSetPosition(1,12);
		LCD_voidSendString((u8*)" ");
		LCD_voidSendNumber(Local_u8TempValue);
		_delay_ms(3000);
	}
	else
	{
		LCD_voidSetPosition(1,12);
		LCD_voidSendNumber(Local_u8TempValue);
		_delay_ms(3000);
	}
}
int main()
{

	LCD_voidInit();
	ADC_voidInit();
	EXTI_voidInit();
	MOTOR_voidInit();
	LM35_voidInit();
	GIE_voidEnable();
	LCD_voidSendString((u8*)" Welcome to MP5!");
	_delay_ms(3000);
	LCD_voidClearScreen();
	EXTI_u8Int1SetCallBack(ROOM_1);
	EXTI_u8Int2SetCallBack(ROOM_2);
	while(1)
	{
		MOTOR_voidCounterClockWise();
		LCD_voidClearScreen();
		LCD_voidSendString((u8*)"Motor CCW");
		_delay_ms(3000);
		MOTOR_voidClockWise();
		LCD_voidClearScreen();
		LCD_voidSendString((u8*)"Motor CW");
		_delay_ms(3000);
	}

}
