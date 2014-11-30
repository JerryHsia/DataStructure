//
//  BinTree.h
//  DataStructure
//
//  Created by Jerry Hsia on 11/15/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#ifndef __DataStructure__BinTree__
#define __DataStructure__BinTree__

#include <stdio.h>

typedef struct BinTreeNode {
    int data;
    struct BinTreeNode* left;// 左子树
    struct BinTreeNode* right;// 右子树
} BNODE, BINTREE;

// 初始化树(先序的方式)
BINTREE* t_init() {
    int input = 1;
    scanf("%d", &input);
    if (input != -1) {
        BINTREE* tree = (BINTREE*)malloc(sizeof(BINTREE));
        tree->data = input;
        tree->left = t_init();
        tree->right = t_init();
        return tree;
    } else {
        return NULL;
    }
}

// 先序遍历
int t_foreach_1(BINTREE* tree) {
    if (tree == NULL) return ERROR;
    printf("%d\n", tree->data);
    t_foreach_1(tree->left);
    t_foreach_1(tree->right);
    return SUCCESS;
}

// 中序遍历
int t_foreach_2(BINTREE* tree) {
    if (tree == NULL) return ERROR;
    t_foreach_2(tree->left);
    printf("%d\n", tree->data);
    t_foreach_2(tree->right);
    return SUCCESS;
}

// 后序遍历
int t_foreach_3(BINTREE* tree) {
    if (tree == NULL) return ERROR;
    t_foreach_3(tree->left);
    t_foreach_3(tree->right);
    printf("%d\n", tree->data);
    return SUCCESS;
}

// 清空树
int t_clear(BINTREE* tree) {
    if (tree == NULL) return ERROR;
    t_clear(tree->left);
    t_clear(tree->right);
    free(tree);
    tree = NULL;
    return SUCCESS;
}

#endif /* defined(__DataStructure__BinTree__) */
