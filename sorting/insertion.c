#include <stdio.h>

#include "auxiliary.h"

void insertion_sort(int *A, int len) {
    for (int j = 1; j < len; j++) {
        int r = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > r) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = r;
    }
}

int main(int argc, char **argv) {
    int array[] = { 23, 54 ,6, 12, 76, 3, 5, 8 };
    insertion_sort(array, 8);
    printIntArray(array, 8);
    return 0;
}
