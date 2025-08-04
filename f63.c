#include <stdio.h>

#define MAX 100

void readPolynomial(int poly[], int degree) {
    printf("Enter coefficients from highest degree to constant term:\n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", degree - i);
        scanf("%d", &poly[i]);
    }
}

void displayPolynomial(int poly[], int degree) {
    for (int i = 0; i <= degree; i++) {
        if (poly[i] != 0) {
            if (i != 0 && poly[i] > 0)
                printf(" + ");
            else if (poly[i] < 0)
                printf(" - ");

            int coeff = poly[i] < 0 ? -poly[i] : poly[i];
            if (degree - i > 1)
                printf("%dx^%d", coeff, degree - i);
            else if (degree - i == 1)
                printf("%dx", coeff);
            else
                printf("%d", coeff);
        }
    }
    printf("\n");
}

int max(int a, int b) {
    return a > b ? a : b;
}

void addPolynomials(int poly1[], int deg1, int poly2[], int deg2, int result[]) {
    int maxDeg = max(deg1, deg2);
    int i;

    for (i = 0; i <= maxDeg; i++) {
        int coeff1 = (i <= deg1) ? poly1[deg1 - i] : 0;
        int coeff2 = (i <= deg2) ? poly2[deg2 - i] : 0;
        result[maxDeg - i] = coeff1 + coeff2;
    }
}

int main() {
    int deg1, deg2, poly1[MAX], poly2[MAX], result[MAX];

    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    readPolynomial(poly1, deg1);

    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &deg2);
    readPolynomial(poly2, deg2);

    int maxDeg = max(deg1, deg2);
    addPolynomials(poly1, deg1, poly2, deg2, result);

    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1, deg1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, deg2);

    printf("Sum Polynomial: ");
    displayPolynomial(result, maxDeg);

    return 0;
}
