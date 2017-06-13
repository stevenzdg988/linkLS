/*
 * StaticLinkListFunction.c
 *
 *  Created on: 2017Äê4ÔÂ26ÈÕ
 *      Author: Administrator
 */
#include "StaticLinkListFunction.h"

#include "string.h"
#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "io.h"
#include "time.h"


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType data;
	int cur;
}Component,StaticLinkList[MAXSIZE];


Status visitS(ElemType c)
{
	printf("%c",c);
	return OK;

}

Status InitListS(StaticLinkList space)
{
	int i;
	for(i=0;i<MAXSIZE-1;i++)
		space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;
	return OK;
}

int Malloc_SSL(StaticLinkList space)
{
	int i=space[0].cur;
	if(space[0].cur)
		space[0].cur=space[i].cur;
	return i;

}

void Free_SSL(StaticLinkList space,int k)
{
	space[k].cur=space[0].cur;
	space[0].cur=k;
}

int SListLength(StaticLinkList L)
{
	int j=0;
	int i=L[MAXSIZE-1].cur;
	while(i)
	{
		i=L[i].cur;
		j++;
	}
	return j;
}

Status ListInsertS(StaticLinkList L,int i,ElemType e)
{
	int j,k,l;
	k=MAXSIZE-1;
	if(i<1||i>SListLength(L)+1)
		return ERROR;
	j=Malloc_SSL(L);
	if(j)
	{
		L[j].data=e;
		for(l=1;l<=i-1;l++)
			k=L[k].cur;
		L[j].cur=L[k].cur;
		L[k].cur=j;
		return OK;
	}
	return ERROR;

}

Status ListDeleteS(StaticLinkList L,int i)
{
	int j,k;
	if(i<1||i>SListLength(L))
		return ERROR;
	k=MAXSIZE-1;
	for(j=1;j<=i-1;j++)
		k=L[k].cur;
	j=L[k].cur;
	L[k].cur=L[j].cur;
	Free_SSL(L,j);
	return OK;
}

Status ListTraverseS(StaticLinkList L)
{
	int j=0;
	int i=L[MAXSIZE-1].cur;
	while(i)
	{
		visitS(L[i].data);
		i=L[i].cur;
		j++;
	}
	return j;
	printf("\n");
	return OK;
}
