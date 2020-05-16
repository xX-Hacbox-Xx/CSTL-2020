//
//  Cvector.h
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/13.
//  Copyright © 2020 李远铄. All rights reserved.
//

#ifndef Cvector_h
#define Cvector_h

#include <stdio.h>
#include "Cstandard.h"
typedef int TYPE_VECTOR;
typedef struct VECTOR{
    ulong size;
    ulong maxSize;
    TYPE_VECTOR* value;
}vector;
void Vector_Create(vector* v);
bool Vector_Empty(vector* v);
void Vector_Del(vector* v);
ulong Vector_Size(vector* v);
void Vector_Push(vector* v,TYPE_VECTOR x);
TYPE_VECTOR Vector_Ele(vector* v,ulong index);
#endif /* Cvector_h */
