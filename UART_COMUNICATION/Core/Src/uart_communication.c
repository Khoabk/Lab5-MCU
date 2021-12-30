/*
 * uart_communication.c
 *
 *  Created on: Dec 10, 2021
 *      Author: dang khoa
 */

#include "uart_communication.h"

#include "command_parser.h"

#include "timer.h"
#include "main.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


uint32_t adc_val = 0;

uint8_t state2 = 0;

void uart_communication_fsm()
{

	switch(state2)
	{


	case 0:
	{
	 	if(send_signal)
		{
			state2 = 1;
		}
		
		
		break;
	}
	case 1:
	{

		if(receive_signal)
		{

			char * str = "\rTransmission completes\r";

			HAL_UART_Transmit(&huart1,(uint8_t*)str,strlen(str),1000);

			send_signal = 0;

			receive_signal = 0;

			disable_timer();

			state2 = 0;

			break;

		}


		if(send_signal)
		{
			HAL_UART_Transmit(&huart1,(uint8_t*)"\r!ADC=",6,1000);

			char *str = "0";

			HAL_UART_Transmit(&huart1,(uint8_t*)str, strlen(itoa(adc_val,str,10)),1000);

			HAL_UART_Transmit(&huart1,(uint8_t*)" ",1,1000);

			HAL_UART_Transmit(&huart1,(uint8_t*)"#\r",2,1000);

			send_signal = 0;

			set_Timer(900);
		}


		if(timer_flag)
		{
			send_signal = 1;
		}


	}

	default: break;

	}

}
