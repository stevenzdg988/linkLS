/*
 * compare.c
 *
 *  Created on: 2017年5月22日
 *      Author: Administrator
 */

#include "stdio.h"
#include "math.h"
void outputre(int x)
{
	x=7;
	if(x<5 || x>10)
		printf("大于零");
	else
		printf("小于零");
}

void caculateA(int y)
{
	printf("%d\n",(int)(y*0.1));
	printf("%f\n",y*M_PI);
}

