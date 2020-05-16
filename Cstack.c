//
//  Cstack.c
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/13.
//  Copyright © 2020 李远铄. All rights reserved.
//

#include "Cstack.h"
#include <stdio.h>
#include <stdlib.h>
#define INI_SIZE 100
#define PLUS_SIZE 20

void Stack_Create(stack* s);
TYPE_STACK Stack_Top(stack* s);
void Stack_Pop(stack* s);
bool Stack_Empty(stack* s);
void Stack_Push(stack* s,TYPE_STACK x);
void Stack_Del(stack* s);


void Stack_Create(stack* s){
    s->size=0;
    s->begin=(TYPE_STACK*)calloc(INI_SIZE, sizeof(TYPE_STACK));
    s->maxSize=INI_SIZE-1;
    s->top=s->begin;
}
TYPE_STACK Stack_Top(stack* s){
    if (s->size==0) {
        printf("GET ELE FROM AN EMPTY STACK\n");
        exit(ERROR);
    }
    return *(s->top);
}
void Stack_Pop(stack* s){
    if (s->size==0) {
        printf("POP ELE FROM AN EMPTY STACK\n");
        exit(ERROR);
    }
    (s->top)--;
    s->size--;
}
bool Stack_Empty(stack* s){
    return s->size==0?TRUE:FALSE;
}
void Stack_Push(stack* s,TYPE_STACK x){
    if (s->maxSize==s->size) {
        TYPE_STACK* new=(TYPE_STACK*)realloc(s->begin, (s->maxSize+1+PLUS_SIZE)*sizeof(TYPE_STACK));
        if (new==NULL) {
            printf("ERROR IN REALLOC STACK");
            exit(ERROR);
        }else{
            s->begin=new;
            s->top=s->begin+s->size;
            s->maxSize=s->maxSize+PLUS_SIZE;
            s->top++;
            *(s->top)=x;
            s->size++;
        }
    }else{
        s->top++;
        *(s->top)=x;
        s->size++;
    }
}
void Stack_Del(stack* s){
    if (s->begin==NULL) {
        return;
    }else{
        free(s->begin);
        s->begin=NULL;
        s->size=0;
        s->maxSize=0;
        s->top=NULL;
    }
}
