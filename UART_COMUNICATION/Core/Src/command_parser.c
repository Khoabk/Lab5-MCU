/*
 * command_parser.c
 *
 *  Created on: Dec 10, 2021
 *      Author: dang khoa
 */

#include "main.h"

#include "command_parser.h"

#include "uart_communication.h"

#include "stdlib.h"

#include "string.h"

#include "stdio.h"

uint8_t request[]={'!','R','S','T','#'};

uint8_t ack[]={'!','O','K','#'};

uint8_t temp = '0';

uint8_t buffer[MAX_BUFFER_SIZE];

uint8_t index_buffer = 0;

uint8_t buffer_flag = 0;

uint8_t send_signal = 0;

uint8_t receive_signal = 0;

uint8_t state1 = 0;


void command_parser_fsm()
{
	switch(state1)
	{

		case 0:
		{
			if(temp == '#')
			{

				int i = 4;

				while(i >= 0)
				{

					index_buffer = (index_buffer==0)?29:index_buffer - 1;

					if(request[i] != buffer[index_buffer])
					{

						char *str1 = "\rInvalid request syntax\r";

						HAL_UART_Transmit(&huart1,(uint8_t*)str1,strlen(str1),1000);

						return;
					}

					i--;

				}

				send_signal = 1;

				adc_val = HAL_ADC_GetValue(&hadc1);

				state1 = 1;

			}

			break;
		}
		case 1:
		{
			if(temp == '#')
			{

				int i = 3;

				while(i >= 0)
				{

					index_buffer = (index_buffer == 0)?29:index_buffer - 1;

					if(ack[i] != buffer[index_buffer])
					{

						char *str1 = "\rInvalid ack syntax\r";

						HAL_UART_Transmit(&huart1,(uint8_t*)str1,strlen(str1),1000);

						return;
					}

					i--;

				}
				receive_signal = 1;

				state1 = 0;
			}
			
			break;
		}
		default: break;
	}
}
