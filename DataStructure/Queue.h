//
//  Queue.h
//  DataStructure
//
//  Created by Jerry Hsia on 11/13/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#ifndef __DataStructure__Queue__
#define __DataStructure__Queue__

typedef struct Qnode {
    int data;
    struct Qnode* next;
} QNODE;

typedef struct Queue {
    QNODE* front;// 指向第一个节点
    QNODE* rear;// 指向最后一个节点
    int length;// 队列长度
} QUEUE;

// 初始化队列
QUEUE* q_init() {
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->length = 0;
    return queue;
}

// 获取队列长度
int q_length(QUEUE* queue) {
    return queue->length;
}

// 打印队列
int q_print(QUEUE* queue) {
    printf("当前队列长度：%d\n", q_length(queue));
    QNODE* node = queue->front;
    while (node) {
        printf("%d\n", node->data);
        node = node->next;
    }
    return SUCCESS;
}

// 入队
int q_enter(QUEUE* queue, int data) {
    printf("--%d入队\n", data);
    QNODE* node = (QNODE*)malloc(sizeof(QNODE));
    node->data = data;
    node->next = NULL;
    if (q_length(queue) == 0) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->length++;
    return SUCCESS;
}

// 出队
int q_quit(QUEUE* queue) {
    if (q_length(queue) == 0) return ERROR;
    QNODE* node = queue->front;
    if (node == queue->rear) queue->rear = NULL;// 如果出队的是尾节点，尾节点指针清空
    queue->front = node->next;
    printf("--%d出队\n", node->data);
    free(node);
    queue->length--;
    return SUCCESS;
}

// 清空
int q_clear(QUEUE* queue) {
    if (q_length(queue) == 0) return ERROR;
    while (queue->front) {
        QNODE* next = queue->front->next;
        free(queue->front);
        queue->front = next;
    }
    queue->rear = NULL;
    queue->length = 0;
    return SUCCESS;
}

#endif /* defined(__DataStructure__Queue__) */
