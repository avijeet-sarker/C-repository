#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Function to insert element in queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is Full! Cannot enqueue %d\n", data);
        return;
    }
    if (front == -1)  // first element
        front = 0;
    rear++;
    queue[rear] = data;
    printf("%d enqueued to queue\n", data);
}

// Function to delete element from queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    front++;
    if (front > rear) { // Reset queue
        front = rear = -1;
    }
}

// Function to traverse (display) queue
void traverse() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is Empty\n");
                else
                    printf("Queue is not Empty\n");
                break;
            case 5:
                if (isFull())
                    printf("Queue is Full\n");
                else
                    printf("Queue is not Full\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

