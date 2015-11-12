#include <stdio.h>
#include <stdlib.h>


/*
 * We will compute it on single array instead of 2D array containing
 * whole Pascal's triangle. We start computing our line from right, so
 * we won't overwrite old values when moving. It's described in more detail
 * here: http://stackoverflow.com/questions/28799209/design-the-binomial-coefficient-algorithm-using-a-single-dimensional-array
 *
 * BINOM(y, x):
 *   A <- [0..x + 1]
 *   A[0] <- 1
 *   for i <- 1 to y + 1 do:
 *     for j <- x downto 0 do:
 *       A[j] <- A[j] + A[j - 1]
 *   return A[x]
 */

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
