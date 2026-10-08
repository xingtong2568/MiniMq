#ifndef MINIMQ_QUEUE_H
#define MINIMQ_QUEUE_H
#include "message.h"
/* 队列结构体 */
typedef struct Node {
    Message *message;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;

/* 创建队列 */
Queue *queue_create();
/* 销毁队列 */
int queue_destroy(Queue *queue);
/* 入队 */
int queue_enqueue(Queue *queue, Message *message);
/* 出队 */
Message *queue_dequeue(Queue *queue);

#endif /* MINIMQ_QUEUE_H*/