#include <stdio.h>
#include <stdlib.h>

#include "auxiliary.h"

void merge(int *A, int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int l = start;
    int *B = calloc(end + 1, sizeof(int));
    while (i <= middle && j <= end) {
        if (A[i] < A[j]) {
            B[l] = A[i];
            i++;
            l++;
        } else {
            B[l] = A[j];
            j++;
            l++;
        }
    }
    while (i <= middle) {
        B[l] = A[i];
        i++;
        l++;
    }
    while (j <= end) {
        B[l] = A[j];
        j++;
        l++;
    }
    for (int i = start; i <= end; i++) {
        A[i] = B[i];
    }
    free(B);
}

void merge_sort(int *A, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        merge_sort(A, start, middle);
        merge_sort(A, middle + 1, end);
        merge(A, start, (start + end) / 2, end);
    }
}

int main(int argc, char **argv) {
    int array[] = { 4, 5, 2, 6, 34, 897, 2 };
    merge_sort(array, 0, 6);
    printIntArray(array, 7);
    return 0;
}
