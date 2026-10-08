#ifndef MINIMQ_COMMON_H
#define MINIMQ_COMMON_H

/* 通用返回码
 * 这些值用于表示函数执行结果，返回 0 表示成功，负数表示失败。
 */
#define MINIMQ_SUCCESS          0       /* 操作成功 */
#define MINIMQ_ERROR            -1      /* 通用错误，未分类的失败情况 */
#define MINIMQ_INVALID_PARAM    -2      /* 参数非法、缺失、越界或不符合约束 */
#define MINIMQ_NO_MEMORY        -3      /* 内存分配失败 */
#define MINIMQ_NOT_FOUND        -4      /* 目标资源、对象或消息不存在 */
#define MINIMQ_ALREADY_EXISTS   -5      /* 目标已存在，重复创建或重复注册 */

/* 队列相关错误
 * 适用于消息队列的入队/出队/消费等操作。
 */
#define MINIMQ_QUEUE_FULL       -10     /* 队列已满，无法继续写入 */
#define MINIMQ_QUEUE_EMPTY      -11     /* 队列为空，无法继续读取或消费 */

/* 网络相关错误
 * 适用于 Socket、TCP/UDP、RPC 或消息传输场景。
 */
#define MINIMQ_NETWORK_ERROR    -20     /* 网络层错误，例如连接失败、协议异常等 */
#define MINIMQ_SEND_FAILED      -21     /* 数据发送失败 */
#define MINIMQ_RECV_FAILED      -22     /* 数据接收失败 */

/* Message 相关错误
 * 适用于消息构造、校验、序列化、反序列化和处理流程。
 */
/* Message 相关错误
 * 适用于消息构造、校验、序列化、反序列化和处理流程。
 */
#define MINIMQ_MESSAGE_INVALID             -30     /* 消息格式非法、字段缺失或不合法 */
#define MINIMQ_MESSAGE_EMPTY               -31     /* 消息内容为空 */
#define MINIMQ_MESSAGE_PARSE_FAILED        -32     /* 消息解析失败 */
#define MINIMQ_MESSAGE_SERIALIZE_FAILED    -33     /* 消息序列化失败 */
#define MINIMQ_MESSAGE_TIMEOUT             -34     /* 消息处理超时 */
#define MINIMQ_MESSAGE_CREATE_FAILED       -35     /* Message 创建失败 */
#define MINIMQ_MESSAGE_DESTROY_FAILED      -36     /* Message 销毁失败 */

#endif /* MINIMQ_COMMON_H */