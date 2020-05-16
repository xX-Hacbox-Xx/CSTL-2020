//
//  Cqueue.c
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/13.
//  Copyright © 2020 李远铄. All rights reserved.
//

#include "Cqueue.h"
#include <stdlib.h>
Node_Queue* New_Node_Queue(void);
void Queue_Create(queue* q);
bool Queue_Empty(queue* q);
TYPE_QUEUE Queue_Front(queue* q);
void Queue_Push(queue* q,TYPE_QUEUE x);
void Queue_Pop(queue* q);
void Queue_Del(queue* q);
ulong Queue_Size(queue* q);

void Queue_Create(queue* q){
    q->size=0;
    q->front=NULL;
    q->back=NULL;
}
bool Queue_Empty(queue* q){
    return q->size==0?TRUE:FALSE;
}
TYPE_QUEUE Queue_Front(queue* q){
    if (q->size==0) {
        printf("GET AN ELE FROM AN EMPTY QUEUE\n");
        exit(ERROR);
    }else{
        return (q->front)->value;
    }
}
void Queue_Push(queue* q,TYPE_QUEUE x){
    if (q->size==0) {
        Node_Queue* n=New_Node_Queue();
        q->back=n;
        q->front=n;
        n->value=x;
    }else{
        Node_Queue* n=New_Node_Queue();
        (q->back)->next=n;
        n->value=x;
        q->back=n;
    }
    q->size++;
}
void Queue_Pop(queue* q){
    if (q->size==0) {
        printf("POP AN ELE FROM AN EMPTY QUEUE\n");
        exit(ERROR);
    }else{
        Node_Queue* old=q->front;
        q->front=(q->front)->next;
        free(old);
        q->size--;
    }
}
void Queue_Del(queue* q){
    Node_Queue* n=q->front;
    while (n!=NULL) {
        Node_Queue* pre=n;
        n=n->next;
        free(pre);
    }
    q->back=NULL;
    q->front=NULL;
    q->size=0;
}
Node_Queue* New_Node_Queue(void){
    Node_Queue* n=(Node_Queue*)malloc(sizeof(Node_Queue));
    if (n==NULL) {
        printf("ERROR IN NEW A NODE IN QUEUE\n");
        exit(ERROR);
    }
    n->next=NULL;
    n->value=0;
    return n;
}
ulong Queue_Size(queue* q){
    return q->size;
}
