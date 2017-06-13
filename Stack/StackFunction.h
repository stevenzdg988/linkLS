/*
 * StackFunction.h
 *
 *  Created on: 2017年4月26日
 *      Author: Administrator
 */

#ifndef STACKFUNCTION_H_
#define STACKFUNCTION_H_

/*
 * StackFunction.c
 *
 *  Created on: 2017年4月26日
 *      Author: Administrator
 */
typedef int Status;
typedef int SElemType;

Status Svisit();

Status InitStack();

Status ClearStack();

Status StackEmpty();

int StackLength();

Status GetTop();

Status PopStackDelete();

Status PushStackNew();

Status StackTraverse();

#endif /* STACKFUNCTION_H_ */
