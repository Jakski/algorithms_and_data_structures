#include <stdio.h>

#include "auxiliary.h"

int division(int *A, int start, int end) {
    int middle = A[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (A[j] < middle) {
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[i + 1];
    A[i + 1] = A[end];
    A[end] = tmp;
    return i + 1;
}

void quick_sort(int *A, int start, int end) {
    if (start < end) {
        int middle = division(A, start, end);
        quick_sort(A, start, middle - 1);
        quick_sort(A, middle + 1, end);
    }
}

int main(int argc, char **argv) {
    int array[] = { 23, 54 ,6, 12, 76, 3, 5, 8 };
    quick_sort(array, 0, 7);
    printIntArray(array, 8);
    return 0;
}
