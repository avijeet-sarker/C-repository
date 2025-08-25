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