//
//  Cqueue.h
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/13.
//  Copyright © 2020 李远铄. All rights reserved.
//

#ifndef Cqueue_h
#define Cqueue_h

#include <stdio.h>
#include "Cstandard.h"
typedef long TYPE_QUEUE;
typedef struct NODE_QUEUE{
    struct NODE_QUEUE* next;
    TYPE_QUEUE value;
}Node_Queue;
typedef struct{
    Node_Queue* front;
    Node_Queue* back;
    ulong size;
}queue;
void Queue_Create(queue* q);
bool Queue_Empty(queue* q);
TYPE_QUEUE Queue_Front(queue* q);
void Queue_Push(queue* q,TYPE_QUEUE x);
void Queue_Pop(queue* q);
void Queue_Del(queue* q);
ulong Queue_Size(queue* q);
#endif /* Cqueue_h */
