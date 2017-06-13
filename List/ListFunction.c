#include "ListFunction.h"
#include "stdio.h"
//#include "stdlib.h"
//#include "io.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status visit(ElemType c)
{
	printf("%d ",c);
	return OK;
}

Status InitList(SqList *L)
{
	L->length=0;
	return OK;
}

Status ListEmpty(SqList L)
{
	if(L.length==0)
		return 1;
	else
		return 0;
}

Status ClearList(SqList *L)
{
	L->length=0;
	return 1;
}

int ListLength(SqList L)
{
	return L.length;
}

Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length==0 || i>L.length)
		return 0;
	*e=L.data[i-1];
	return 1;
}

int LocateElem(SqList L ,ElemType e)
{
	int i;
	if(L.length==0)
		return 0;
	for(i=0;i<L.length;i++)
	{
		if(L.data[i]==e)
			break;
	}
	if(i>=L.length)
		return 0;
	return i+1;
}

Status ListInsert(SqList *L,int i ,ElemType e)
{
	int k;
	if(L->length==MAXSIZE)
		return 0;
	if(i<1 || i>L->length+1)
		return 0;
	if(i<=L->length)
	{
		for(k=L->length-1;k>=i-1;k--)
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;
	L->length++;
	return 	1;
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
	int k;
	if(L->length==0)
		return 0;
	if(i<1||i>L->length)
		return 0;
	*e=L->data[i-1];
	if(i<L->length)
	{
		for(k=i;k<L->length;k++)
			L->data[k-1]=L->data[k];
	}
	L->length--;
	return 1;
}

Status ListTraverse(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
		visit(L.data[i]);
	printf("\n");
	return 1;
}

void unionL(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;
	La_len=ListLength(*La);
	Lb_len=ListLength(Lb);
	for(i=1;i<=Lb_len;i++)
	{
		GetElem(Lb,i,&e);
		if(!LocateElem(*La,e))
			ListInsert(La,++La_len,e);
	}
}



