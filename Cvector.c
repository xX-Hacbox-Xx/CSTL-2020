//
//  Cvector.c
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/13.
//  Copyright © 2020 李远铄. All rights reserved.
//

#include "Cvector.h"
#include <stdio.h>
#include <stdlib.h>
#define INI_SIZE 100
#define PLUS_SIZE 20

void Vector_Create(vector* v);
bool Vector_Empty(vector* v);
void Vector_Del(vector* v);
ulong Vector_Size(vector* v);
void Vector_Push(vector* v,TYPE_VECTOR x);
TYPE_VECTOR Vector_Ele(vector* v,ulong index);

void Vector_Create(vector* v){
    TYPE_VECTOR* n=(TYPE_VECTOR*)calloc(INI_SIZE, sizeof(TYPE_VECTOR));
    v->size=0;
    v->value=n;
    v->maxSize=INI_SIZE-1;
}
void Vector_Push(vector* v,TYPE_VECTOR x){
    if (v->size==v->maxSize) {
        TYPE_VECTOR* new=(TYPE_VECTOR*)realloc(v->value, (v->maxSize+1+PLUS_SIZE)*sizeof(TYPE_VECTOR));
        if (new==NULL) {
            printf("ERROR IN REALLOC VECTOR");
            exit(ERROR);
        }else{
            v->value=new;
            v->maxSize=v->maxSize+PLUS_SIZE;
        }
    }
    *((v->value)+v->size+1)=x;
    v->size=v->size+1;
}
TYPE_VECTOR Vector_Ele(vector* v,ulong index){
    if (index>v->size) {
        printf("ERROR IN GET ELE FROM VECTOR : INDEX>SIZE");
        exit(ERROR);
    }
    return *(v->value+index+1);
}
void Vector_Del(vector* v){
    if (v->value==NULL) {
        return;
    }else{
        free(v->value);
        v->size=0;
        v->maxSize=0;
        v->value=NULL;
    }
}
bool Vector_Empty(vector* v){
    return v->size==0?TRUE:FALSE;
}
ulong Vector_Size(vector* v){
    return v->size;
}

