/*
 * QueueFunction.h
 *
 *  Created on: 2017��4��27��
 *      Author: Administrator
 */

#ifndef QUEUEFUNCTION_H_
#define QUEUEFUNCTION_H_

typedef int Status;
typedef int QElemType;

Status Qvisit();

Status InitQueue();

Status ClearQueue();

Status QueueEmpty();

int QueueLength();

Status QGetHead();

Status EnQueue();

Status DeQueue();

Status QueueTraverse();

#endif /* QUEUEFUNCTION_H_ */
