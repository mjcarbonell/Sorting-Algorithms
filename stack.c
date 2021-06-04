#include "stack.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
struct Stack {
    uint32_t top; // INDEX OF THE NEXT EMPTY SLOT
    uint32_t capacity; // NUMBER OF ITEMS THAT CAN BE PUSHED
    int64_t *items; // ARRAY OF ITEMS, EACH WITH TYPE int64_t
};

Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s) {
        s->top = 0;
        s->capacity = capacity;
        s->items = (int64_t *) calloc(capacity, sizeof(int64_t));
        if (!s->items) {
            free(s);
            s = NULL;
        }
    }
    return s;
}

void stack_delete(Stack **s) {
    if (*s && (*s)->items) {
        free((*s)->items);
        free(*s);
        *s = NULL;
    }
    return;
}

bool stack_empty(Stack *s) {
    if (s->top == 0) {
        return true;
    }
    return false;
}

uint32_t stack_size(Stack *s) {
    return (s->top);
}

bool stack_push(Stack *s, int64_t x) { // We cannot push if stack is full. place itme in array and icnrement top 
    if (s->top == (s->capacity)) {
        return false;
    }
    s->items[s->top] = x;
    s->top += 1;
    return true;
}

bool stack_pop(Stack *s, int64_t *x) { // We cant pop if stack is empty. Decrement top and place item in specified location 
    if (s->top == 0) {
        return false;
    }
    s->top -= 1;
    *x = s->items[s->top];
    return true;
}

void stack_print(Stack *s) {
    if (s->top == 0) {
        printf("Stack is NULL\n");
        return;
    }
    for (uint64_t i = 0; i < (s->capacity); ++i) {
        if (i == 0) {
            printf("START\n");
        }
        printf("%ld\n", (s->items[i]));
    }
    printf("END\n");
    return;
}

/*int main(void){
	Stack *s = stack_create();
	stack_delete(&s);
	assert(s == NULL);
} */
