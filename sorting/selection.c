#include <stdio.h>

#include "auxiliary.h"


void selection_sort(int *array, int len) {
    for (int i = 0; i < len - 1; i++) {
        int k = i;
        for (int j = i + 1; j < len; j++) {
            if (array[j] < array[k]) {
                k = j;
            }
        }
        int tmp = array[i];
        array[i] = array[k];
        array[k] = tmp;
    }
}

int main(int argc, char **argv) {
    int array[] = { 23, 54 ,6, 12, 76, 3, 5, 8 };
    selection_sort(array, 8);
    printIntArray(array, 8);
    return 0;
}
