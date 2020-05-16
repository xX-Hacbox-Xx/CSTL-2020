//
//  Cstack.h
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/13.
//  Copyright © 2020 李远铄. All rights reserved.
//

#ifndef Cstack_h
#define Cstack_h

#include <stdio.h>
#include "Cstandard.h"
typedef long TYPE_STACK;
typedef struct STACK{
    ulong size;
    ulong maxSize;//就是指size的最大值
    TYPE_STACK* begin;//begin本身不存储数据！即begin==top是size=0；
    TYPE_STACK* top;
}stack;
void Stack_Create(stack* s);
TYPE_STACK Stack_Top(stack* s);
void Stack_Pop(stack* s);
bool Stack_Empty(stack* s);
void Stack_Push(stack* s,TYPE_STACK x);
void Stack_Del(stack* s);
#endif /* Cstack_h */

