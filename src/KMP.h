//
//  kmp.h
//  DataStructure
//
//  Created by Jerry Hsia on 11/14/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#ifndef __DataStructure__kmp__
#define __DataStructure__kmp__

typedef char* String;

// 打印next数组
void print_next(int* next, int length) {
    int i = 0;
    while (i < length) {
        printf("next[%d]=%d\n", i, next[i]);
        i++;
    }
}

// 获取next数组
void get_next(String T, int* next) {
    int i = 0,j = -1;
    next[0] = j;
    int length = strlen(T);
    
    while (i < length) {
        if (j == -1 || T[i] == T[j]) {
            ++i;
            ++j;
            next[i] = j;
            /* 更优化的next数组
            if (T[i] != T[j]) {
                next[i] = j;
            } else {
                next[i] = next[j];
            }*/
        } else {
            j = next[j];
        }
    }
}

// 找出T在S中第一次出现的位置
int index_kmp(String S, String T) {
    int i = 0;
    int j = 0;
    int next[255];
    get_next(T, next);
    print_next(next, strlen(T));
    int s_length = strlen(S);
    int t_length = strlen(T);
    
    while (i < s_length && j < t_length) {
        if (j == -1 || S[i] == T[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == t_length) {
        return i - t_length;
    } else {
        return 0;
    }
}

#endif /* defined(__DataStructure__kmp__) */
