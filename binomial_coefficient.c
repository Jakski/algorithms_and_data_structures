#include <stdio.h>
#include <stdlib.h>


int binom(int y, int x) {
    // dynamically allocating array
    int *array = calloc(x + 1, sizeof(int));
    array[0] = 1;
    for (int i = 1; i <= y; i++) {
        for (int j = x; j > 0; j--) {
            array[j] = array[j] + array[j - 1];
        }
    }
    // we save result, because it would vanish after free(...)
    int result = array[x];
    free(array);
    return result;
}

int main(int argc, char **argv) {
    int y, x;
    scanf("%d %d", &y, &x);
    printf("%d\n", binom(y, x));
    return 0;
}
