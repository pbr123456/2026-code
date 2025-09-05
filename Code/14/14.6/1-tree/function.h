//
// Created by 86199 on 2025-02-14.
//

#ifndef INC_1_TREE_FUNCTION_H
#define INC_1_TREE_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode{
    BiElemType c;//c就是数据
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

//tag结构体是辅助队列使用的
typedef struct tag{
    BiTree p;//树的某一个结点
    struct tag *pnext;
}tag_t,*ptag_t;

//队列的结构体
typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;//链表头，链表尾
}LinkQueue;//先进先出

void InitQueue(LinkQueue &q);
bool IsEmpty(LinkQueue q);
void EnQueue(LinkQueue &q,ElemType x);
bool DeQueue(LinkQueue &q,ElemType &x);

#endif //INC_1_TREE_FUNCTION_H
