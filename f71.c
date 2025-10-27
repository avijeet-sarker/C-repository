#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void insertFront(int x) {
    if (isFull()) {
        printf("Deque is Full!\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;
    deque[front] = x;
}

void insertRear(int x) {
    if (isFull()) {
        printf("Deque is Full!\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;
    deque[rear] = x;
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deleted element: %d\n", deque[front]);
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deleted element: %d\n", deque[rear]);
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void display() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", deque[rear]);
}

void peek() {
    if (isEmpty())
        printf("Deque is Empty!\n");
    else
        printf("Front element: %d\n", deque[front]);
}

int main() {
    int choice, val, type;

    printf("Select Deque Type:\n");
    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    printf("Enter choice: ");
    scanf("%d", &type);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Rear\n");
        if (type == 2) printf("2. Insert at Front\n");
        printf("3. Delete from Front\n");
        if (type == 1) printf("4. Delete from Rear\n");
        printf("5. Peek\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 2:
                if (type == 2) {
                    printf("Enter value: ");
                    scanf("%d", &val);
                    insertFront(val);
                } else
                    printf("Invalid for Input-Restricted Deque.\n");
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                if (type == 1)
                    deleteRear();
                else
                    printf("Invalid for Output-Restricted Deque.\n");
                break;
            case 5:
                peek();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
