//
//  Sort.h
//  DataStructure
//
//  Created by Jerry Hsia on 11/20/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#ifndef DataStructure_Header_h
#define DataStructure_Header_h
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

typedef struct list {
    int datas[MAX_SIZE];
    int length;
} LIST;

// 初始化链表
LIST* init(int* array, int length) {
    length = length < MAX_SIZE ? length : MAX_SIZE;
    LIST* list = (LIST*)malloc(sizeof(LIST));
    list->length = length;
    for (int i = 0; i < length; i++) {
        list->datas[i] = array[i];
    }
    return list;
}

// 交换数组中的两个数
void swap(LIST* list, int i, int j) {
    int temp;
    temp = list->datas[i];
    list->datas[i] = list->datas[j];
    list->datas[j] = temp;
}

// 打印链表
void print(LIST* list) {
    printf("==打印链表\n");
    for (int i = 0; i < list->length; i++) {
        printf("%d\n", list->datas[i]);
    }
}

/**
 冒泡排序算法
 核心概要：进行双重循环，外循环一次将本次循环中的最小数置顶
 时间复杂度：n*(n-1)/2即O(n*n)
 */
void bubble_sort(LIST* list) {
    int flag = 1; // 0表示已排好序
    for (int i = 0; i < list->length && flag; i++) {
        flag = 0;
        for (int j = list->length - 1; j > i; j--) {
            if (list->datas[j] < list->datas[j - 1]) {
                flag = 1; // 若未执行到此处证明已经排好序(flag=0)，循环终止
                swap(list, j, j - 1);
            }
        }
        // 每一次外循环结束，相对最小的数置顶到i位置
    }
}

/**
 选择排序算法
 核心概要：进行双重循环，每一次外循环过程中如选出了最小的数，交换到顶部
 时间复杂度：O(n*n)
 */
void select_sort(LIST* list) {
    int min;
    for (int i = 0; i < list->length; i++) {
        min = i;// 将i位置约定为本次循环中最小的树
        for (int j = i + 1; j < list->length; j++) {
            if (list->datas[j] < list->datas[min]) {
                min = j;
            }
        }
        if (min != i) {// 如果有比i位置更小的树，则交换
            swap(list, i, min);
        }
    }
}

/**
 插入排序算法
 核心概要：将新值插入已经排好的序列的正确位置中
 时间复杂度：O(n*n)
 */
void insert_sort(LIST* list) {
    int i, j;
    for (i = 1; i < list->length; i++) {
        int temp = list->datas[i];// 需要插入的数
        for (j = i - 1; list->datas[j] > temp && j >= 0; j--) {
            list->datas[j + 1] = list->datas[j];// 右移比temp大的数
        }
        list->datas[j + 1] = temp;
    }
}

#endif
