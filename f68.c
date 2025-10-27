#include <stdio.h>
#define MAX 5  

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack is FULL! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed into stack\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack is EMPTY! Cannot pop\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is EMPTY!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty())
                    printf("Stack is EMPTY\n");
                else
                    printf("Stack is NOT EMPTY\n");
                break;
            case 4:
                if (isFull())
                    printf("Stack is FULL\n");
                else
                    printf("Stack is NOT FULL\n");
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

