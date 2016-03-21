
#include "st_queue.h"
#include <string.h>
#include <stdio.h>

#define MESSAGE_NUM     (10)

static Queue g_test_queue;

static Message messages[MESSAGE_NUM];

static void queue_dump(Queue *q) {
    int i = 0;

    for (i = 0; i < q->size; i++) {
        printf("message=%ld\r\n", q->queue[q->head+i]);
    }
}

int main(int argc, char *argv[]) {
    Message msg = 0;
    int16_t ret = 0;

    init_queue(&g_test_queue, messages, MESSAGE_NUM);
    msg = 1;
    en_queue(&g_test_queue, msg);
    msg = 2;
    en_queue(&g_test_queue, msg);
    queue_dump(&g_test_queue);
    ret = de_queue(&g_test_queue, &msg);
    printf("dequeue ret=%d, message=%ld\r\n", ret, msg);
    queue_dump(&g_test_queue);
    ret = de_queue(&g_test_queue, &msg);
    printf("dequeue ret=%d, message=%ld\r\n", ret, msg);
    queue_dump(&g_test_queue);
    ret = de_queue(&g_test_queue, &msg);
    printf("dequeue ret=%d, message=%ld\r\n", ret, msg);
    queue_dump(&g_test_queue);

    return 0;
}

