//
//  Cset.h
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/21.
//  Copyright © 2020 李远铄. All rights reserved.
//

#ifndef Cset_h
#define Cset_h

#include <stdio.h>
#include "Cstandard.h"
typedef int TYPE_SET;
typedef int bool;
typedef struct NODE_SET{
    TYPE_SET value;
    struct NODE_SET* left;
    struct NODE_SET* right;
}Node_Set;
typedef struct SET{
    Node_Set* root;
    Node_Set* head;
}set;
bool Set_Compare_Ele(TYPE_SET a,TYPE_SET b);
void Set_Create(set* tree);
bool Set_Insert(set* tree,TYPE_SET ele);//返回是否已经存在
bool Set_Find(set* tree,TYPE_SET ele);
void Set_DelValue(set* tree,TYPE_SET ele);
void Set_Print(set* tree);//从小到大，就是DFS中序
void Set_TYPE_Print(TYPE_SET x);//注意如果是打印字符串的话需要改函数,自定义打印模式
void Set_Del(set* tree);
#endif /* Cset_h */
