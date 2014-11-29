//
//  CircLinkList.h
//  DataStructure
//
//  Created by Jerry Hsia on 15/06/13.
//  Copyright (c) 2013 Jerry Hsia. All rights reserved.
//

#ifndef DataStructure_CircLinkList_h
#define DataStructure_CircLinkList_h

typedef struct CircLinkListNode {
    int data;
    struct CircLinkListNode* next;
} CNODE;

struct CircLinkList {
    CNODE* rear;
};

typedef struct CircLinkList* CLIST;

// 初始化链表
CLIST c_init() {
    CLIST circLinkList = (CLIST)malloc(sizeof(CLIST));
    CNODE* node = (CNODE*)malloc(sizeof(CNODE));
    node->data = 0;// 头结点数据域存储链表长度
    node->next = node;// 头结点指针指向头结点
    circLinkList->rear = node;// 尾指针指向头结点
    return circLinkList;
}

// 获取链表长度
int c_length(CLIST list) {
    return list->rear->next->data;
}

// 打印链表
void c_print(CLIST list) {
    printf("--打印链表，链表长度：%d\n", c_length(list));
    CNODE* node = list->rear->next;
    while (node->next != list->rear->next) {
        printf("%d\n", node->next->data);
        node = node->next;
    }
}

// 添加一个元素到index位置
int c_add(CLIST list, unsigned int index, int data) {
    printf("--在%d位置插入%d\n", index, data);
    if (index > c_length(list)) {
        return ERROR;
    }
    CNODE* newNode = (CNODE*)malloc(sizeof(CNODE));
    newNode->data = data;
    if (index == c_length(list)) {// 在末尾插入，直接在尾节点后插入，时间复杂度O(1)
        newNode->next = list->rear->next;// 新节点的指针域指向头结点
        list->rear->next = newNode;// 旧的尾节点指针域指向新节点
        list->rear = newNode;// 尾指针指向新节点
        list->rear->next->data++;// 链表长度加1
    } else {
        CNODE* node = list->rear->next;
        int i = 0;
        while (i < index) {
            node = node->next;
            i++;
        }
        newNode->next = node->next;
        node->next = newNode;
        list->rear->next->data++;
        return SUCCESS;
    }
    return ERROR;
}

// 获取第index个元素
int c_get(CLIST list, unsigned int index) {
    printf("--获取%d位置的元素\n", index);
    if (index > c_length(list) - 1) {
        return ERROR;
    }
    if (index == c_length(list) - 1) {// 充分利用尾指针的优势
        return list->rear->data;
    } else {
        CNODE* node = list->rear->next;
        int i = 0;
        while (i < index) {
            node = node->next;
            i++;
        }
        return node->next->data;
    }
}

// 删除一个元素
int c_delete(CLIST list, unsigned int index) {
    printf("--删除%d位置元素\n", index);
    if (index > c_length(list) - 1) {
        return ERROR;
    }
    int i = 0;
    CNODE* node = list->rear->next;
    while (i < index) {
        node = node->next;
        i++;
    }
    CNODE* deleteNode = node->next;
    int data = deleteNode->data;
    node->next = deleteNode->next;
    free(deleteNode);
    list->rear->next->data--;
    return data;
}

// 清空
void c_clear(CLIST list) {
    printf("--清空链表\n");
    CNODE* head = list->rear->next;
    CNODE* node = head;
    while (node->next != head) {
        CNODE* nextNode = node->next->next;
        free(node->next);
        node->next = nextNode;
    }
    list->rear = head;
    head->data = 0;
}
#endif
