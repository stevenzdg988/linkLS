/*
 * LinkStack.c
 *
 *  Created on: 2017Äê4ÔÂ27ÈÕ
 *      Author: Administrator
 */
#include "LinkStackFunction.h"

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

typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status LSvist(SElemType c)
{
	printf("%d",c);
	return OK;
}

Status LSInitStack(LinkStack *S)
{
	S->top=(LinkStackPtr)malloc(sizeof(StackNode));
	if(!S->top)
		return ERROR;
	S->top=NULL;
	S->count=0;
	return OK;
}

Status LSClearStack(LinkStack *S)
{
	LinkStackPtr p,q;
	p=S->top;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	S->count=0;
	return OK;
}

Status LSStackEmpty(LinkStack S)
{
	if(S.count==0)
		return TRUE;
	else
		return FALSE;
}

int LSStackLength(LinkStack S)
{
	return S.count;

}

Status LSGetTop(LinkStack S,SElemType *e)
{
	if(S.top==NULL)
		return ERROR;
	else
		*e=S.top->data;
	return OK;
}

Status LSPush(LinkStack *S,SElemType e)
{
	LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
	s->data=e;
	s->next=S->top;
	S->top=s;
	S->count++;
	return OK;
}

Status LSPop(LinkStack *S,SElemType *e)
{
	LinkStackPtr p;
	if(LSStackEmpty(*S))
		return ERROR;
	*e=S->top->data;
	p=S->top;
	S->top=S->top->next;
	free(p);
	S->count--;
	return OK;
}

Status LSStackTraverse(LinkStack S)
{
	LinkStackPtr p;
	p=S.top;
	while(p)
	{
		LSvist(p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}
