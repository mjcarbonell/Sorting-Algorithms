#include "quick.h"

#include "queue.h"
#include "sorting.h"
#include "stack.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

extern uint32_t max_stack_size;
extern uint32_t max_queue_size;
uint64_t moves = 0;
uint64_t compares = 0;
int64_t partition(uint32_t *A, uint32_t lo, uint32_t hi) { // This logic was borrowed from the homework pdf...
    int64_t lo_2 = lo;
    int64_t hi_2 = hi;
    //printf("HIGH %u and LOW %u\n", hi, lo);
    double fraction_pro = ((hi - lo) / 2);
    int64_t fraction = fraction_pro;
    int64_t pivot = A[(lo + fraction)];
    //printf("AFTER PIVOT\n");
    //printf("PIVOT %ld\n", pivot);
    int64_t i = (lo_2 - 1);
    int64_t j = (hi_2 + 1);
    //printf("I VALUE %ld AND J VALUE %ld\n", i, j);
    while (i < j) {
        i += 1;
        while (*(A + i) < pivot) {
            i += 1;
            compares += 1;
        }
        j -= 1;
        while (*(A + j) > pivot) {
            j -= 1;
            compares += 1;
        }
        if (i < j) {
            int64_t temp_first = *(A + i);
            int64_t temp_second = *(A + j);
            *(A + i) = temp_second;
            *(A + j) = temp_first;
            moves += 3;
        }
    }
    //printf("FIRST ELEMENT %d\n", A[0]);
    //printf("RESULT %ld\n", j);
    return j;
}

void quick_sort_stack(uint32_t *A, uint32_t n) {
    int64_t x;
    uint32_t lo = 0;
    uint32_t hi = (n - 1);
    uint32_t maxStack = 0;
    uint32_t ultMax = 0; 
    moves = 0;
    compares = 0;
    Stack *stack = stack_create((2 * n));
    stack_push(stack, lo);
    stack_push(stack, hi);
    maxStack += 2;
    uint32_t stackSize = stack_size(stack);
    //printf("STACK TOP%d\n", stackSize);
    while ((stackSize - 1) != 0) {
        stack_pop(stack, &x);
        hi = x;
        stack_pop(stack, &x); // Use ampersan for computer defined types. AKA x.
        lo = x;
        if (ultMax < maxStack){
        	ultMax = maxStack;
        }
        maxStack -= 2; // DECREMENT MAX QUEUE SIZE 
        int64_t p = partition(A, lo, hi);
        if (lo < p) {
            compares += 1;
            stack_push(stack, lo);
            stack_push(stack, p);
            maxStack += 2;
        }
        if (hi > (p + 1)) {
            compares += 1;
            stack_push(stack, (p + 1));
            stack_push(stack, hi);
            maxStack += 2;
        }
        //printf("HI %u LO %u P %ld\n", hi, lo, p);
        if (stack_empty(stack) == true) {
            //printf("MADE IT TO EMPTY\n");
            break;
        }
        //stack_print(stack);
    }
    if (ultMax < maxStack){
    	ultMax = maxStack;
    }
    printf("%d elements, %lu moves, %lu compares\n", n, moves, compares);
    printf("Max stack size: %d\n", ultMax);
    if (printSize > n) {
        for (uint32_t i = 0; i < n; i += 1) {
            if (i % 5 == 0 && i != 0){
            	printf("\n%d	", A[i]);
            }
            else{
            	printf("%d	", A[i]);
            }
        }
        printf("\n");
    } else {
        for (uint32_t i = 0; i < printSize; i += 1) {
            if (i % 5 == 0 && i != 0){
            	printf("\n%d	", A[i]);
            }
            else{
            	printf("%d	", A[i]);
            }
        }
        printf("\n");
    }
    stack_delete(&stack);
    return;
}

void quick_sort_queue(uint32_t *A, uint32_t n) {
    int64_t x;
    uint32_t lo = 0;
    uint32_t hi = (n - 1);
    uint32_t maxQueue = 0;
    uint32_t ultMax = 0;
    moves = 0;
    compares = 0;
    Queue *queue = queue_create((2 * n));
    enqueue(queue, lo);
    enqueue(queue, hi);
    maxQueue += 2; // INCREMENT MAX QUEUE SIZE 
    uint32_t queueSize = queue_size(queue);
    while ((queueSize - 1) != 0) {
        dequeue(queue, &x);
        lo = x;
        dequeue(queue, &x);
        hi = x;
        if (ultMax < maxQueue){
        	ultMax = maxQueue;
        }
        maxQueue -= 2; // DECREMENT MAX QUEUE SIZE 
        int64_t p = partition(A, lo, hi);
        if (lo < p) {
            compares += 1;
            enqueue(queue, lo);
            enqueue(queue, p);
            maxQueue += 2; // INCREMENT MAX QUEUE SIZE 
        }
        if (hi > (p + 1)) {
            compares += 1;
            enqueue(queue, (p + 1));
            enqueue(queue, hi);
            maxQueue += 2; // INCREMENT MAX QUEUE SIZE 
        }
        if (queue_empty(queue) == true) {
            break;
        }
    }
    printf("%d elements, %lu moves, %lu compares\n", n, moves, compares);
    printf("Max queue size: %d\n", ultMax);
    if (printSize > n) {
        for (uint32_t i = 0; i < n; i += 1) {
            if (i % 5 == 0 && i != 0){
            	printf("\n%d	", A[i]);
            }
            else{
            	printf("%d	", A[i]);
            }
        }
        printf("\n");
    } else {
        for (uint32_t i = 0; i < printSize; i += 1) {
            if (i % 5 == 0 && i != 0){
            	printf("\n%d	", A[i]);
            }
            else{
            	printf("%d	", A[i]);
            }
        }
        printf("\n");
    }
    queue_delete(&queue);
    return;
}
