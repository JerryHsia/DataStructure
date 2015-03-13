//
//  HuffCode
//  DataStructure
//
//  Created by Jerry Hsia on 11/16/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Public.h"
#include "HuffCode.h"
 
int main(int argc, const char * argv[]) {
    
    char* string = "abcdeffebcacc";
    
    create_tree(string);
    
    return 0;
}