#include <stdio.h>

void compareNumbers(int *a, int *b) {
    if (*a > *b) {
        printf("%d is greater than %d\n", *a, *b);
    } else if (*a < *b) {
        printf("%d is greater than %d\n", *b, *a);
    } else {
        printf("Both numbers are equal.\n");
    }
}

int main() {
    int num1, num2;

    
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    compareNumbers(&num1, &num2);

    return 0;
}


