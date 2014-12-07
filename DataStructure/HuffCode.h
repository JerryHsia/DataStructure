//
//  Huff.h
//  DataStructure
//
//  Created by Jerry Hsia on 11/16/14.
//  Copyright (c) 2014 Jerry Hsia. All rights reserved.
//

#ifndef __DataStructure__Huff__
#define __DataStructure__Huff__
#define MAX_WEIGHT 100000

typedef struct HuffCodeNode {
    char data;
    int weight;
    int parent;
    int left;
    int right;
} HNODE;

HNODE tree[255];
int total = 0;

void visit(HNODE node, char s[10]) {
    if (node.data != '0') {
        printf("%c: %s\n", node.data, s);
    }
    if (node.left != -1) {
        char s1[10];
        strcpy(s1, s);
        strcat(s1, "0");
        visit(tree[node.left], s1);
    }
    if (node.right != -1) {
        char s1[10];
        strcpy(s1, s);
        strcat(s1, "1");
        visit(tree[node.right], s1);
    }
}

// 打印编码
void print_code () {
    printf("==打印编码\n");
    HNODE root;
    for (int i = 0; i < total; i++) {
        if (tree[i].parent == -1) {
            root = tree[i];
            break;
        }
    }
    char s[10] = "";
    visit(root, s);
}

// 打印节点数组
void print_nodes() {
    printf("==打印节点数组\n");
    for (int i = 0; i < total; i++) {
        printf("index: %d, data: %c, weight: %d, parent: %d, left: %d, right:%d\n", i, tree[i].data, tree[i].weight, tree[i].parent, tree[i].left, tree[i].right);
    }
}

// 创建节点数组
void create_nodes(char* string) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        int index = -1;
        for (int j = 0; j < total; j++) {
            if (tree[j].data == string[i]) {
                index = j;
                break;
            }
        }
        if (index == -1) {
            HNODE node = {string[i], 1, -1, -1, -1};
            tree[total] = node;
            total++;
        } else {
            tree[index].weight++;// 如果已经存在权重加1
        }
    }
}

// 创建哈夫曼树
void create_tree(char* string) {
    
    create_nodes(string);
    
    int old_total = total;
    for (int i = 0; i < old_total; i++) {
        int w1 = MAX_WEIGHT, w2 = MAX_WEIGHT;
        int x1 = 0, x2 = 0;
        // 寻找最小的两个权重构建新的节点
        for (int j = 0; j < total; j++) {
            if (tree[j].weight < w1 && tree[j].parent == -1) {
                w1 = tree[j].weight;
                x1 = j;
                continue;
            }
            if (tree[j].weight >= w1 && tree[j].weight <= w2 && tree[j].parent == -1) {
                w2 = tree[j].weight;
                x2 = j;
            }
        }
        if (w1 == MAX_WEIGHT || w2 == MAX_WEIGHT) break; // 构建完毕
        tree[x1].parent = total;
        tree[x2].parent = total;
        HNODE node = {'0', (tree[x1].weight + tree[x2].weight), -1, x1, x2};
        tree[total] = node;
        total++;
    }
    print_nodes();
    print_code();
}

#endif /* defined(__DataStructure__Huff__) */
