#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

void multiplyComplex(Complex *c1, Complex *c2, Complex *result) {
    result->real = (c1->real * c2->real) - (c1->imag * c2->imag);
    result->imag = (c1->real * c2->imag) + (c1->imag * c2->real);
}

int main() {
    Complex c1, c2, result;
    int choice;

    do {
        printf("\n---- Complex Number Operations ----\n");
        printf("1. Addition (Call by Value)\n");
        printf("2. Multiplication (Call by Address)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter first complex number (real and imaginary): ");
                scanf("%f %f", &c1.real, &c1.imag);
                printf("Enter second complex number (real and imaginary): ");
                scanf("%f %f", &c2.real, &c2.imag);
                result = addComplex(c1, c2);
                printf("Sum = %.2f + %.2fi\n", result.real, result.imag);
                break;

            case 2:
                printf("Enter first complex number (real and imaginary): ");
                scanf("%f %f", &c1.real, &c1.imag);
                printf("Enter second complex number (real and imaginary): ");
                scanf("%f %f", &c2.real, &c2.imag);
                multiplyComplex(&c1, &c2, &result);
                printf("Product = %.2f + %.2fi\n", result.real, result.imag);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
