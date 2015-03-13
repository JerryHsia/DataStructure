//
//  Stack.c
//  DataStructure
//
//  Created by Jerry Hsia on 11/10/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Public.h"
#include "Stack.h"

int main(int argc, const char * argv[]) {
    
    STACK* stack = s_init();
    for (int i = 0; i < 5; i++) {
        s_push(stack, i);
    }
    s_print(stack);
    
    s_pop(stack);
    s_print(stack);
    
    s_clear(stack);
    s_print(stack);
    
    return 0;
}
