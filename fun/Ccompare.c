/*
 * compare.c
 *
 *  Created on: 2017��5��22��
 *      Author: Administrator
 */

#include "stdio.h"
#include "math.h"
void outputre(int x)
{
	x=7;
	if(x<5 || x>10)
		printf("������");
	else
		printf("С����");
}

void caculateA(int y)
{
	printf("%d\n",(int)(y*0.1));
	printf("%f\n",y*M_PI);
}

