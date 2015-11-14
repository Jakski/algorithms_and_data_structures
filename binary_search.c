#include <stdio.h>


int binary_search(int *array, int element, int length){
    int i = length / 2;
    int left = 0;
    int right = length - 1;
    while (array[i] != element && left < right) {
        if (array[i] < element) {
            left = i + 1;
        } else {
            right = i - 1;
        }
        i = (left + right) / 2;
    }
    if (array[i] == element) {
        return i;
    } else {
        return -1;
    }
}

int main(int argc, char **argv) {
    int number;
    scanf("%d", &number);
    int array[] = { 1, 2, 3, 5, 7, 20, 34, 56 };
    printf("%d\n", binary_search(array, number, 8));
    return 0;
}
