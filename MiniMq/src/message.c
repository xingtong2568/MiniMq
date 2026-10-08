#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "message.h"

static unsigned long id = 0;  /* 消息ID计数器 */


/* 创建消息 */
Message *message_create(){
    Message *message = (Message *)malloc(sizeof(Message));
    if (message == NULL) {
        return NULL;
    }
    message->id = message_generate_id();  /* 初始化消息ID为0，实际ID应由系统生成 */
    message->data = NULL;
    message->length = 0;
    return message;
}
/* 销毁消息 */
int message_destroy(Message *message){
    if (message == NULL) {
        return MINIMQ_INVALID_PARAM;
    }
    free(message->data);
    free(message);
    return MINIMQ_SUCCESS;
}

/* 设置消息内容 */
int message_set_data(Message *message, const char *data, size_t length){
    char *new_data = malloc(length);

    if (new_data == NULL) {
        return MINIMQ_NO_MEMORY;
    }

    memcpy(new_data, data, length);

    free(message->data);

    message->data = new_data;
    message->length = length;

    return MINIMQ_SUCCESS;
}


unsigned long message_generate_id() {
    return ++id;  /* 生成唯一的消息ID */
}