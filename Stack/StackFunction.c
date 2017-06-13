/*
 * StackFunction.c
 *
 *  Created on: 2017Äê4ÔÂ26ÈÕ
 *      Author: Administrator
 */
#include "StackFunction.h"

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
	int top;
}SqStack;

Status Svisit(SElemType c)
{
	printf("%d",c);
	return OK;
}

Status InitStack(SqStack *S)
{
	S->top=-1;
	return OK;
}

Status ClearStack(SqStack *S)
{
	S->top=-1;
	return OK;
}

Status StackEmpty(SqStack S)
{
	if(S.top==-1)
		return TRUE;
	else
		return FALSE;

}

int StackLength(SqStack S)
{
	return S.top+1;
}

Status GetTop(SqStack S,SElemType *e)
{
	if(S.top==-1)
		return ERROR;
	else
		*e=S.data[S.top];
	return OK;
}

Status PushStackNew(SqStack *S,SElemType e)
{
	if(S->top==MAXSIZE-1)
		return ERROR;
	S->top++;
	S->data[S->top]=e;
	return OK;
}

Status PopStackDelete(SqStack *S,SElemType *e)
{
	if(S->top==-1)
		return ERROR;
	*e=S->data[S->top];
	S->top--;
	return OK;
}

Status StackTraverse(SqStack S)
{
	int i;
	i=0;
	while(i<=S.top)
	{
		Svisit(S.data[i++]);

	}
	printf("\n");
	return OK;
}
