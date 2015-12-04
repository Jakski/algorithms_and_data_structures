#include <stdio.h>
#include <stdlib.h>

typedef struct queue_s Queue;
struct queue_s {
    int head;
    int tail;
    int length;
    int *elements;
};

int queue_empty(Queue queue) {
    if (queue.head == queue.tail) {
        return 1;
    } else {
        return 0;
    }
}

int dequeue(Queue *queue) {
    if (queue->head == queue->tail) {
        fputs("Queue is empty! Returning -1.\n", stderr);
        return -1;
    } else {
        int x = queue->elements[queue->head];
        if (queue->head == queue->length) {
            queue->head = 0;
        } else {
            queue->head++;
        }
        return x;
    }
}

void enqueue(Queue *queue, int x) {
    if (queue->tail == queue->length) {
        if (queue->head == 0) {
            fputs("Queue overflow!\n", stderr);
        } else {
            queue->elements[queue->tail] = x;
            queue->tail = 0;
        }
    } else if (queue->head == queue->tail + 1) {
        fputs("Queue overflow!\n", stderr);
    } else {
        queue->elements[queue->tail] = x;
        queue->tail++;
    }
}

int main( int argc, char **argv ) {
    char command[2];
    int length;
    scanf("%d", &length);
    Queue queue = {
        .head = 0,
        .tail = 0,
        .length = length - 1,
        .elements = (int*)malloc(length * sizeof(int))
    };
    int finish = 0;
    while (finish == 0) {
        scanf("%s", command);
        int x;
        switch (command[0]) {
            case 'e': // euqueue command
                scanf("%d", &x);
                enqueue(&queue, x);
                break;
            case 'd': // dequeue command
                printf("%d\n", dequeue(&queue));
                break;
            case 'q': // queue_empty command
                if (queue_empty(queue) == 1)
                    puts("Queue is empty.");
                else
                    puts("Queue is not empty.");
                break;
            case 'f': // finish
                finish = 1;
                break;
            default:
                fputs("Wrong command\n", stderr);
        }
    }
    free(queue.elements);
    return 0;
}
