//
//  BiTree.h
//  DataStructure
//
//  Created by Jerry Hsia on 11/15/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#ifndef __DataStructure__BiTree__
#define __DataStructure__BiTree__

typedef struct BiTreeNode {
    int data;
    struct BiTreeNode* left;// 左子树
    struct BiTreeNode* right;// 右子树
} BNODE, BITREE;

typedef struct BiTreeStackNode {
    BNODE* data;
    int is_first;
    struct BiTreeStackNode* next;
} BSNODE;

typedef struct Stack {
    BSNODE* top;// 指向栈顶元素
    int length;// 栈的长度
} STACK;

// 初始化栈
STACK* s_init() {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->top = NULL;
    stack->length = 0;
    return stack;
}

// 入栈
int s_push(STACK* stack, BSNODE* sNode) {
    sNode->next = stack->top;
    stack->top = sNode;
    stack->length++;
    return SUCCESS;
}

// 出栈
int s_pop(STACK* stack) {
    if (stack->length == 0) return ERROR;
    BSNODE* sNode = stack->top;
    stack->top = sNode->next;
    stack->length--;
    return SUCCESS;
}

// 初始化树(先序的方式)
BITREE* t_init() {
    int input = 1;
    scanf("%d", &input);
    if (input != -1) {
        BITREE* tree = (BITREE*)malloc(sizeof(BITREE));
        tree->data = input;
        tree->left = t_init();
        tree->right = t_init();
        return tree;
    } else {
        return NULL;
    }
}

// 先序遍历
int t_pre_foreach_1(BITREE* tree) {
    if (tree == NULL) return ERROR;
    printf("%d\n", tree->data);
    t_pre_foreach_1(tree->left);
    t_pre_foreach_1(tree->right);
    return SUCCESS;
}

// 先序遍历(非递归)
int t_pre_foreach_2(BITREE* tree) {
    STACK* stack = s_init();
    BNODE* node = tree;
    while (node != NULL || stack->length != 0) {
        while (node != NULL) {
            printf("%d\n", node->data);
            BSNODE* sNode = (BSNODE*)malloc(sizeof(BSNODE));
            sNode->data = node;
            s_push(stack, sNode);
            node = node->left;
        }
        if (stack->length != 0) {
            BSNODE* sNode = stack->top;
            s_pop(stack);
            node = sNode->data;
            node = node->right;
        }
    }
    return SUCCESS;
}

// 中序遍历
int t_in_foreach_1(BITREE* tree) {
    if (tree == NULL) return ERROR;
    t_in_foreach_1(tree->left);
    printf("%d\n", tree->data);
    t_in_foreach_1(tree->right);
    return SUCCESS;
}

// 中序遍历(非递归)
int t_in_foreach_2(BITREE* tree) {
    STACK* stack = s_init();
    BNODE* node = tree;
    while (node != NULL || stack->length != 0) {
        while (node != NULL) {
            BSNODE* sNode = (BSNODE*)malloc(sizeof(BSNODE));
            sNode->data = node;
            s_push(stack, sNode);
            node = node->left;
        }
        if (stack->length != 0) {
            BSNODE* sNode = stack->top;
            s_pop(stack);
            node = sNode->data;
            printf("%d\n", node->data);
            node = node->right;
        }
    }
    return SUCCESS;
}


// 后序遍历
int t_post_foreach_1(BITREE* tree) {
    if (tree == NULL) return ERROR;
    t_post_foreach_1(tree->left);
    t_post_foreach_1(tree->right);
    printf("%d\n", tree->data);
    return SUCCESS;
}

// 后序遍历(非递归)
/*
 对于任一结点P，将其入栈，然后沿其左子树一直往下搜索，直到搜索到没有左孩子的结点，此时该结点出现在栈顶，但是此时不能将其出栈并访问，因此其右孩子还未被访问。所以接下来按照相同的规则对其右子树进行相同的处理，当访问完其右孩子时，该结点又出现在栈顶，此时可以将其出栈并访问。这样就保证了正确的访问顺序。可以看出，在这个过程中，每个结点都两次出现在栈顶，只有在第二次出现在栈顶时，才能访问它。因此需要多设置一个变量标识该结点是否是第一次出现在栈顶。
 */
int t_post_foreach_2(BITREE* tree) {
    STACK* stack = s_init();
    BNODE* node = tree;
    BSNODE* temp;
    while(node != NULL || stack->length != 0){
        while(node != NULL) {
            BSNODE* sNode = (BSNODE*)malloc(sizeof(BSNODE));
            sNode->data = node;
            sNode->is_first = 1;
            s_push(stack, sNode);
            node = node->left;
        }
        if(stack->length != 0) {
            temp = stack->top;
            s_pop(stack);
            
            if(temp->is_first == 1) {
                temp->is_first = 0;
                s_push(stack, temp);
                node = temp->data->right;
            } else {
                printf("%d\n", temp->data->data);
                node = NULL;
            }
        }
    }
    return SUCCESS;
}

// 后序遍历(非递归)
/*
要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
 */
int t_post_foreach_3(BITREE* tree) {
    STACK* stack = s_init();
    BNODE *cur; // 当前结点
    BNODE *pre = NULL;// 前一次访问的结点
    BSNODE* sNode = (BSNODE*)malloc(sizeof(BSNODE));
    sNode->data = tree;
    s_push(stack, sNode);
    while(stack->length != 0) {
        cur = stack->top->data;
        if((cur->left == NULL && cur->right == NULL)||
           (pre != NULL && (pre == cur->left || pre == cur->right))) {
            printf("%d\n", cur->data);
            s_pop(stack);
            pre = cur;
        } else {
            if(cur->right != NULL) {
                BSNODE* sNode = (BSNODE*)malloc(sizeof(BSNODE));
                sNode->data = cur->right;
                s_push(stack, sNode);
            }
            if(cur->left != NULL) {
                BSNODE* sNode = (BSNODE*)malloc(sizeof(BSNODE));
                sNode->data = cur->left;
                s_push(stack, sNode);
            }
        }
    }
    return SUCCESS;
}

// 清空树
int t_clear(BITREE* tree) {
    if (tree == NULL) return ERROR;
    t_clear(tree->left);
    t_clear(tree->right);
    free(tree);
    tree = NULL;
    return SUCCESS;
}

#endif /* defined(__DataStructure__BiTree__) */
