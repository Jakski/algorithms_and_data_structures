#include <stdio.h>

/*
 * FIB(number):
 *   num1 <- 0
 *   num2 <- 1
 *   for i <- 0 to number do:
 *     tmp <- num1
 *     num1 <- num2
 *     num2 <- num1 + num2
 *   return num1
 */
int fib(int number) {
    if (number < 2) {
        return number;
    } else {
        int num1 = 0;
        int num2 = 1;
        for (int i = 0; i < number; i++) {
            int tmp = num1;
            num1 = num2;
            num2 = tmp + num2;
        }
        return num1;
    }
}

int main(int argc, char **argv) {
    int number;
    scanf("%d", &number);
    printf("%d\n", fib(number));
    return 0;
}
