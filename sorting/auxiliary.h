#ifndef AUXILIARY_H_INCLUDED
#define AUXILIARY_H_INCLUDED

#include <stdio.h>

void printIntArray(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#endif
