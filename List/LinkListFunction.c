#include "LinkListFunction.h"

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"




#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList;

Status visitL(ElemType c)
{
	printf("%d",c);
	return OK;
}

Status InitListL(LinkList *L)
{
	*L=(LinkList)malloc(sizeof(Node));
	if(!(*L))
		return ERROR;
	(*L)->next=NULL;

	return OK;
}

Status ListEmptyL(LinkList L)
{
	if(L->next)
		return FALSE;
	else
		return TRUE;
}

Status ClearListL(LinkList *L)
{
	LinkList p,q;
	p=(*L)->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;
	return OK;

}

int ListLengthL(LinkList L)
{
	int i=0;
	LinkList p=L->next;
	while(p)
	{
		i++;
		p=p->next;
	}
	return i;
}

Status GetElemL(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;
	p=L->next;
	j=1;
	while(p && j<i)
	{
		p=p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	*e=p->data;
	return OK;
}

int LocateElemL(LinkList L,ElemType e)
{
	int i=0;
	LinkList p=L->next;
	while(p)
	{
		i++;
		if(p->data==e)
			return i;
		p=p->next;
	}
	return 0;
}

Status ListInsertL(LinkList *L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p=*L;
	j=1;
	while(p && j<i)
	{
		p=p->next;
		++j;

	}
	if(!p || j>i)
		return ERROR;
	s=(LinkList)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status ListDeleteL(LinkList *L,int i,ElemType *e)
{
	int j;
	LinkList p,q;
	p=*L;
	j=1;
	while(p->next&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i)
		return ERROR;
	q=p->next;
	p->next=q->next;
	*e=q->data;
	free(q);
	return OK;
}

Status ListTraverseL(LinkList L)
{
	LinkList p=L->next;
	while(p)
	{
		visitL(p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

void CreateListHeadL(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		p->next=(*L)->next;
		(*L)->next=p;
	}
}

void CreateListTailL(LinkList *L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));
	r=*L;
	for(i=0;i<n;i++)
	{
		p=(Node *)malloc(sizeof(Node));
		p->data=rand()%100+1;
		r->next=p;
		r=p;
	}
	r->next=NULL;
}
