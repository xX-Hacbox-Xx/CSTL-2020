//
//  Cmap.c
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/21.
//  Copyright © 2020 李远铄. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "Cmap.h"
#include "Cstandard.h"
Node_Map* New_Node_Map(void);
bool Compare_Ele(TYPE_KEY a,TYPE_KEY b);
void Map_Create(map* tree);
bool Map_Insert(map* tree,TYPE_KEY key,TYPE_VALUE value);//返回是否已经存在
bool Map_Node_Insert(Node_Map* n,TYPE_KEY key,TYPE_VALUE value);
bool Map_Find(map* tree,TYPE_KEY key,TYPE_VALUE* value);
bool Map_Node_Find(Node_Map* now,TYPE_KEY key,TYPE_VALUE* value);
void Map_DelKey(map* tree,TYPE_KEY key);
void Map_Node_DelKey(Node_Map* last,Node_Map* now,TYPE_KEY key);
void Map_Print(map* tree);//从小到大，就是DFS中序
void Map_Node_Print(Node_Map* now);//注意如果是打印字符串的话需要改函数
void Map_TYPE_Print(Node_Map* n);//自定义打印模式
void Map_Del(map* tree);
void Map_Node_Del(Node_Map* now);

bool Map_Insert(map* tree,TYPE_KEY key,TYPE_VALUE value){
    Node_Map* n=tree->root;
    if (n==NULL) {
        Node_Map* d=New_Node_Map();
        tree->head->left=d;
        d->key=key;
        d->value=value;
        tree->root=d;
        return FALSE;
    }
    return Map_Node_Insert(n, key,value);
}
bool Map_Node_Insert(Node_Map* n, TYPE_KEY key,TYPE_VALUE value){
    if (Compare_Ele(key, n->key)) {//ele<n->value
        if (n->left==NULL) {
            Node_Map* new_n=New_Node_Map();
            new_n->key=key;
            new_n->value=value;
            n->left=new_n;
            return FALSE;
        }else{
            return Map_Node_Insert(n->left, key,value);
        }
    }else if(Compare_Ele(n->key, key)){
        if (n->right==NULL) {
            Node_Map* new_n=New_Node_Map();
            new_n->key=key;
            new_n->value=value;
            n->right=new_n;
            return FALSE;
        }else{
            return Map_Node_Insert(n->right, key,value);
        }
    }else{//两者相等
        n->value=value;
        return TRUE;
    }
}
bool Map_Find(map* tree,TYPE_KEY key,TYPE_VALUE* value){
    Node_Map* n=tree->root;
    if (n==NULL) {
        return FALSE;
    }else{
        return Map_Node_Find(n, key,value);
    }
}
bool Map_Node_Find(Node_Map* now,TYPE_KEY key,TYPE_VALUE* value){
    if (Compare_Ele(key, now->key)) {//ele<now->value
        if (now->left==NULL) {
            return FALSE;
        }else{
            return Map_Node_Find(now->left, key,value);
        }
    }else if(Compare_Ele(now->key, key)){
        if (now->right==NULL) {
            return FALSE;
        }else{
            return Map_Node_Find(now->right, key,value);
        }
    }else{
        *value=now->value;
        return TRUE;
    }
}
void Map_DelKey(map* tree,TYPE_KEY key){
    Node_Map* now=tree->root;
    if (now==NULL) {
        return;
    }else{
        Map_Node_DelKey(tree->head,now, key);
    }
    tree->root=tree->head->left;
}
void Map_Node_DelKey(Node_Map* last,Node_Map* now,TYPE_KEY key){
    if (Compare_Ele(key, now->key)) {//ele<now->value
        if (now->left==NULL) {
            return;
        }else{
            Map_Node_DelKey(now,now->left, key);
        }
    }else if(Compare_Ele(now->key, key)){
        if (now->right==NULL) {
            return;
        }else{
            Map_Node_DelKey(now,now->right, key);
        }
    }else{
        Node_Map* to_del=now;
        if (last->left==now) {
            if (now->right!=NULL) {
                last->left=now->right;
                now=now->right;
                for (; now->left!=NULL; now=now->left);
                now->left=to_del->left;
            }else if(now->left!=NULL){
                last->left=now->left;
                now=now->left;
                for (; now->right!=NULL; now=now->right);
                now->right=to_del->right;
            }else{
                last->left=NULL;
            }
        }else{
            if (now->right!=NULL) {
                last->right=now->right;
                now=now->right;
                for (; now->left!=NULL; now=now->left);
                now->left=to_del->left;
            }else if(now->left!=NULL){
                last->right=now->left;
                now=now->left;
                for (; now->right!=NULL; now=now->right);
                now->right=to_del->right;
            }else{
                last->right=NULL;
            }
        }
        free(to_del);
    }
}
void Map_Print(map* tree){
    if (tree->root!=NULL) {
        Map_Node_Print(tree->root);
    }
    return;
}
void Map_Node_Print(Node_Map* now){
    if (now->left!=NULL) {
        Map_Node_Print(now->left);
    }
    Map_TYPE_Print(now);
    if (now->right!=NULL) {
        Map_Node_Print(now->right);
    }
}
void Map_Del(map* tree){
    Node_Map* now=tree->root;
    if (now!=NULL) {
        Map_Node_Del(now);
    }
    tree->head->left=NULL;
    tree->root=NULL;
}
void Map_Node_Del(Node_Map* now){
    if (now->left!=NULL) {
        Map_Node_Del(now->left);
    }
    if (now->right!=NULL) {
        Map_Node_Del(now->right);
    }
    free(now);
}
Node_Map* New_Node_Map(void){
    Node_Map* n=(Node_Map*)malloc(sizeof(Node_Map));
    if (n==NULL) {
        printf("ERROR IN NEW A MAP NODE\n");
        exit(ERROR);
    }
    n->left=NULL;
    n->right=NULL;
    n->key=0;n->value=0;
    return n;
}
bool Compare_Ele(TYPE_KEY a,TYPE_KEY b){
    return a<b;
}
void Map_Create(map* tree){
    tree->root=NULL;
    tree->head=New_Node_Map();
    tree->head->left=tree->root;
}
void Map_TYPE_Print(Node_Map* x){
    printf("%d %d/",x->key,x->value);
}
