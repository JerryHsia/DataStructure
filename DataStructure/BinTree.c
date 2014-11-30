//
//  BinTree.c
//  DataStructure
//
//  Created by Jerry Hsia on 11/15/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Public.h"
#include "BinTree.h"

int main(int argc, const char * argv[]) {
    BINTREE* tree = t_init();
    
    printf("--先序遍历\n");
    t_foreach_1(tree);
    
    printf("--中序遍历\n");
    t_foreach_2(tree);
    
    printf("--后序遍历\n");
    t_foreach_3(tree);
    
    t_clear(tree);

    return 0;
}




