#include "queue.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
struct Queue {
    uint32_t head;
    uint32_t tail;
    uint32_t size;
    uint32_t capacity;
    int64_t *items;
};

Queue *queue_create(uint32_t capacity) {
    Queue *q = (Queue *) malloc(capacity * sizeof(Queue));
    if (q) {
        q->head = 0;
        q->tail = 0;
        q->size = 0;
        q->capacity = capacity;
        q->items = (int64_t *) calloc(capacity, sizeof(int64_t));
        if (!q->items) {
            free(q);
            q = NULL;
        }
    }
    return q;
}

void queue_delete(Queue **q) { // Freeing items and setting the queue to NULL to prevent memory leaks 
    if (*q && (*q)->items) {
        free((*q)->items);
        free(*q);
        *q = NULL;
    }
    return;
}

bool queue_empty(Queue *q) {
    if (q->size == 0) {
        return true;
    }
    return false;
}

bool queue_full(Queue *q) {
    if (q->size == q->capacity) {
        return true;
    }
    return false;
}

uint32_t queue_size(Queue *q) {
    return (q->size);
}

bool enqueue(Queue *q, int64_t x) {
    if ((q->size) == (q->capacity)) { //Increment tail and increment size. Place item in array 
        return false;
    }
    q->size += 1;
    q->items[q->tail] = x;
    q->tail = ((q->tail + 1) % (q->capacity));
    return true;
}

bool dequeue(Queue *q, int64_t *x) { // Decrement size and increase the head. Place item in array to specified location
    if (q->size == 0) {
        return false;
    }
    q->size -= 1;
    *x = (q->items[q->head]);
    q->head = ((q->head + 1) % q->capacity);
    return true;
}

void queue_print(Queue *q) {
    for (uint64_t i = 0; i < (q->capacity); ++i) {
        printf("%ld\n", (q->items[i]));
    }
}
