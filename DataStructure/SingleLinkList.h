//
//  SingleLinkList.h
//  DataStructure
//
//  Created by Jerry Hsia on 11/06/13.
//  Copyright (c) 2013 Jerry Hsia. All rights reserved.
//

#ifndef DataStructure_SingleLinkList_h
#define DataStructure_SingleLinkList_h

typedef struct SingleLinkListNode {
    int data;
    struct SingleLinkListNode* next;
} SNODE;

typedef struct SingleLinkListNode* SLIST;

// 初始化链表
SLIST s_init() {
    SLIST list = (SLIST)malloc(sizeof(SNODE));
    list->data = 0;// 头结点数据域存储链表长度
    return list;
}

// 获取链表长度
int s_length(SLIST list) {
    return list->data;
}

// 打印单链表
void s_print(SLIST list) {
    printf("--打印链表，当前链表长度%d\n", s_length(list));
    SNODE* node = list;
    while (node->next) {
        printf("%d\n", node->next->data);
        node = node->next;
    }
}

// 添加一个元素到index位置
int s_add(SLIST list, int index, int data) {
    printf("--在%d位置插入%d\n", index, data);
    if (index > s_length(list)) {
        return ERROR;
    }
    SNODE* node = list;
    int i = 0;
    while (i < index && node->next) {
        node = node->next;
        i++;
    }
    SNODE* newNode = (SNODE*)malloc(sizeof(SNODE));
    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;
    
    list->data++;
    return SUCCESS;
}

// 获取第index个元素
int s_get(SLIST list, unsigned int index) {
    printf("--获取第%d个元素\n", index);
    if (index > s_length(list) - 1) {
        return ERROR;
    }
    SNODE* node = list;
    int i = 0;
    while (i <= index && node->next) {
        node = node->next;
        i++;
    }
    return node->data;
}

// 删除一个元素
int s_delete(SLIST list, unsigned int index) {
    printf("--删除第%d个元素\n", index);
    int length = s_length(list);
    if (index > length - 1 || length == 0) {
        return ERROR;
    }
    SNODE* node = list;
    int i = 0;
    while (i < index && node->next) {
        node = node->next;
        i++;
    }
    SNODE* deleteNode = node->next;
    if (deleteNode->next) {
        node->next = deleteNode->next;
    } else {
        node->next = NULL;
    }
    
    list->data--;
    return deleteNode->data;
}

// 清空
void s_clear(SLIST list) {
    SNODE* node = list->next;
    while (node) {
        SNODE* next = node->next;
        free(node);
        node = next;
    }
    list->data = 0;
    list->next = NULL;
}
#endif
