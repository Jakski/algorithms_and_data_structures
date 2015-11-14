#include <stdio.h>


int horner(int *array, int length, int x) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum = (sum * x) + array[i];
    }
    return sum;
}

int main(int argc, char **argv) {
    int x;
    scanf("%d", &x);
    int array[] = { 2, 3, 4 };
    printf("%d\n", horner(array, 3, x));
    return 0;
}
