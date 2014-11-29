//
//  Stack.h
//  DataStructure
//
//  Created by Jerry Hsia on 11/29/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#ifndef __DataStructure__Stack__
#define __DataStructure__Stack__

typedef struct StackNode {
    int data;
    struct StackNode* next;
} SNODE;

typedef struct Stack {
    SNODE* top;// 指向栈顶元素
    int length;// 栈的长度
} STACK;

// 初始化栈
STACK* s_init() {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->top = NULL;
    stack->length = 0;
    return stack;
}

// 打印栈
int s_print(STACK* stack) {
    SNODE* node = stack->top;
    printf("当前栈的长度：%d\n", stack->length);
    while (node) {
        printf("%d\n", node->data);
        node = node->next;
    }
    return SUCCESS;
}

// 获取栈的长度
int s_length(STACK* stack) {
    return stack->length;
}

// 入栈
int s_push(STACK* stack, int data) {
    printf("--%d入栈\n", data);
    SNODE* node = (SNODE*)malloc(sizeof(SNODE));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->length++;
    return SUCCESS;
}

// 出栈
int s_pop(STACK* stack) {
    if (s_length(stack) == 0) return ERROR;
    SNODE* node = stack->top;
    int data = node->data;
    stack->top = node->next;
    stack->length--;
    free(node);
    printf("--%d出栈\n", data);
    return data;
}

// 清空
int s_clear(STACK* stack) {
    if (s_length(stack) == 0) return ERROR;
    printf("--清空栈\n");
    while (stack->top) {
        SNODE* next = stack->top->next;
        free(stack->top);
        stack->top = next;
    }
    stack->length = 0;
    return SUCCESS;
}

#endif /* defined(__DataStructure__Stack__) */
