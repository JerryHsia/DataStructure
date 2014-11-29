//
//  StaticLinkList.h
//  DataStructure
//
//  Created by Jerry Hsia on 04/11/14.
//  Copyright (c) 2013 Jerry Hsia. All rights reserved.
//

#ifndef DataStructure_StaticLinkList_h
#define DataStructure_StaticLinkList_h
#define MAX_SIZE 7

typedef struct StaticLinkListNode {
    int data;
    int cur; // 后继元素在数组中的索引
} SNODE, StaticLinkList[MAX_SIZE];

// 初始化链表
void s_init(StaticLinkList list) {
    for (int i = 0; i < MAX_SIZE; i++) {
        list[i].cur = i + 1;// 默认元素在数组中的位置连续
        list[i].data = 0;
    }
    list[MAX_SIZE - 1].cur = 0;// 数组最后一个元素作为链表的头结点，cur保存链表第一个元素在数组中的位置，0代表链表为空
}

// 分配存储位置
int s_malloc(StaticLinkList list) {
    int cur = list[0].cur;
    if (cur) {
        list[0].cur = list[cur].cur;
    }
    list[0].data++; // 将第一个数组元素的data字段用于存放链表长度
    return cur;
}

// 释放存储位置
void s_free(StaticLinkList list, int cur) {
    list[cur].data = 0;
    list[cur].cur = list[0].cur;
    list[0].cur = cur;
    list[0].data--;
}

// 获取链表长度
int s_length(StaticLinkList list) {
    return list[0].data;// 数组第一个元素数据域存储链表长度
}

// 打印链表
void s_print(StaticLinkList list) {
    printf("--打印链表，当前链表长度：%d\n", s_length(list));
    SNODE node = list[MAX_SIZE - 1];
    while (node.cur != 0) {
        printf("%d\n", list[node.cur].data);
        node = list[node.cur];
    }
}

// 打印原始数组
void s_print_array(StaticLinkList list) {
    printf("--打印原始数组\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("index:%d data:%d cur:%d \n", i, list[i].data, list[i].cur);
    }
}

// 添加一个元素
int s_add(StaticLinkList list, unsigned int index, unsigned int data) {
    printf("--在 %d 位置插入 %d\n", index, data);
    if (s_length(list) == MAX_SIZE - 2 || index > s_length(list)) return ERROR;
    int i = 0;
    int position = MAX_SIZE - 1;
    SNODE node = list[position];
    while (i < index) {
        position = node.cur;
        node = list[position];
        i++;
    }
    int next_cur = s_malloc(list);
    list[next_cur].data = data;
    list[next_cur].cur  = node.cur;
    list[position].cur = next_cur;
    return SUCCESS;
}

// 删除一个元素
int s_delete(StaticLinkList list, unsigned int index) {
    printf("--删除第 %d 个元素\n", index);
    if (index > s_length(list) - 1) return ERROR;
    int i = 0;
    int position = MAX_SIZE - 1;
    SNODE node = list[position];
    while (i < index) {
        position = node.cur;
        node = list[position];
        i++;
    }
    list[position].cur = list[node.cur].cur;
    s_free(list, node.cur);
    return SUCCESS;
}

#endif