#include <stdio.h>

#include "auxiliary.h"

void bubble_sort(int *A, int len) {
    for (int i = 0; i < len - 2; i++) {
        for (int j = len - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
            }
        }
    }
}

int main(int argc, char **argv) {
    int array[] = { 23, 54 ,6, 12, 76, 3, 5, 8 };
    bubble_sort(array, 8);
    printIntArray(array, 8);
    return 0;
}
