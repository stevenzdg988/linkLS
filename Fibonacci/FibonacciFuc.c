/*
 * FibonacciFuc.c
 *
 *  Created on: 2017��4��27��
 *      Author: Administrator
 */
#include "FibonacciFun.h"

int Fibnacci(int i)
{
	if(i<2)
		return i==0?0:1;
	return Fibnacci(i-1)+Fibnacci(i-2);
}

