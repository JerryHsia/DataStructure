//
//  BiTree.c
//  DataStructure
//
//  Created by Jerry Hsia on 11/15/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Public.h"
#include "BiTree.h"

int main(int argc, const char * argv[]) {
    
    BITREE* tree2 = (BITREE*)malloc(sizeof(BITREE));
    tree2->data = 2;
    tree2->left = NULL;
    tree2->right = NULL;
    
    BITREE* tree3 = (BITREE*)malloc(sizeof(BITREE));
    tree3->data = 3;
    tree3->left = NULL;
    tree3->right = NULL;
    
    BITREE* tree = (BITREE*)malloc(sizeof(BITREE));
    tree->data = 1;
    tree->left = tree2;
    tree->right = tree3;
    
    printf("--先序遍历\n");
    t_pre_foreach_1(tree);
    
    printf("--先序遍历(非递归)\n");
    t_pre_foreach_2(tree);
    
    printf("--中序遍历\n");
    t_in_foreach_1(tree);
    
    printf("--中序遍历(非递归)\n");
    t_in_foreach_2(tree);
    
    printf("--后序遍历\n");
    t_post_foreach_1(tree);
    
    printf("--后序遍历(非递归)\n");
    t_post_foreach_2(tree);
    
    printf("--后序遍历(非递归)\n");
    t_post_foreach_3(tree);

    
    t_clear(tree);

    return 0;
}



