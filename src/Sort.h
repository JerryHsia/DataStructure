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

/**
 希尔排序算法
 核心概要：先根据增量进行跳跃比较插入，使数据基本有序，最后进行一次完整的插入排序，由于已经基本有序，交换次数将大大减少
 时间复杂度：O(n的3/2次方)
 */
void shell_sort(LIST* list) {
    int i, j, temp;
    int increment = list->length;
    
    do {
        increment = increment/3 + 1;// increment > 1时跳跃比较进行插入，increment = 1时就是插入排序
        for (i = increment; i < list->length; i++) {
            if (list->datas[i] < list->datas[i - increment]) {
                temp = list->datas[i];
                for (j = i - increment; j >= 0 && temp < list->datas[j];j -= increment) {
                    list->datas[j + increment] = list->datas[j];
                }
                list->datas[j + increment] = temp;
            }
        }
    } while (increment > 1);
}

// 构造堆
void heap_build(LIST* list, int s, int m) {
    int temp, j;
    temp = list->datas[s];
    for (j = 2*s; j <= m; j *= 2) {
        if (j < m && list->datas[j] < list->datas[j + 1]) {
            j++;
        }
        if (temp >= list->datas[j]) {
            break;
        }
        list->datas[s] = list->datas[j];
        s = j;
    }
    list->datas[s] = temp;
}

/**
 堆排序算法
 核心概要：将待排序的序列构造成一个大顶堆，此时整个序列的最大值就是堆顶的根节点
        将它移走，然后将剩余的n-1个序列重新构造成一个堆，这样又得到堆顶的根节点为最大值
        如此反复。
 */
void heap_sort(LIST* list) {
    int i;
    for (i = list->length/2; i >= 1; i--) {
        heap_build(list, i, list->length - 1);
    }
    
    for (i = list->length - 1; i > 1; i--) {
        swap(list, 1, i); // 将根节点的数交换到尾部
        heap_build(list, 1, i - 1); // 重新构造堆
    }
}

void merge(int SR[], int TR[], int i, int m, int n) {
    int j,k,l;
    for (j = m + 1,k=i; i <= m && j <= n; k++) {
        if (SR[i] < SR[j]) {
            TR[k] = SR[i++];
        } else {
            TR[k] = SR[j++];
        }
    }
    if (i <= m) {
        for (l = 0; l <= m - i; l++) {
            TR[k + 1] = SR[i + 1];
        }
    }
    if (j <= n) {
        for (l = 0; l <= n - j; l++) {
            TR[k + 1] = SR[j + 1];
        }
    }
}

void m_sort(int SR[], int TR1[], int s, int t) {
    int m;
    int TR2[MAX_SIZE + 1];
    if (s == t) {
        TR1[s] = SR[s];
    } else {
        m = (s + t) / 2;
        m_sort(SR, TR2, s, m);
        m_sort(SR, TR2, m + 1, t);
        merge(TR2, TR1, s, m, t);
    }
}

void merge_sort(LIST* list) {
    m_sort(list->datas, list->datas, 0, list->length);
}

#endif
