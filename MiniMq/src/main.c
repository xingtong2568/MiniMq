#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "message.h"
#include "queue.h"

int main() {
    /* 创建队列 */
    Queue *queue = queue_create();
    if (queue == NULL) {
        fprintf(stderr, "Failed to create queue\n");
        return EXIT_FAILURE;
    }

    /* 创建消息 */
    Message *message1 = message_create();
    if (message1 == NULL) {
        fprintf(stderr, "Failed to create message1\n");
        queue_destroy(queue);
        return EXIT_FAILURE;
    }
    const char *data1 = "Hello, MiniMq!";
    message_set_data(message1, data1, strlen(data1));

    Message *message2 = message_create();
    if (message2 == NULL) {
        fprintf(stderr, "Failed to create message2\n");
        message_destroy(message1);
        queue_destroy(queue);
        return EXIT_FAILURE;
    }
    const char *data2 = "This is a test message.";
    message_set_data(message2, data2, strlen(data2));

    /* 入队 */
    queue_enqueue(queue, message1);
    queue_enqueue(queue, message2);

    /* 出队并打印消息内容 */
    Message *dequeued_message;
    while ((dequeued_message = queue_dequeue(queue)) != NULL) {
        printf("Dequeued Message ID: %lu, Data: %.*s\n", dequeued_message->id, (int)dequeued_message->length, dequeued_message->data);
        message_destroy(dequeued_message);
    }

    /* 销毁队列 */
    queue_destroy(queue);

    return EXIT_SUCCESS;
}