#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;      
    int power;      
    struct Node *next;
};


struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}


void insertTerm(struct Node** poly, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->power);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            insertTerm(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            insertTerm(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    insertTerm(&poly1, 3, 3);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 1, 1);
    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 5, 1);
    insertTerm(&poly2, 6, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Result (Addition): ");
    display(result);

    return 0;
}

        

   