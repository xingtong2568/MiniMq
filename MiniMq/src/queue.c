#include <stdlib.h>
#include "queue.h"
#include "common.h"

/* 创建队列 */
Queue *queue_create(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}
/* 销毁队列 */
int queue_destroy(Queue *queue){
    if (queue == NULL) {
        return MINIMQ_INVALID_PARAM;
    }
    while (queue->head != NULL) {
        Node *temp = queue->head;
        queue->head = queue->head->next;
        free(temp);
    }
    free(queue);
    return MINIMQ_SUCCESS;
}
/* 入队 */
int queue_enqueue(Queue *queue, Message *message){
    if (queue == NULL || message == NULL) {
        return MINIMQ_INVALID_PARAM;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return MINIMQ_NO_MEMORY;
    }
    new_node->message = message;
    new_node->next = NULL;

    if (queue->tail == NULL) {  // 队列为空
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    return MINIMQ_SUCCESS;
}
/* 出队 */
Message *queue_dequeue(Queue *queue){
    if (queue == NULL) {
        return NULL;
    }
    if (queue->head == NULL) {
        return NULL;
    }
    Node *temp = queue->head;
    Message *message = temp->message;
    queue->head = queue->head->next;
    free(temp);
    return message;
}