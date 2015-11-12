#ifndef AUXILIARY_H_INCLUDED
#define AUXILIARY_H_INCLUDED

#include <stdio.h>

/*
 * It's auxiliary module with utilities. It's useful
 * while checking correct of sort algorithms.
 */

void printIntArray(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#endif
