/*
 * timer.c
 *
 *  Created on: Dec 10, 2021
 *      Author: dang khoa
 */

#include "main.h"

#include "timer.h"


static int timer_counter = 10;

static int timer_bound = 10;

int timer_flag = 0;

static int timer_cycle = 10;

static int en = 0;




void disable_timer()
{
	en = 0;

	timer_flag = 0;
}




void set_Timer(int count_down)
{
	if(!en) en = 1;

	timer_bound = count_down/timer_cycle;

	timer_counter = timer_bound;

	timer_flag = 0;
}



void timer_run()
{

	if(en)
	{
		timer_counter=(timer_counter==0)?0:timer_counter-1;

		timer_flag=(timer_counter==0)?1:0;
	}

}

