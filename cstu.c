/*
 * cstu.c
 *
 *  Created on: 2017年4月20日
 *      Author: Administrator
 */
#include "stdio.h"


//#include "math.h"
#include "List/ListFunction.h"
#include "List/LinkListFunction.h"
#include "List/StaticLinkListFunction.h"
#include "Stack/StackFunction.h"
#include "Stack/LinkStackFunction.h"
#include "Stack/DoubleStackFunction.h"
#include "Fibonacci/FibonacciFun.h"
#include "Queue/QueueFunction.h"
#include "fun/Ccompare.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

//Liststruct
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;


//LinkListstruct
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList;

//StaticLinkListstruct

typedef struct
{
	ElemType data;
	int cur;
}Component,StaticLinkList[MAXSIZE];

//STACK
typedef int SElemType;
typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

//LinkStack
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

//DoubleStack
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

//Queue
typedef int QElemType;
typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;
//Status InitList();

int main()
{

	//List//
	//链表初始化-list init
	printf("***********List************\n");
	SqList L;
	InitList(&L);
	printf("After InitList,Output is：L.length=%d\n",L.length);
	//插入数据到链表
	int j,k;
	Status i;
	ElemType e;
	i=InitList(&L);
	for(j=1;j<=5;j++)
		i=ListInsert(&L,1,j);
	printf("The list is insert data,L.data=");
	ListTraverse(L);
	printf("The list`s length is:L.length=%d\n",L.length);
	// 判断链表是否为空表
	i=ListEmpty(L);
	printf("L is empty?[i=%d](1:yes,0:no)\n",i);
	//清空链表
	i=ClearList(&L);
	printf("The list`s length is:L.length=%d\n",L.length);
	//
	i=ListEmpty(L);
	printf("L is empty?[i=%d](1:yes,0:no)\n",i);
	//
	for(j=1;j<=10;j++)
		ListInsert(&L,j,j);
	printf("Inser the num 1~10 on it`s tail:L.data=");

	ListTraverse(L);
	printf("L.length=%d \n",L.length);
	ListInsert(&L,1,0);
	printf("Insert the num 0 on it`s top:L.data=");
	ListTraverse(L);
	printf("L.length=%d\n",L.length);
	GetElem(L,5,&e);
	printf("The fifth elem is: %d\n",e);
	for(j=3;j<=4;j++)
	{
		k=LocateElem(L,j);
		if(k)
			printf("The %d th elem data is:%d\n",k,j);
		else
			printf("No value %d elem data is %d\n",j,e);

	}
	printf("Output the elem on order:");
	ListTraverse(L);
	k=ListLength(L);
	for(j=k+1;j>=k;j--)
	{
		i=ListDelete(&L,j,&e);
		if(i==0)
			printf("Delete the %d data fail.\n",j);
		else
			printf("Delete the %d data valure is:%d\n",j,e);
	}
	printf("Output the L.data:");
	ListTraverse(L);
	j=5;
	ListDelete(&L,j,&e);
	printf("Delete the %d elem is:%d \n",j,e);
	printf("Output the L data:");
	ListTraverse(L);

	SqList Lb;
	i=InitList(&Lb);
	for(j=6;j<=15;j++)
		i=ListInsert(&Lb,1,j);
	unionL(&L,Lb);
	printf("Output The Lb data:");
	ListTraverse(Lb);
	//return 0;


	printf("\n***********LinkList************\n");
	//LinkList//

	LinkList K;
	ElemType f;
	Status v;
	int m;
	i=InitListL(&K);
	printf("After init List:ListLengthL(K)=%d\n",ListLengthL(K));
	for(j=1;j<=5;j++)
		v=ListInsertL(&K,1,j);
	printf("Insert data num 1~5 on ListHead:K.data=");
	v=ListTraverseL(K);
	printf("ListLengthL(K)=%d \n",ListLengthL(K));
	v=ListEmptyL(K);
	printf("K is empty:i=%d(1:yes,0:no)\n",v);
	v=ClearListL(&K);
	printf("Clear the K-list:ListLengthL(K)=%d\n",ListLengthL(K));
	v=ListEmptyL(K);
	printf("K is empty:i=%d(1:yes,0:no)\n",v);
	for(j=1;j<=10;j++)
		ListInsertL(&K,j,j);
	printf("Insert the num 1~10 on the K tail:K.date=");
	ListTraverseL(K);
	printf("ListLengthL(K)=%d\n",ListLengthL(K));
	ListInsertL(&K,1,0);
	printf("Insert num 0 on the K head:k.data=");
	ListTraverseL(K);
	printf("ListLengthL(K)=%d\n",ListLengthL(K));
	GetElemL(K,5,&f);
	printf("The fifth element is:%d \n",f);
	for(j=3;j<=4;j++)
	{
		m=LocateElemL(K,j);
		if(m)
			printf("The No.%d element is:%d\n",m,j);
		else
			printf("There is no %d element\n",j);

	}

	m=ListLengthL(K);
	for(j=m+1;j>=m;j--)
	{
		v=ListDeleteL(&K,j*f);
		if(v==ERROR)
			printf("Delete The No.%d data false\n",j);
		else
			printf("Delet the No.%d element is:%d\n",j,f);
	}
	printf("Output the elements in order:");
	ListTraverseL(K);
	j=5;
	ListDeleteL(&K,j,&f);
	printf("Delete the No.%d element is:%d\n",j,f);
	printf("Output the data inorder:");
	ListTraverseL(K);
	v=ClearListL(&K);
	printf("\nClear list :ListLengthL(K)=%d \n",ListLengthL(K));
	CreateListHeadL(&K,20);
	printf("Make K element(Head):");
	ListTraverseL(K);
	v=ClearListL(&K);
	printf("\nDelete K ,ListLengthL(K)=%d \n",ListLengthL(K));
	CreateListTailL(&K,20);
	printf("Make K element(Tail):");
	ListTraverseL(K);


	printf("\n*************StaticLinkList****************\n");

	StaticLinkList SL;
	//Status a;
	InitListS(SL);
	printf("After init SL,SL.length=%d\n",SListLength(SL));
	ListInsertS(SL,1,'F');
	ListInsertS(SL,1,'E');
	ListInsertS(SL,1,'D');
	ListInsertS(SL,1,'C');
	ListInsertS(SL,1,'B');
	ListInsertS(SL,1,'A');
	printf("\nInsert charactor F~A:\nSL.data=");
	ListTraverseS(SL);
	ListInsertS(SL,3,"Z");
	printf("\nInsert num a between charactor B and C:\nSL.data=");
	ListTraverseS(SL);
	ListDeleteS(SL,1);
	printf("\nDelete behand charactor A in SL:\nSL.data=");
	ListTraverseS(SL);
	printf("\n");

	printf("\n****************STACK****************\n");

	int x;
	SqStack s;
	int g;
	if(InitStack(&s)==OK)
		for(x=1;x<=10;x++)
			PushStackNew(&s,x);
	printf("The element of Stack is:");
	StackTraverse(s);
	PopStackDelete(&s,&g);
	printf("Out to the stack element e=%d\n",g);
	printf("Stack is empty:%d(1:yes,0:no)\n",StackEmpty(s));
	GetTop(s,&g);
	printf("The top of the STACK  element is: %d,The length of the STACK is:%d\n",g,StackLength(s));
	ClearStack(&s);
	printf("After clear the STACK,The STACK is empty? %d(1:yes,0:no)\n",StackEmpty(s));

	printf("\n*************************LinkStack***********************\n");
	int jj;
	LinkStack ss;
	int ee;
	if(LSInitStack(&ss)==OK)
		for(jj=1;jj<=10;jj++)
			LSPush(&ss,jj);
	printf("The element of the Stack is:");
	LSStackTraverse(ss);
	LSPop(&ss,&ee);
	printf("The top of the Stack element out ee=%d\n",ee);
	printf("Stack is empty? %d(1:yes,0:no)\n",LSStackEmpty(ss));
	LSGetTop(ss,&ee);
	printf("The top of Stack element ee=%d ,The length of Stack is:%d \n",ee,LSStackLength(ss));
	LSClearStack(&ss);
	printf("After clear the Stack,the Stack is empty? %d(1:yes,0:no)\n",LSStackEmpty(ss));

	printf("\n**************************DoubleStack*******************************\n");
	int dj;
	SqDoubleStack ds;
	int de;
	if(DSInitStack(&ds)==OK)
	{
		for(dj=1;dj<=5;dj++)
			DSPush(&ds,dj,1);
		for(dj=MAXSIZE;dj>=MAXSIZE-2;dj--)
			DSPush(&ds,dj,2);
	}
	printf("The element of the Stack is:");
	DSStackTraverse(ds);
	printf("The length of Stack is: %d\n",DSStackLength(ds));
	DSPop(&ds,&de,2);
	printf("The element of the pop is: de=%d\n",de);
	printf("The stack is empty?  %d(1:yes,0:no)\n",DSStackEmpty(ds));
	for(dj=6;dj<=MAXSIZE-2;dj++)
		DSPush(&ds,dj,1);
	printf("The element of the Stack is:");
	DSStackTraverse(ds);

	printf("The stack is full? %d(1:no,0:yes)\n",DSPush(&ds,100,1));
	DSClearStack(&ds);
	printf("After clear stack,It is empty?  %d(1:yes,0:no)\n",DSStackEmpty(ds));

	printf("************************FIBNACCI**********************\n");
	int fi;
	//scanf("%d",&fi);
	//fi=Fibnacci(fi);
	//printf("%d\n",fi);
	for(fi=0;fi<=10;fi++)
	{
		int ffi;
		ffi=Fibnacci(fi);
		printf("%d\n",ffi);
	}
	int o=10000;
	outputre(o);
	printf("\n");
	caculateA(o);

	printf("\n**************************QUEUE************************\n");
	Status qj;
	int qi=0,ql;
	QElemType qd;
	SqQueue Q;
	InitQueue(&Q);
	printf("After init Queue,It is empty? %d(1:yes,0:no)\n",QueueEmpty(Q));
	printf("Please Input integer num element( %d ),-1 is ahead of time:",MAXSIZE-1);
	do
	{
		qd=qi+100;
		if(qd==-1)
			break;
		qi++;
		EnQueue(&Q,qd);
	}while(qi<MAXSIZE-1);
	printf("The length of Queue is: %d \n",QueueLength(Q));
	printf("The Queue is empty? %d(1:yes,0:no)\n",QueueEmpty(Q));
	printf("The continunity of %d Delete element on the Head,and Insert element on the Rear:\n",MAXSIZE);
	for(ql=1;ql<=MAXSIZE;ql++)
	{
		DeQueue(&Q,&qd);
		printf("The Deleted element is:%d ,and The Insert elemnent is :%d \n",qd,ql+1000);
		qd=ql+1000;
		EnQueue(&Q,qd);

	}
	ql=QueueLength(Q);
	printf("The element of the Queue is:\n");
	QueueTraverse(Q);
	printf("The common of Inserting %d elements:\n",ql-2);
	while(QueueLength(Q)>2)
	{
		scanf("%d",&qd);
		DeQueue(&Q,&qd);
		printf("The deleted element value is: %d \n",qd);

	}
	qj=QGetHead(Q,&qd);
	if(qj)
		printf("The Queue front is: %d \n",qd);
	ClearQueue(&Q);
	printf("After clear the Queue,It is empty? %d (1:yes,0:no)\n",QueueEmpty(Q));

	return 0;
}

