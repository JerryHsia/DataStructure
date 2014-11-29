//
//  main.c
//  DataStructure
//
//  Created by Jerry Hsia on 11/06/14.
//  Copyright (c) 2013 Jerry Hsia. All rights reserved.
//
/*
#include <stdio.h>
#include <stdlib.h>
#include "Public.h"
#include "DCircLinkList.h"

int main(int argc, const char * argv[]) {
    
    // 头插法
    CLIST circLinkList0 = c_init();
    for (int i = 0; i < 5; i++) {
        c_add(circLinkList0, 0, i);
    }
    c_print(circLinkList0);
    
    // 尾插法
    CLIST circLinkList = c_init();
    for (int i = 0; i < 5; i++) {
        c_add(circLinkList, c_length(circLinkList), i);
    }
    c_print(circLinkList);
    
    c_add(circLinkList, 3, 5);
    c_print(circLinkList);
    
    printf("%d\n", c_get(circLinkList, 5));
    c_print(circLinkList);
    
    c_delete(circLinkList, 1);
    c_print(circLinkList);
    
    c_clear(circLinkList);
    c_print(circLinkList);
    return 0;
}
*/