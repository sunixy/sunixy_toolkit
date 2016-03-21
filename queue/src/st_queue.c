/*
 * File:   queue.c
 * Author: sunixy
 *
 * Created on December 30, 2015, 3:43 PM
 */
#include "st_queue.h"

 
int16_t init_queue(Queue *q, Message *address, uint16_t size) {  
    if ((NULL == address) || (0 == size)) {
        return -1;
    }
    q->queue = address;  
    q->size = size;
    q->head = q->tail = 0;  
  
    return 0;  
}  
  
int16_t en_queue(Queue *q, Message m) {  
    if((q->tail+1) % q->size == q->head) {  
        return -1;  
    } 
    q->queue[q->tail] = m;
    q->tail = (q->tail + 1) % q->size;

    return 0;
}  
  
int16_t de_queue(Queue *q, Message *m) {  
    if(q->head == q->tail)  
    {  
        return -1;  
    }  
  
    (*m) = q->queue[q->head];  
    q->head = (q->head + 1) % q->size;  
  
    return 0;  
}  

