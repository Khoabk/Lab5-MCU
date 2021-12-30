/*
 * uart_communication.h
 *
 *  Created on: Dec 10, 2021
 *      Author: dang khoa
 */

#ifndef COMMAND_PARSER_H_
#define COMMAND_PARSER_H_

#include "main.h"

#define MAX_BUFFER_SIZE 30

extern uint8_t temp;

extern uint8_t buffer[MAX_BUFFER_SIZE];

extern uint8_t index_buffer;

extern uint8_t buffer_flag;

extern uint8_t send_signal;

extern uint8_t receive_signal;

extern uint8_t state1;


void command_parser_fsm();


#endif

