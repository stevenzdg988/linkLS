/*
 * DoubleStack.c
 *
 *  Created on: 2017Äê4ÔÂ27ÈÕ
 *      Author: Administrator
 */
#include "DoubleStackFunction.h"

#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int SElemType;

typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

Status DSvisit(SElemType c)
{
	printf("%d",c);
	return OK;
}

Status DSInitStack(SqDoubleStack *S)
{
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK;
}

Status DSClearStack(SqDoubleStack *S)
{
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK;
}

Status DSStackEmpty(SqDoubleStack S)
{
	if(S.top1==-1&&S.top2==MAXSIZE)
		return TRUE;
	else
		return FALSE;
}

int DSStackLength(SqDoubleStack S)
{
	return (S.top1+1)+(MAXSIZE-S.top2);
}

Status DSPush(SqDoubleStack *S,SElemType e,int stackNumber)
{
	if(S->top1+1==S->top2)
		return ERROR;
	if(stackNumber==1)
		S->data[++S->top1]=e;
	else if(stackNumber==2)
		S->data[--S->top2]=e;
	return OK;
}

Status DSPop(SqDoubleStack *S,SElemType *e,int stackNumber)
{
	if(stackNumber==1)
	{
		if(S->top1==-1)
			return ERROR;
		*e=S->data[S->top1--];
	}
	return OK;
}

Status DSStackTraverse(SqDoubleStack S)
{
	int i;
	i=0;
	while(i<=S.top1)
	{
		DSvisit(S.data[i++]);
	}
	i=S.top2;
	while(i<MAXSIZE)
	{
		DSvisit(S.data[i++]);
	}
	printf("\n");
	return OK;
}
