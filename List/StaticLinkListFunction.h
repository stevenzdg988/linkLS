/*
 * StaticLinkListFunction.h
 *
 *  Created on: 2017年4月26日
 *      Author: Administrator
 */

#ifndef STATICLINKLISTFUNCTION_H_
#define STATICLINKLISTFUNCTION_H_

/*
 * StaticLinkListFunction.c
 *
 *  Created on: 2017年4月26日
 *      Author: Administrator
 */
typedef int Status;
typedef int ElemType;


Status visitS();

Status InitListS();

void Free_SSL();

Status ListInsertS();

int SListLength();

Status ListDeleteS();

Status ListTraverseS();

#endif /* STATICLINKLISTFUNCTION_H_ */
