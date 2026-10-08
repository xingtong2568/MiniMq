#include <stddef.h>
#ifndef MINIMQ_MESSAGE_H
#define MINIMQ_MESSAGE_H

/* 消息结构体 */
typedef struct {
    unsigned long id;   /* 消息ID 系统自动生成 */
    char *data;
    size_t length;
} Message;

/* 创建消息 */
Message *message_create();
/* 生成消息ID */
unsigned long message_generate_id(void);

/* 销毁消息 */
int message_destroy(Message *message);

/* 设置消息内容 */
int message_set_data(Message *message, const char *data, size_t length);



#endif /* MINIMQ_MESSAGE_H */