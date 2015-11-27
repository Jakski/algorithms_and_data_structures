#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack_s Stack;
struct stack_s {
    int top;
    int max;
    int *body;
};

void push(Stack *stack, int value) {
    stack->top++;
    if (stack->top > stack->max) {
        puts("Stack overflow!");
        stack->top--;
    } else {
        stack->body[stack->top] = value;
    }
}

int stack_empty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

int pop(Stack *stack) {
    if (stack_empty(stack)) {
        puts("Stack is empty!");
        return -1;
    } else {
        stack->top--;
        return stack->body[stack->top + 1];
    }
}

/*
 * First input is stack maximum size. You can 'push' or 'pop' element.
 * You will get error message and -1 output when you 'pop' on empty stack.
 * 'end' stops program and frees allocated memory.
 */

int main( int argc, char **argv ) {
    int length;
    scanf("%d", &length);
    Stack stack = {
        .top = -1,
        .max = length - 1,
        .body = (int*)malloc(length * sizeof(int))
    };
    char *command = (char*)malloc(6 * sizeof(char));
    for (;;) {
        int argument;
        scanf("%s", command);
        if (strncmp(command, "pop", 3) == 0) {
            printf("Popped value: %d\n", pop(&stack));
        } else if (strncmp(command, "push", 4) == 0) {
            scanf("%d", &argument);
            push(&stack, argument);
        } else if (strncmp(command, "end", 3) == 0) {
            puts("Exit!");
            break;
        } else {
            puts("Wrong command!");
        }
    }
    free(stack.body);
    free(command);
    return 0;
}
