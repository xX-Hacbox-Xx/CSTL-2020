//
//  Cmap.h
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/21.
//  Copyright © 2020 李远铄. All rights reserved.
//

#ifndef Cmap_h
#define Cmap_h

#include <stdio.h>
#include "Cstandard.h"
typedef int TYPE_KEY;
typedef int TYPE_VALUE;
typedef struct NODE_MAP{
    TYPE_KEY key;
    TYPE_VALUE value;
    struct NODE_MAP* left;
    struct NODE_MAP* right;
}Node_Map;
typedef struct MAP{
    Node_Map* root;
    Node_Map* head;
}map;
bool Compare_Ele(TYPE_KEY a,TYPE_KEY b);
void Map_Create(map* tree);
bool Map_Insert(map* tree,TYPE_KEY key,TYPE_VALUE value);//返回是否已经存在
bool Map_Find(map* tree,TYPE_KEY key,TYPE_VALUE* value);
void Map_DelKey(map* tree,TYPE_KEY key);
void Map_Print(map* tree);//从小到大，就是DFS中序
void Map_TYPE_Print(Node_Map* n);//自定义打印模式
void Map_Del(map* tree);
#endif /* Cmap_h */
