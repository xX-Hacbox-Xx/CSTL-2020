//
//  Cset.c
//  BFS走迷宫 C语言 利用自定义STL
//
//  Created by 李远铄 on 2020/4/21.
//  Copyright © 2020 李远铄. All rights reserved.
//

#include "Cset.h"
#include <stdio.h>
#include <stdlib.h>
Node_Set* New_Node_Set(void);
bool Set_Compare_Ele(TYPE_SET a,TYPE_SET b);
void Set_Create(set* tree);
bool Set_Insert(set* tree,TYPE_SET ele);//返回是否已经存在
bool Set_Node_Insert(Node_Set* n,TYPE_SET ele);
bool Set_Find(set* tree,TYPE_SET ele);
bool Set_Node_Find(Node_Set* now,TYPE_SET ele);
void Set_DelValue(set* tree,TYPE_SET ele);
void Set_Node_DelValue(Node_Set* last,Node_Set* now,TYPE_SET ele);
void Set_Print(set* tree);//从小到大，就是DFS中序
void Set_Node_Print(Node_Set* now);//注意如果是打印字符串的话需要改函数
void Set_TYPE_Print(TYPE_SET x);//自定义打印模式
void Set_Del(set* tree);
void Set_Node_Del(Node_Set* now);

bool Set_Insert(set* tree,TYPE_SET ele){
    Node_Set* n=tree->root;
    if (n==NULL) {
        Node_Set* d=New_Node_Set();
        tree->head->left=d;
        d->value=ele;
        tree->root=d;
        return FALSE;
    }
    return Set_Node_Insert(n, ele);
}
bool Set_Node_Insert(Node_Set* n, TYPE_SET ele){
    if (Set_Compare_Ele(ele, n->value)) {//ele<n->value
        if (n->left==NULL) {
            Node_Set* new_n=New_Node_Set();
            new_n->value=ele;
            n->left=new_n;
            return FALSE;
        }else{
            return Set_Node_Insert(n->left, ele);
        }
    }else if(Set_Compare_Ele(n->value, ele)){
        if (n->right==NULL) {
            Node_Set* new_n=New_Node_Set();
            new_n->value=ele;
            n->right=new_n;
            return FALSE;
        }else{
            return Set_Node_Insert(n->right, ele);
        }
    }else{//两者相等
        return TRUE;
    }
}
bool Set_Find(set* tree,TYPE_SET ele){
    Node_Set* n=tree->root;
    if (n==NULL) {
        return FALSE;
    }else{
        return Set_Node_Find(n, ele);
    }
}
bool Set_Node_Find(Node_Set* now,TYPE_SET ele){
    if (Set_Compare_Ele(ele, now->value)) {//ele<now->value
        if (now->left==NULL) {
            return FALSE;
        }else{
            return Set_Node_Find(now->left, ele);
        }
    }else if(Set_Compare_Ele(now->value, ele)){
        if (now->right==NULL) {
            return FALSE;
        }else{
            return Set_Node_Find(now->right, ele);
        }
    }else{
        return TRUE;
    }
}
void Set_DelValue(set* tree,TYPE_SET ele){
    Node_Set* now=tree->root;
    if (now==NULL) {
        return;
    }else{
        Set_Node_DelValue(tree->head,now, ele);
    }
    tree->root=tree->head->left;
}
void Set_Node_DelValue(Node_Set* last,Node_Set* now,TYPE_SET ele){
    if (Set_Compare_Ele(ele, now->value)) {//ele<now->value
        if (now->left==NULL) {
            return;
        }else{
            Set_Node_DelValue(now,now->left, ele);
        }
    }else if(Set_Compare_Ele(now->value, ele)){
        if (now->right==NULL) {
            return;
        }else{
            Set_Node_DelValue(now,now->right, ele);
        }
    }else{
        Node_Set* to_del=now;
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
        return;
    }
}
void Set_Print(set* tree){
    if (tree->root!=NULL) {
        Set_Node_Print(tree->root);
    }
    return;
}
void Set_Node_Print(Node_Set* now){
    if (now->left!=NULL) {
        Set_Node_Print(now->left);
    }
    Set_TYPE_Print(now->value);
    if (now->right!=NULL) {
        Set_Node_Print(now->right);
    }
}
void Set_Del(set* tree){
    Node_Set* now=tree->root;
    if (now!=NULL) {
        Set_Node_Del(now);
    }
    tree->head->left=NULL;
    tree->root=NULL;
}
void Set_Node_Del(Node_Set* now){
    if (now->left!=NULL) {
        Set_Node_Del(now->left);
    }
    if (now->right!=NULL) {
        Set_Node_Del(now->right);
    }
    free(now);
}
Node_Set* New_Node_Set(void){
    Node_Set* n=(Node_Set*)malloc(sizeof(Node_Set));
    if (n==NULL) {
        printf("ERROR IN NEW A SET NODE\n");
        exit(ERROR);
    }
    n->left=NULL;n->right=NULL;n->value=0;
    return n;
}
bool Set_Compare_Ele(TYPE_SET a,TYPE_SET b){
    return a<b;
}
void Set_Create(set* tree){
    tree->root=NULL;
    tree->head=New_Node_Set();
    tree->head->left=tree->root;
}
void Set_TYPE_Print(TYPE_SET x){
    printf("%d ",x);
}

