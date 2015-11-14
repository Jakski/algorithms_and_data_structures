#include <stdio.h>


int gcd(int number1, int number2) {
    while (number2 > 0) {
        int tmp = number2;
        number2 = number1 % number2;
        number1 = tmp;
    }
    return number1;
}

int main(int argc, char **argv) {
    int number1, number2;
    scanf("%d %d", &number1, &number2);
    printf("%d\n", gcd(number1, number2));
    return 0;
}
