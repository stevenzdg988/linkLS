/*
 * LinkStack.h
 *
 *  Created on: 2017��4��27��
 *      Author: Administrator
 */

#ifndef LINKSTACKFUNCTION_H_
#define LINKSTACKFUNCTION_H_

typedef int Status;
typedef int SElemType;

Status LSvist();

Status LSInitStack();

Status LSClearStack();

Status LSStackEmpty();

int LSStackLength();

Status LSGetTop();

Status LSPush();

Status LSPop();

Status LSStackTraverse();

#endif /* LINKSTACKFUNCTION_H_ */
