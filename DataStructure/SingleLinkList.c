//
//  main.c
//  DataStructure
//
//  Created by Jerry Hsia on 03/11/14.
//  Copyright (c) 2013 Jerry Hsia. All rights reserved.
//
/*
#include <stdio.h>
#include <stdlib.h>
#include "Public.h"
#include "SingleLinkList.h"

int main(int argc, const char * argv[]) {
    
    // 头插法
    SLIST singleLinkList0 = s_init();
    for (int i = 0; i < 5; i++) {
        s_add(singleLinkList0, 0, i);
    }
    s_print(singleLinkList0);
    
    // 尾插法
    SLIST singleLinkList = s_init();
    SNODE* endNode = singleLinkList;
    for (int i = 0; i < 5; i++) {
        SNODE* node = (SNODE*)malloc(sizeof(SNODE));
        node->data = i;
        endNode->next = node;
        endNode = node;
        singleLinkList->data++;
    }
    
    s_print(singleLinkList);
    
    s_add(singleLinkList, 3, 5);
    s_print(singleLinkList);
    
    printf("%d\n", s_get(singleLinkList, 3));
    s_print(singleLinkList);
    
    s_delete(singleLinkList, 1);
    s_print(singleLinkList);
    
    s_clear(singleLinkList);
    s_print(singleLinkList);
    
    return 0;
}
*/